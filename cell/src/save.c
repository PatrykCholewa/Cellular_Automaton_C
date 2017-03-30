#include "save.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <png.h>

int scale(int m, int n) {
	if(m*n<=300) {
		return 5;
	}
	if(m*n<=14400) {
		return 3;
	}
	return 1;
}

int numOfDigits(int n) {
    int digits = 0;
    if(n == 0) {
        return 1;
    }
    while(n != 0) {
        n/=10;
        digits++;
    }
    return digits;
}

char* addNumToName(char *s) {
    static int number = 0;
    int i;
    int tmp = number;
    int digits = numOfDigits(number);
    char *ns = malloc((strlen(s)+digits+1)*sizeof (char));
    for(i=digits-1; i>=0; i--) {
        int d = tmp % 10;
        ns[i] = d+'0';
        tmp /= 10;
    }
    ns[digits] = '_';
    i = 0;
    while(s[i] != '\0') {
        ns[digits+i+1] = s[i];
        i++;
    }
    ns[digits+i+1] = '\0';
    number++;
    return ns;
}

void save_scalex1(png_bytep *rows, map_t map);
void save_scalex3(png_bytep *rows, map_t map);
void save_scalex5(png_bytep *rows, map_t map);

int save(map_t map) {
	int x, y;
	int width, height;
	int scl;
	png_byte color_type;
	png_byte bit_depth;
	png_structp png_ptr;
	png_infop info_ptr;
	png_bytep *row_pointers;
	char *outFile;
	
	bit_depth = 8;
	color_type = PNG_COLOR_TYPE_GRAY;
	
	scl = scale(map->m, map->n);

	switch(scl) {
		case 1:
			save_scalex1(row_pointers, map);
			width = map->m;
			height = map->n;
			break;
		case 3:
            save_scalex3(row_pointers, map);
            width = 3*map->m;
            height = 3*map->n;
			break;
		case 5:
            save_scalex5(row_pointers, map);
            width = 5*map->m;
            height = 5*map->n;
			break;
	}

	outFile = addNumToName(map->cfg.out);
	
	FILE *out = fopen(outFile, "wb");

	if(out == NULL)
		return -1;

    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    info_ptr = png_create_info_struct(png_ptr);
    
    png_init_io(png_ptr, out);
    if(setjmp(png_jmpbuf(png_ptr)))
        return 1;
    
    png_set_IHDR(png_ptr, info_ptr, width, height, bit_depth, color_type, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png_ptr, info_ptr);

    if(setjmp(png_jmpbuf(png_ptr)))
        return 2;

    png_write_image(png_ptr, row_pointers);
    
    if(setjmp(png_jmpbuf(png_ptr)))
        return 3;
    
    png_write_end(png_ptr, NULL);
    
    for(y=0; y<height; y++);
        free(row_pointers[y]);
    free(row_pointers);
	free (outFile);
	
    fclose(out);
	
	return 0;
}

void save_scalex1(png_bytep *rows, map_t map) {
	
	int x, y;
    rows = (png_bytep*) malloc(sizeof(png_bytep)*map->m);
    for(y=0; y<map->n; y++)
        rows[y] = (png_byte*)malloc(sizeof(png_byte)*map->n);

    for(y=0; y<map->n; y++) {
        png_byte *row = rows[y];
        for(x=0; x<map->m; x++) {
            row[x] = map->board[x][y] == '\0' ? 0 : 255;
        }
    }

}

void save_scalex3(png_bytep *rows, map_t map) {

    int x, y, y_tmp;
    rows = (png_bytep*) malloc(sizeof(png_bytep)*map->m*3);
    for(y=0; y<map->n; y++)
        rows[y] = (png_byte*)malloc(sizeof(png_byte)*map->n*3);
	
	y_tmp = 0;
    for(y=0; y<map->n*3; y+=3) {
		int x_tmp = 0;
        png_byte *row = rows[y];
		png_byte *row2 = rows[y+1];
		png_byte *row3 = rows[y+2];
        for(x=0; x<map->m*3; x+=3) {
            row[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
			row[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
			row[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
			x_tmp++;
        }
		x_tmp = 0;
        for(x=0; x<map->m*3; x+=3) {
            row2[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row2[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row2[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            x_tmp++;
		}
		x_tmp = 0;
        for(x=0; x<map->m*3; x+=3) {
            row3[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row3[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row3[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
			x_tmp++;
        }
		y_tmp++;
    }


}

void save_scalex5(png_bytep *rows, map_t map) {

    int x, y, y_tmp;
    rows = (png_bytep*) malloc(sizeof(png_bytep)*map->m*5);
    for(y=0; y<map->n; y++)
        rows[y] = (png_byte*)malloc(sizeof(png_byte)*map->n*5);

    y_tmp = 0;
    for(y=0; y<map->n*5; y+=5) {
        int x_tmp = 0;
        png_byte *row = rows[y];
        png_byte *row2 = rows[y+1];
        png_byte *row3 = rows[y+2];
		png_byte *row4 = rows[y+3];
        png_byte *row5 = rows[y+4];

		
        for(x=0; x<map->m*5; x+=5) {
            row[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
			row[x+3] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
			row[x+4] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            x_tmp++;
        }
        x_tmp = 0;
        for(x=0; x<map->m*5; x+=5) {
            row2[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row2[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row2[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row2[x+3] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row2[x+4] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
			x_tmp++;
        }
        x_tmp = 0;
        for(x=0; x<map->m*5; x+=5) {
            row3[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row3[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row3[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row3[x+3] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row3[x+4] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            x_tmp++;
        }
		x_tmp = 0;
        for(x=0; x<map->m*5; x+=5) {
            row4[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row4[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row4[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row4[x+3] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row4[x+4] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            x_tmp++;
        }
		x_tmp = 0;
        for(x=0; x<map->m*5; x+=5) {
            row5[x] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row5[x+1] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row5[x+2] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row5[x+3] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            row5[x+4] = map->board[x_tmp][y_tmp] == '\0' ? 0 : 255;
            x_tmp++;
        }
		
        y_tmp++;
    }



}

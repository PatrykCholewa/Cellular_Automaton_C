#include "save.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int scale(int m, int n) {
	/*if(m*n<=300) {
		return 5;
	}
	if(m*n<=14400) {
		return 3;
	}*/
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

char* createCommand(char *c) {
	char command_base[40] = "convert out/cellsim_output_tmp.pbm out/";
	char *command = malloc(strlen(command_base)+strlen(c)+1);
	strcpy(command, command_base);
	strcat(command, command_base);
	return command;
}

void save_scalex1(map_t map);
void save_scalex3(map_t map);
void save_scalex5(map_t map);

int save(map_t map) {
	char *outFile;
	char *command;
	int scl;
	
	scl = scale(map->m, map->n);

	switch(scl) {
		case 1:
			save_scalex1(map);
			break;
		case 3:
            save_scalex3(map);
			break;
		case 5:
            save_scalex5(map);
			break;
	}

	outFile = addNumToName(map->cfg.out);
	command = createCommand(outFile);
	
	system(command);
	remove("out/cellsim_output_tmp.pbm");
	
	free(outFile);
	free(command);
	
	return 0;
}

void save_scalex1(map_t map) {
	int x, y;
	system("rm _r out");
	system("mkdir out");
	FILE *tmp_out = fopen("out/cellsim_output_tmp.pbm", "w");
	
	fprintf(tmp_out, "P1\n%d %d\n", map->m, map->n);
	
	for(y=0; y<map->n; y++) {
		for(x=0; x<map->m; x++) {
			fprintf(tmp_out, "%d", map->borad[x][y] == '\0' ? 0 : 1);
		}
		fprintf("\n");
	}
	
	fclose(tmp_out);
}

png_bytep* save_scalex3(png_bytep *rows, map_t map) {

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

	return rows;
}

png_bytep* save_scalex5(png_bytep *rows, map_t map) {

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

	return rows;
}

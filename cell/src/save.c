#include "save.h"

int scale(int m, int n) {
	return 1;
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
	//int passesNumber;
	png_bytep *row_pointers;
	
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
			break;
		case 5:
			break;
	}
	
	FILE *out = fopen(map->cfg.out, "wb");

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

}

void save_scalex5(png_bytep *rows, map_t map) {

}

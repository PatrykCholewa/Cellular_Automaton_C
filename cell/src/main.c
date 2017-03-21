#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"alloc.h"
//#include"gen.h"

#define FILE_NAME_SIZE 16

int main(int argc , char **argv ){

	map_t map;
	FILE *in;

	if( argc > 2 ){
		in = fopen( argv[1] , "r" );
	} else {
		fprintf( stderr , "Too less arguments!" );
	}

	if( in == NULL ){
		fprintf ( stderr , "Set file reading error!\n");
		exit( EXIT_FAILURE );
	}

	map = initalloc( map );
	map = add_cfg( map , in );

	fclose( in );
	in = fopen( argv[2] , "r" );

	if( in == NULL ){
		fprintf ( stderr , "Map file reading error!\n");
		exit( EXIT_FAILURE );
	}

	map = boardalloc( map );
	map = add_map( map , in );

	fclose( in );
	
	//map = iter_gen( map );

	//freealloc( map );

	return 0;

}

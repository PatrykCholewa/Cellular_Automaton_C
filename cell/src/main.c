#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"alloc.h"
//#include"gen.h"

#define FILE_NAME_SIZE 16

int main(int argc , char **argv ){

	map_t map;
//	FILE *in_map = argc > 1 ? fopen( argv[1] , "r" ) : fprintf( stderr , "No map file to read given!" );
	FILE *in_set = argc > 2 ? fopen( argv[2] , "r" ) : fprintf( stderr , "No set file to read given!" );

//	if( in_map == NULL ){
//		fprintf ( stderr , "File reading error!\n");
//		exit( EXIT_FAILURE );
//	}

	if( in_set == NULL ){
		fprintf ( stderr , "File reading error!\n");
		exit( EXIT_FAILURE );
	}

	map = initalloc( map );
	map = add_cfg( map , in_set ); /*error?*/
	map = boardalloc( map );
	//map = add_map( map );

	fclose( in_set );
//	fclose( in_map );
	
	//map = iter_gen( map );

	//freealloc( map );

	return 0;

}

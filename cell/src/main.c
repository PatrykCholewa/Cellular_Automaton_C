#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"alloc.h"
//#include"gen.h"

int main(int argc , char **argv ){

	map_t map;

	FILE *in_map = argc > 1 ? fopen( argv[1] , "r" ) : fopen( "./bin/map.cfg" , "r" );
	FILE *in_set = argc > 2 ? fopen( argv[2] , "r" ) : fopen( "./bin/set.cfg" , "r" );

	if( in_set == NULL ){
		fprintf ( stderr , "File reading error!\n");
		exit( EXIT_FAILURE );
	}
	
	if( in_map == NULL ){
		fprintf ( stderr , "File reading error!\n");
		exit( EXIT_FAILURE );
	}

	map = initalloc( map );
	map = add_cfg( map , in_set );
//	map = boardalloc( map );
	//map = add_map( map );

	fclose( in_set );
	fclose( in_map );
	
	//map = iter_gen( map );

	//freealloc( map );
	return 0;

}

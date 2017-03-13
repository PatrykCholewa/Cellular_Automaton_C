#include"struct.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_FILENAME_SIZE 30
#define BUF_SIZE 1024

map_t initalloc (map_t map ){

	map = malloc( sizeof (*map) );

	map->m = 20;
	map->n = 20;
	map->cfg.nbrhd = 8;
	map->cfg.bound = 0;
	map->cfg.save = 50;
	map->cfg.intrvl = 5;
	
	map->cfg.out = malloc( 4 * sizeof (map->cfg.out) );
	map->cfg.out = "out";

	return map;

}

map_t boardalloc( map_t map ){
	
	int i;
	printf("0\n");	
	map->board = malloc( map->m * sizeof ( char * ) );
	printf("b\n");
	map->colsize = malloc( map->m * sizeof ( int ) );
	printf("cs\n");
	for( i = 0 ; i < map->m ; i++ ){
		printf("%i\n" , i);
		map->board[i] = malloc( map->n * sizeof ( char ) );
		map->colsize[i] = 0;
	}
	printf("3\n");
	map->board[3][3] = 10;
	printf("p\n");
	printf( "%i\n" , map->board[3][3] );

	return map;
}

map_t add_cfg( map_t map , FILE *in ){
	
	char s[BUF_SIZE];
	char *v;

	while( fscanf( in , "%s = %s" , s , v) != EOF ){
		
		if( strcmp( s , "nbrhd" ) == 0 ){
			if( ( strcmp( v , "Moore") == 0 ) || ( strcmp(  v , "8" ) == 0 ) ){
				map->cfg.nbrhd = 8;
			}
			if( ( strcmp( v , "Neumann") == 0 )  || ( strcmp( v , "4" ) == 0 ) ){
				map->cfg.nbrhd = 4;
			}
			/*
				Custom
			*/
		}
		if( strcmp( s , "bound" ) == 0 ){
			if( strcmp( v , "1" ) == 0 ){
				map->cfg.bound = 1;
			}
			if( strcmp( v , "0" ) == 0 ){
				map->cfg.bound = 0;
			}
			/*
			if( ( strcmp( v , "-1" ) == 0 ) || ( strcmp( v , "infinite" ) == 0 )  ){
				map->cfg.bound = -1;
			}
			*/
		}		
		if( strcmp( s , "save" ) == 0 ){
			map->cfg.save = atoi(v);
		}
		if( strcmp( s , "intrvl" ) == 0 ){
			map->cfg.intrvl = atoi(v);
		}
		if( strcmp( s , "out" ) == 0 ){
			map->cfg.out = v;
		}	
		if( strcmp( s , "m" ) == 0 ){
			map->m = atoi(v);
		}
		if( strcmp( s , "n" ) == 0 ){
			map->n = atoi(v);
		}
	
	}
	
}

//map_t add_map( map_t map , FILE *in );

//void freealloc( map_t map );



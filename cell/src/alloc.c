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
	
	map->cfg.out = malloc( MAX_FILENAME_SIZE * sizeof (map->cfg.out) );
	map->cfg.out = "out";

	return map;

}

map_t boardalloc( map_t map ){
	
	int i;

	map->board = malloc( map->m * sizeof ( *map->board ) );
	map->colsize = malloc( map->m * sizeof ( map->colsize ) );

	for( i = 0 ; i < map->m ; i++ ){
		int j;
		map->board[i] = malloc( map->n * sizeof ( map->board[i] ) );
		for ( j = 0 ; j < map->n ; j++ ){
			map->board[i][j] = 0;
		}
	}

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

	return map;
	
}

map_t add_map( map_t map , FILE *in ){

	int a;
	int b;
	while( fscanf( in , "%d %d" , &a , &b ) != EOF ){
		if( a < map->m && b < map->n ){
			map->board[a][b] = 1;
		} else {
			fprintf( stderr , "Point (%d , %d) out of bounds!\n" , a , b);
			printf("1\n");
		} 
	} 
	
	return map;

}

//void freealloc( map_t map );

#include"struct.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_FILENAME_SIZE 128
#define BUF_SIZE 1024

map_t initalloc (map_t map ){

	map = malloc( sizeof (*map) );

	map->m = 20;
	map->n = 20;
	map->cfg.nbrhd = 8;
	map->cfg.bound = 0;
	map->cfg.save = 50;
	map->cfg.intrvl = 5;
	map->cfg.live = 0;
	
	map->cfg.out = malloc( MAX_FILENAME_SIZE * sizeof (map->cfg.out) );
	map->cfg.out = ".png";

	return map;

}

map_t boardalloc( map_t map ){
	
	int i;

	map->board = malloc( map->m * sizeof ( *map->board ) );
	map->old_board = malloc( map->m * sizeof ( *map->old_board ) );

	for( i = 0 ; i < map->m ; i++ ){
		int j;
		map->board[i] = malloc( map->n * sizeof ( map->board[i] ) );
		map->old_board[i] = malloc( map->n * sizeof (map->board[i] ) );
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
			} else
			if( ( strcmp( v , "Neumann") == 0 )  || ( strcmp( v , "4" ) == 0 ) ){
				map->cfg.nbrhd = 4;
			}
			/*
				Custom
			*/
		} else
		if( strcmp( s , "bound" ) == 0 ){
			if( strcmp( v , "1" ) == 0 ){
				map->cfg.bound = 1;
			} else
			if( strcmp( v , "0" ) == 0 ){
				map->cfg.bound = 0;
			} else
			if( ( strcmp( v , "-1" ) == 0 ) || ( strcmp( v , "infinite" ) == 0 )  ){
				map->cfg.bound = -1;
			}
		} else	
		if( strcmp( s , "save" ) == 0 ){
			map->cfg.save = atoi(v);
		} else
		if( strcmp( s , "intrvl" ) == 0 ){
			map->cfg.intrvl = atoi(v);
		} else
		if( strcmp( s , "out" ) == 0 ){
			int iter;
			map->cfg.out = malloc( MAX_FILENAME_SIZE * sizeof( map->cfg.out ) );
			for( iter = 0 ; iter < MAX_FILENAME_SIZE ; iter++ ){
				map->cfg.out[iter] = v[iter];
				if( v[iter] == '\0' ){
					iter = MAX_FILENAME_SIZE;
				}
			}
		} else	
		if( strcmp( s , "m" ) == 0 ){
			map->m = atoi(v);
		} else
		if( strcmp( s , "n" ) == 0 ){
			map->n = atoi(v);
		} else 
		if( strcmp( s , "live" ) == 0 ){
			if( strcmp( v , "yes" ) == 0 ){
				map->cfg.live = 1;				
			}
		} else {}
	
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

void freealloc( map_t map ){

	int i;
	for( i = 0 ; i < map->m ; i++ ){
		free( map->board[i] );
		free( map->old_board[i] );
	}
	free( map->cfg.out );
	free( map->board );
	free( map->old_board );
	free( map );
	
	return ;
}

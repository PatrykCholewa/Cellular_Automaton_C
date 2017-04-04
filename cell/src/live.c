#include <stdio.h>
#include <unistd.h>
#include "struct.h"

void wait(){

	usleep( 200000 );

}

void print_board( map_t map ){

	int i;
	int j;

	wait();
	system("clear");

	printf(" ");
	for( i = 0 ; i < map->m ; i++ ){
		printf("-");
	}
	printf("\n");

	for( i = 0 ; i < map->n ; i++ ){
	
		printf( "|" );	
	
		for( j = 0 ; j < map->m ; j++ ){
			int p = map->board[j][i];
			if ( p == 0 ){
				printf(" ");
			} else {
				printf("#");
			}
		}  	

		printf( "|" );	

		printf( "\n" );
	}
	
	printf( " " );
	for( i = 0 ; i < map->m ; i++ ){
		printf("-");
	}
	printf("\n");
	
	return ;

}

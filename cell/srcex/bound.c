#include "struct.h"
#include "bound.h"
#include <stdio.h>

int state_check( map_t map , int x ,int y){

	if( map->cfg.bound == 0 ){
		return dead_bound( map , x , y );
	}
	
	if( map->cfg.bound == 1 ){
		return live_bound( map , x , y );
	}

	if( map->cfg.bound == -1 ){
		return infinitive_bound( map , x ,y );
	}

	fprintf( stderr , "Unsupported bound type!\n" );
	return 0;
	
}

int dead_bound( map_t map , int x , int y){
	
	if( x >= map->m ){
		return 0;
	}
	if( x < 0 ){
		return 0;
	}
	if( y >= map->n ){
		return 0;
	}
	if( y < 0 ){
		return 0;
	}
	
	return map->board[x][y];

}

int live_bound( map_t map , int x , int y){

	if( x >= map->m ){
		return 1;
	}
	if( x < 0 ){
		return 1;
	}
	if( y >= map->n ){
		return 1;
	}
	if( y < 0 ){
		return 1;
	}
	
	return map->board[x][y];

}

int infinitive_bound( map_t map , int x , int y){

	if( x >= map->m ){
		x = x - map->m;
	}
	if( x < 0 ){
		x = x + map->m;
	}
	if( y >= map->n ){
		y = y - map->n;
	}
	if( y < 0 ){
		y = y + map->n;
	}
	
	return map->board[x][y];


}

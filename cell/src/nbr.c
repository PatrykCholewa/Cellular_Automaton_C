#include "struct.h"
#include "nbr.h"
#include "bound.h"
#include <stdio.h>

int neumann_neighbourhood( map_t map , int x , int y ){

	int sum = 0;
	
	sum = sum + state_check( map , x + 1 , y );
	sum = sum + state_check( map , x - 1 , y );
	sum = sum + state_check( map , x , y + 1 );
	sum = sum + state_check( map , x , y - 1 );

	return sum;

}

int moore_neighbourhood( map_t map , int x , int y ){
	
	int sum = 0;
	
	sum = sum + state_check( map , x + 1 , y );
	sum = sum + state_check( map , x + 1 , y - 1 );
	sum = sum + state_check( map , x + 1 , y + 1 );
	sum = sum + state_check( map , x - 1 , y );
	sum = sum + state_check( map , x - 1 , y + 1 );
	sum = sum + state_check( map , x - 1 , y - 1 );
	sum = sum + state_check( map , x , y + 1 );
	sum = sum + state_check( map , x , y - 1);
	
	return sum;

}

int num_of_neighbours( map_t map , int x , int y ){

	if( map->cfg.nbrhd == 4 ){
		return neumann_neighbourhood( map , x , y );
	}
	
	if( map->cfg.nbrhd == 8 ){
		return moore_neighbourhood( map , x , y );
	}

	fprintf( stderr , "Unsupported neighbourhood type!\n" );
	return 0;

}

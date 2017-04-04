#include <string.h>
#include "struct.h"
#include "save.h"
#include "life.h"
#include "live.h"

map_t next_gen( map_t map ){

	int i;
	int j;
	int k;

	for( k = 0 ; k < map-> m ; k++ ){
		memcpy( map->old_board[k] , map->board[k] , map->n * sizeof ( map->board[k] ) );
	}

	for( i = 0; i < map->m ; i++ ){
		for( j = 0 ; j < map->n ; j++ ){
						
			map->board[i][j] = map->board[i][j] +  cells_next_state( map , i , j );
			
		}
	} 			

	return map;

}

map_t iter_gen( map_t map ){

	int i;
	int j;

	save( map );

	if( map->cfg.live == 1){
		print_board ( map );
	}

	for( i = 0 ; i < map->cfg.save ; i++ ){
	
		for ( j = 0 ; j < map->cfg.intrvl ; j++ ){

			map = next_gen( map );
	
			if( map->cfg.live == 1){
				print_board ( map );
			}

		}
			
		save ( map );

	}

	return map;	

}


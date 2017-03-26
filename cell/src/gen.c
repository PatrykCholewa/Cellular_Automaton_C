#include <string.h>
#include "struct.h"
//#include "save.h"
//#include "life.h"

map_t next_gen( map_t map ){

	int i;
	int j;
	int k;

	for( i = 0; i < map->m ; i++ ){
		for( j = 0 ; j < map->n ; j++ ){
			
			for( k = 0 ; k < map-> n ; k++ ){
				memcpy( map->old_board[k] , map->board[k] , map->n * sizeof ( map->board[k] ) );
			}
			
//			map->board[i][j] = map->board[i][j] + cells_next_state( map , i , j );

		}
	} 			

	return map;

}

map_t iter_gen( map_t map ){

	int i;
	int j;

//	map = save( map );

	for( i = 0 ; i < map->cfg.save ; i++ ){
	
		for ( j = 0 ; j < map->cfg.intrvl ; j++ ){

			map = next_gen( map );

		}

//		map = save ( map );

	}

	return map;	

}


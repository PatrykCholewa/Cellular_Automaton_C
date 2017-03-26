#include "struct.h"
//#include "save.h"
//#include "nbr.h"

map_t next_gen( map_t map ){

	return map;

}

map_t iter_gen( map_t map ){

	int i;
	int j;

	//map = save( map );

	for( i = 0 ; i < map->cfg.save ; i++ ){
	
		for ( j = 0 ; j < map->cfg.intrvl ; j++ ){

			map = next_gen( map );

		}

//		map = save ( map );

	}

	return map;	

}


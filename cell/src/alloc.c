#include"struct.h"
#include<stdlib.h>
#include<stdio.h>

#define MAX_FILENAME_SIZE 30

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

//map_t boardalloc( map_t map );

//map_t add_cfg( map_t map , FILE *in );

//map_t add_start( map_t map , FILE *in );

//void freealloc( map_t map );



#include"struct.h"
#include<stdio.h>
#include<stdlib.h>

#ifndef ALLOC_CONTROL
#define ALLOC_CONTROL

map_t initalloc (map_t map );

map_t boardalloc( map_t map );

map_t add_cfg( map_t map , FILE *in );

map_t add_start( map_t map , FILE *in );

void freealloc( map_t map );

#endif

#include"struct.h"
#include<stdlib.h>

map_t inittalloc (map_t map );

map_t boardalloc( map_t map );

map_t add_cfg( map_t map , FILE *in );

map_t add_start( map_t map , FILE *in );

void freealloc( map_t map );



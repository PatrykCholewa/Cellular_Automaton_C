#include<stdio.h>
#include<stdlib.h>
#include"struct.h"
#include"alloc.h"
//#include"gen.h"

int main(int argc , char **argv ){

	map_t map;
	
	map = initalloc( map );
	//map = add_cfg( map );
	//map = boardalloc( map );
	//map = add_start( map );
	
	//map = iter_gen( map );

	//freealloc( map );

	return 0;

}

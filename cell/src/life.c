#include "struct.h"
//#include "nrb.h"

int cells_next_state(map_t map, int x, int y ){

	const char cstate = map->board[x][y];
	int nbr = /* num_of_neighbours( map , x , y ); */0;
	
	if( cstate == 0 ){
		if ( nbr == 3 ){
			return 1;
		} else {
			return 0;
		}
	} else {
		if ( nbr == 2 || nbr == 3 ){
			return 0;
		} else {
			return -1;
		}
	}

}

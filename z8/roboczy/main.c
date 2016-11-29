#include <stdio.h>
#include "parser.h"
#include "cout.h"
//#include "dane.h"

int main ( int argc, char **argv){

	int i;
	
	if( argc = 1 ){
		
		printf("Podaj plik do czytania!");
		return EXIT_FAILURE;

	}

	for(i=1 ; i <= argc ; i++ ){

		char *inpname = argv[i];	
		analizatorSkladni( inpname );

	}

	wypisz( argc - 1 );

	return EXIT_SUCCESS;

}	

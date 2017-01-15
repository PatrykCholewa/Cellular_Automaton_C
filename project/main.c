#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
/**
 ** #include "struct.h"
 ** #include "alloc.h"
 ** #include "matrix.h"
 ** #include "piv_ge_solver.h"
 ** #include "czas.h"
 ** #mod3.h"
 ** #analizator.h"
 ** #bisekcja.h"
 ** #aproksymator_na_bazie.h"
 ** #points.h"
 ** #splines.h"
 ** #wykreslnik.h"
  */

int main(int argc, char **argv){

	int opt;
	FILE *in;
	FILE *out;
	int max_iter = 1000;
	double dt = 0.001;
	double tempk = 200;
	double tk = 0.4;
	char bool3 = 0;
	
	while ((opt = getopt(argc, argv, "ceip:")) != -1){
		switch (opt){
			case 'c':
				in = fopen( optarg ,"r" );
				break;
			case 'i':
				printf( "%d\n" , max_iter);
				max_iter = atoi(optarg);
				printf( "%d\n" , max_iter);
				sscanf(optarg, "%lf", &dt);
				break;
			case 'p':
				out = fopen( optarg , "w" );
				break;
			case 'e':
				b = 1;
				sscanf(optarg, "%lf", &tempk);
				sscanf(optarg, "%lf", &tk);
				break;
			default:
				fprinf(stderr, "Błąd oflagowania!");
				exit(EXIT_FAILURE);
		}
	}	
	/**
	  * Nie działa, bo ma problemy z konwersją stringów. Nie wiem czemu.
	  * Przynajmniej umie wchodzić do case'ów.
	  */
	
	if( in == NULL ){
		in = fopen( "stale.cfg" , "r");
		if ( in == NULL ){
			fprintf (stderr , "Brak pliku wejścia.");
			exit(EXIT_FAILURE);
		}
	}
	if (out == NULL ){
		out = fopen( "wykres.png" , "w" );
	}
	
	/**
	  * ...
	  */
	
	return 0;
}	

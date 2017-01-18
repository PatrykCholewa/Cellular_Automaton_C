#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "struct.h"
#include "alloc.h"
/**
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


/*
	MOJA FUNKCJA TO RACZEJ OSTATECZNOSC, DLATEGO
	JA OBKOMENTOWALEM. JEST PROSTA, W ZWIAZKU
	Z CZYM NIE WYWALA BLEDU, KIEDY ZNAJDZIE
	NIEZNANA FLAGE. PO PROSTU JA OMIJA.
	MIMO TEJ WADY MA TEZ INNA, DOSYC ISTOTNA
	ZALETE - DZIALA...
	
int getopt2(char **source, int numOfStringsInSource, char *target, int isBoolean)
{
	int i;
	for(i=0; i<numOfStringsInSource; i++) {
		if(strcmp(source[i], target) == 0) {
			if(isBoolean == 0) {
				if(i != numOfStringsInSource-1)
					return i+1;
				else
					return -1;
			}else
				return i;
		}
	}
	
	return -1;
}
*/

int main(int argc, char **argv){

	int opt;
	FILE *in = NULL;
	FILE *out = NULL;
	int max_iter = 1000;
	double dt = 0.001;
	double tempk = 200;
	double tk = 0.4;
	char bool3 = 0;
	int i;
	
	/*
		GDYBYSMY UZYLI MOJEJ FUNKCJI,
		TO WHILE Z GETOPT I SWITCHA
		TRZEBA USUNAC, A TO ODKOMENTOWAC.
	
	opt = getopt2(argv, argc, "-c", 0);
	if(opt != -1) {
		in = fopen(argv[opt], "r");
	}
	opt = getopt2(argv, argc, "-i", 0);
        if(opt != -1) {
		max_iter = atoi(argv[opt]);
		if(opt != argc-1)
			dt = atof(argv[opt+1]);
        }
	opt = getopt2(argv, argc, "-p", 0);
        if(opt != -1) {
		out = fopen(argv[opt], "w");
        }
	opt = getopt2(argv, argc, "-e", 0);
        if(opt != -1) {
		tempk = atof(argv[opt]);
		if(opt != argc-1)
			tk = atof(argv[opt+1]);
        }
	*/

	// Dodać obsługę błędów

	while ((opt = getopt(argc, argv, "cipe:")) != -1){
		switch (opt){
			case 'c':
				in = fopen( argv[optind] ,"r" );
				break;
			case 'i':
				max_iter = atoi(argv[optind]);
				sscanf(argv[optind + 1], "%lf", &dt);
				break;
			case 'p':
				out = fopen( argv[optind] , "w" );
				break;
			case 'e':
				bool3 = 1;
				sscanf(argv[optind], "%lf", &tempk);
				sscanf(argv[optind + 1], "%lf", &tk);
				break;
			default:
				fprintf(stderr, "Błąd oflagowania!\n");
				exit(EXIT_FAILURE);
		}
	}
	
	if( in == NULL ){
		in = fopen( "stale.cfg" , "r");
		if ( in == NULL ){
			fprintf (stderr , "Brak pliku wejścia.\n");
			exit(EXIT_FAILURE);
		}
	}
	if (out == NULL ){
		out = fopen( "wykres.png" , "w" );
	}
	
	cool_t cool_data;
	
	cool_data = alloc( cool_data );
	cool_data = add_const( cool_data , in );	

	if( bool3 == 0 ){
		//przebiegnij( cool_t cool_data, int max_iter, double dt)
		// ...
	} else {
		// bisektor() ???
		// ...
	}
	// generuj() ???
	// wypisz_wynik() ???
	// ... ???

	return 0;
}	

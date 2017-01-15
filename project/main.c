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
	FILE *in;
	FILE *out;
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

	
	while ((opt = getopt(argc, argv, "ceip:")) != -1){
		switch (opt){
			case 'c':
				in = fopen( optarg ,"r" );
				break;
			case 'i':
				printf( "%d\n" , max_iter);
				if(optarg==NULL) printf("optarg == NULL\n");
				max_iter = atoi(optarg);
				printf( "%d\n" , max_iter);
				sscanf(optarg, "%lf", &dt);
				break;
			case 'p':
				out = fopen( optarg , "w" );
				break;
			case 'e':
				//b = 1;	- nie wiem po co to b, ale nie ma deklaracji, wiec obkomentowalem, zeby skompilowac.
				sscanf(optarg, "%lf", &tempk);
				sscanf(optarg, "%lf", &tk);
				break;
			default:
				fprintf(stderr, "Błąd oflagowania!");
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
			fprintf (stderr , "Brak pliku wejścia.\n");
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

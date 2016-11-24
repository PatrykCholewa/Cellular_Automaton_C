#include <stdio.h> 
#include <stdlib.h> 

#include "bibl.h"  

/*	
typedef struct c{
	int **pozycje;
	char **slowa;
	int *liczba_wystapien;
	int ile_slow;
} skorowidz_t;
*/

//void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t skorowidz );

//void szukaj_do_skorowidza( FILE *in, skorowidz_t skorowidz);

//void wypisz_skorowidz(skorowidz_t skorowidz);

int
main( int argc, char **argv ) {

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	if( argc < 3 ) {
		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	skorowidz_t *skorowidz;

	zainicjuj_skorowidz( argc, argv, skorowidz);

	szukaj_do_skorowidza( in , skorowidz);

	wypisz_skorowidz( skorowidz);

	return EXIT_SUCCESS;
}


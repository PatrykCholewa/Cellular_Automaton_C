#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#include "bibl.h"

#define BUFSIZE 8192   
	
typedef struct c{
	int **pozycje;
	char **slowa;
	int *liczba_wystapien;
} skorowidz_t;

//void zainicjuj_skorowidz( int argc, char **argv, skorowidz_t skorowidz );

//void szukaj_do_skorowidza( FILE *in, skorowidz_t skorowidz);

//void wypisz_skorowidz( skorowidz_t skorowidz);

int
main( int argc, char **argv ) {
	int i;
	int ile_linii;
	char buf[BUFSIZE];

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	skorowidz_t *skorowidz;

	zainicjuj_skorowidz( argc, argv, &skorowidz);

	if( argv < 2 ) {
		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	szukaj_do_skorowidza( in ,&skorowidz);

	wypisz_skorowidz(&skorowidz);

	return EXIT_SUCCESS;
}


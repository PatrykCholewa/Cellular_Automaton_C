#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define BUFSIZE 8192   
	
//void zainicjuj_skorowidz( int argc, char **argv, int **skorowidz);

//void dodaj_pozycje_skorowidza( int **skowowidz, int i, int linia, char **slowa );

//void wypisz_skorowidz( int **skorowidz, char **slowa );

int
main( int argc, char **argv ) {
	int i;
	int ile_linii;
	char buf[BUFSIZE];

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	int **skorowidz;

	zainicjuj_skorowidz( argc, argv, skorowidz);

	if( skorowidz[0][0] == 0 ) {
		fprintf( stderr, "%s: błąd: proszę podać słowa do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}

	ile_linii= 0;
	while( fgets( buf, BUFSIZE, in ) != NULL ) {
		ile_linii++;
		for( i= 0; i < skorowidz[0][0]; i++ )
			if( strstr( buf, /* kolejne slowa */ ) != NULL ) { ///!!!!!!
			//	dodaj_pozycje_skorowidza( skorowidz, i, ile_linii, argv );
		}
	}

	wypisz_skorowidz( skorowidz , argv );

	return EXIT_SUCCESS;
}


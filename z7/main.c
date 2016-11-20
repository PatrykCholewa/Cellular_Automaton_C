#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define BUFSIZE 8192   
	
#typedef struct c{
	int **tabela;
	char **slowa;
} elem_skor_t , *pointer_skor_t;

//void zainicjuj_skorowidz( int argc, char **argv, pointer_skor_t skorowidz );

//void dodaj_pozycje_skorowidza( pointer_skor_t skowowidz, int i, int linia);

//void wypisz_skorowidz( pointer_skor_t skorowidz);

int
main( int argc, char **argv ) {
	int i;
	int ile_linii;
	char buf[BUFSIZE];

	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	pointer_skor_t skorowidz;

	zainicjuj_skorowidz( argc, argv,&skorowidz);

	if( skorowidz->tabela[0][0] == 0 ) {
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


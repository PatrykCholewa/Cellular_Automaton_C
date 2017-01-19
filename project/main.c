#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "struct.h"
#include "alloc.h"
#include "czas.h"

#define TMP_SIZE 50

/**
  * #mod3.h"
  * #analizator.h"
  * #bisekcja.h"
  * #wykreslnik.h"
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
	FILE *cwfile = NULL;
	char *cwfilename;
	char stmp[TMP_SIZE];
	char stmp2[TMP_SIZE];
	char bool3 = 0;
	int ret;
	
	
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

	cool_t cool_data;
	
	cool_data = startalloc( cool_data );

	while ((opt = getopt(argc, argv, "cipew:")) != -1){
		switch (opt){
			case 'c':
				in = fopen( argv[optind] ,"r" );
				break;
			case 'i':
				cool_data->Yc = atoi(argv[optind]);
				sscanf(argv[optind + 1], "%lf", &cool_data->dt);
				break;
			case 'p':
				out = fopen( argv[optind] , "w" );
				break;
			case 'e':
				bool3 = 1;
				break;
			case 'w':
				cwfile = fopen( argv[optind] , "r" );
				cwfilename = argv[optind];
				break;
			default:
				fprintf(stderr, "Błąd oflagowania!\n");
				exit(EXIT_FAILURE);
		}
	}
	
	cool_data = Yalloc( cool_data );

	if( in == NULL ){
		in = fopen( "stale.cfg" , "r");
		if ( in == NULL ){
			fprintf (stderr , "Brak pliku wejścia.\n");
			exit(EXIT_FAILURE);
		}
	}
	if( cwfile == NULL ){
		cwfile = fopen( "cw.cfg" , "r");
		cwfilename = "cw.cfg";
		if ( cwfile == NULL ){
			fprintf (stderr , "Brak pliku z danymi, co do ciepła właściwego..\n");
			exit(EXIT_FAILURE);
		}
	}
	if (out == NULL ){
		out = fopen( "wykres.png" , "w" );
	}
	
	
	cool_data = add_const( cool_data , in );

	snprintf( stmp, TMP_SIZE , "%lf" , (double)cool_data->Yc * cool_data->dt);
	snprintf( stmp2, TMP_SIZE , "%d" , cool_data->Yc);
	ret = execl( "./intrp","./intrp","-s","spl","-p",cwfilename,"-g","myplot","-f","0","-t",stmp,"-n",stmp2,NULL);

	if (ret == -1 ){
		fprintf( stderr , "Problemy z użyciem pliku do wyliczenia cw.\n");
		exit(EXIT_FAILURE);
	}

	if( bool3 == 0 ){
		cool_data = przebiegnij( cool_data );
	} else {
		// bisektor() ???
		// ...
	}
	// generuj() ???
	// wypisz_wynik() ???
	// ... ???

	printf( "%d\n", ret);

	return 0;
}	

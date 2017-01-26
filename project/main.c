#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "struct.h"
#include "alloc.h"
#include "czas.h"
#include "wykreslnik.h"
#include "bisekcja.h"
#include "aproksymator/splines.h"
#include "aproksymator/points.h"
#define TMP_SIZE 50

int main(int argc, char **argv){

	int opt;
	FILE *in = NULL;
	FILE *cwfile = NULL;
	char *out = "wykres.png";
	char bool3 = 0;
	int ret = 0;
	points_t pts;
	cool_t cool_data;
	pts.n = 0;

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
				out = argv[optind];
				break;
			case 'e':
				bool3 = 1;
				break;
			case 'w':
				cwfile = fopen( argv[optind] ,"r" );
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
		if ( cwfile == NULL ){
			fprintf (stderr , "Błąd pliku cw.\n");
			exit(EXIT_FAILURE);
		}
	}

	cool_data = add_const( cool_data , in );

	read_points_failed( cwfile , &pts );

	cool_data->cw = splines_approximate( &pts , 4 );
	
	if (ret == -1 ){
		fprintf( stderr , "Problemy z użyciem pliku do wyliczenia cw.\n");
		exit(EXIT_FAILURE);
	}
	
	if( bool3 == 0 ){
		cool_data = przebiegnij( cool_data );
		printf("\nTemperatura koncowa: %gC\n", cool_data->Y[0][cool_data->Yc]);
		printf("Czas, po ktorym pret osiagnie dana temperature: %gs\n\n", wynikosprawdzacz(cool_data));

	} else {
		printf("\nMasa wody wymagana do schlodzenia preta do temperatury %gC: %gkg\n\n", cool_data->tempend, szukaj_bisekcyjnie(cool_data));
	}

	fclose( in );	
	
	make_plot(out, cool_data );

	return 0;
}	

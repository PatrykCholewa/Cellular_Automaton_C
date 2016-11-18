#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8192

int
szukajLinia(char *linia, char *szukane) {
	
	/*
		Zwraca 1, jezeli znaleziono wzorzec w linii
		oraz 0, jezeli go nie znaleziono
	*/

	if(strstr(linia, szukane) != NULL)
		return 1;
	return 0;
}

int
iloscWystapien(FILE *in, char *szukane) {
	
	char *buf2[BUFSIZE];
	int i=0;
	while(fgets(buf2, BUFSIZE, in) != NULL)
		if(szukajLinia(buf2, szukane) == 1)
			i++;
	fseek(in, 0, 0);
	return i;
}

void
szukajPlik(FILE *in, char *szukane, int *tab_wyniki) {
	
	/*
		Zapisuje w tablicy numery linii,
		w ktorych znaleziono wzorzec
	*/
	
	fseek(in, 0, 0);
	
	tab_wyniki = malloc((iloscWystapien(in, szukane)+1)*sizeof (int));
	
	int il_linii = 0;
	int i=1;
	
	while(fgets(buf, BUFSIZE, in) != NULL) {
		if(szukajLinia(buf, szukane) == 1) {
			tab_wyniki[il_linii+1] = i;
			// Zapisz i do tab_wyniki
			// z alokacja pamieci
			il_linii++;
		}
		i++;
	}
	
	tab_wyniki[0] = il_linii;
}

int
main(int argc, char **argv) {
	
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8192

#typedef struct c{
	int **tabela;
	char **slowa;
} elem_skor_t , *pointer_skor_t;

void zainicjuj_skorowidz( int argc, char **argv, elem_skor skorowidz );

void dodaj_pozycje_skorowidza( elem_skor_t skowowidz, int i, int linia);

void wypisz_skorowidz( elem_skor_t skorowidz);

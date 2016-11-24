#include <stdio.h>


typedef struct {
	int **pozycje;
	char **slowa;
	int *liczba_wystapien;
	int ile_slow;
} skorowidz_t;


void zainicjuj_skorowidz( int ile_slow, char **slowa, skorowidz_t *s );

void szukaj_do_skorowidza( FILE *in, skorowidz_t *s);

void wypisz_skorowidz( skorowidz_t *skorowidz);

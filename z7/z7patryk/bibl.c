#include "bibl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 8192

/*
typedef struct c{
	int **pozycje;
	char **slowa;
	int *liczba_wystapien;
	int ile_slow;
}skorowidz_t;
*/



static int
dlugosc_lancucha(char *lancuch)	{
	int dlugosc;
	dlugosc = 0;
	while(lancuch[dlugosc] != '\0')
		dlugosc++;
	return dlugosc;
}

static void
copy(char *s, char*q) {
	int i=0;
	do {
		q[i] = s[i];
	}while(q[i++] != '\0');
}

void
zainicjuj_skorowidz(int ile_argumentow, char **slowa, skorowidz_t *s) {
	int i;
//	s->ile_slow = malloc ( sizeof (int) );
	s->ile_slow = ile_argumentow-2;
	s->pozycje = malloc(s->ile_slow*sizeof (int*) );
	for(i=0; i<s->ile_slow; i++)
		s->pozycje[i] = NULL;
	s->liczba_wystapien = malloc(s->ile_slow*sizeof (int) );
	for(i=0; i<s->ile_slow; i++)
		s->liczba_wystapien[i] = 0;
	s->slowa = malloc(s->ile_slow*sizeof (char*));
	for(i=0; i<s->ile_slow; i++) {
		s->slowa[i] = malloc(dlugosc_lancucha(slowa[i+2])*sizeof(char));
		copy(slowa[i+2], s->slowa[i]);
	}
	
}

static void
dodaj(skorowidz_t *s, int slowo, int linia) {
	if(s->pozycje[slowo] == NULL) {
		s->pozycje[slowo] = malloc(sizeof (int*));
		s->pozycje[slowo][0] = linia;
		s->liczba_wystapien[slowo]++;
	}else{
		int i;
		int *tmp = malloc((s->liczba_wystapien[slowo]+1) * sizeof(int*));
		for(i=0; i<s->liczba_wystapien[slowo]; i++)
			tmp[i]=s->pozycje[slowo][i];
		tmp[i] = linia;
		free(s->pozycje[slowo]);
		s->liczba_wystapien[slowo]++;
		s->pozycje[slowo] = tmp;
	}
}

void
szukaj_do_skorowidza(FILE *in, skorowidz_t *s) {
	int numer_slowa;
	for(numer_slowa=0; numer_slowa<s->ile_slow; numer_slowa++){
		int numer_linii=0;
		fseek(in, 0, 0);
		char buf[BUFSIZE];
		while(fgets(buf, BUFSIZE, in) != NULL) {
			numer_linii++;
			if(strstr(buf, s->slowa[numer_slowa]) != NULL)
				dodaj(s, numer_slowa, numer_linii);
		}
	}
}

void wypisz_skorowidz( skorowidz_t *skorowidz){
	int i;
	for (i = 0 ; i < skorowidz->ile_slow ; i++){
		if(skorowidz -> liczba_wystapien[i] != 0){
			printf("Słowo \"%s\" występuje w liniach: ", skorowidz->slowa[i]);
			int j;
			for(j = 0 ; j < skorowidz->liczba_wystapien[i] ; j++){
				printf("%d, ", skorowidz->pozycje[i][j]);
			}
			printf(".\n");
		}else{
			printf("Nie napotkano słowa \"%s\".\n", skorowidz->slowa[i]);
		}
	}
	return ;
}


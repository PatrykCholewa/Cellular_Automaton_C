#ifndef _BIBL_H_

#define _BIBL_H_
#define BUFSIZE 8192

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct e{
	int ile_slow;
	int **pozycje;
}skorowidz;

void zainicjuj_skorowidz(int il_slow, char **slowa, skorowidz s);
// inicjuje skorowidz - tworzy pierwszy wymiar tablicy 2W w skorowidzu s

void dodaj(skorowidz s, nr_slowa, int linia);
// dodaje jedna linie do elementu nr_slowa w tablicy 2W skorowidza

void szukaj_linii(FILE *we, char **slowa, skorowidz s);
// szuka po kolei kazdego slowa z tablicy slowa (czyli argv) w pliku we
// i zapisuje na bierzaco wyniki do skorowidza s za pomoca funkcji dodaj()

void wypisz_skorowidz(skorowidz s);
// robi to, co ma w nazwie z tym, co ma w argumencie - nie chce
// mi sie tlumaczyc, chociaz to, co wlasnie pisze pewnie zajelo
// mi wiecej czasu...

#endif

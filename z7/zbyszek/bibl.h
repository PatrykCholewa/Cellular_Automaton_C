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

void zainicjuj_skorowidz(int il_slow, skorowidz s);
// inicjuje skorowidz - tworzy pierwszy wymiar tablicy 2W w skorowidzu s
// na podstawie podanej ilosci slow(argc-2)
// Uwaga: element tablicy [0][0] jednak nie bedzie przechowywal informacji
// o ilosci slow - od tego jest oddzielny element struktury, ale
// informacje o ilosci znalezionych linii nadal beda przechowywane
// w elementach [numer_slowa][0]

void dodaj(skorowidz s, nr_slowa, int linia);
// dodaje jeden numer linii do elementu [nr_slowa] tablicy 2W skorowidza
// (powieksza drugi wymiar tablicy o jeden element oraz pierwsza
// wartosc zwiaksza o jeden)

void szukaj_linii(FILE *we, char **slowa, skorowidz s);
// szuka po kolei kazdego slowa z tablicy slowa (czyli argv) w pliku we
// i zapisuje na bierzaco wyniki do skorowidza s za pomoca funkcji dodaj()

void wypisz_skorowidz(skorowidz s);
// robi to, co ma w nazwie z tym, co ma w argumencie - nie chce
// mi sie tlumaczyc rzeczy wiadomych, chociaz to, co wlasnie
// pisze pewnie zajelo mi wiecej czasu...

#endif

#include "bisekcja.h"
#include "czas.h"
#include "analizator_danych.h"
#include <stdio.h>

static double wynik(cool_t t, double mW) {
	t->stale.mw = mW;
	
	t = przebiegnij(t);
	return wynikosprawdzacz(t);
}

double szukaj_bisekcyjnie( cool_t t) {
	double eps = 0.0599;
	double a = 0.001;
	double b = 100.0;
	double tmp = (a+b)/2;

	while(wynik(t, tmp) > t->tend+eps || wynik(t, tmp) < t->tend-eps) {
		if(wynik(t, tmp) < t->tend)
			a = tmp;
		else
			b = tmp;
		tmp = (a+b)/2;
	}
	
	
	return tmp;
}

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
	double eps = 0.05;
	double a = 0.25;
	double b = 200;

	while((wynik(t, a)-t->tend)+(wynik(t, b)-t->tend) > eps) {
		double tmp = ((a+b)/2.0);
		printf("a %g   b %g   tmp %g    t %g\n",a, b, tmp, wynik(t, tmp)-t->tend);
		printf("%g\n", t->stale.mw);
		if(wynik(t, tmp)-t->tend == 0)
			return tmp;
		else if(wynik(t, tmp)-t->tend < 0)
			b = tmp;
		else
			a = tmp;
	}
	
	t->stale.mw = (a+b)/2;
	t = przebiegnij(t);
	
	return (a+b)/2;
}

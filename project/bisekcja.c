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
	double a = 0.001;
	double b = 100.0;
	double tmp = (a+b)/2;
	printf("%g\n", wynik(t, t->stale.mw));
	/*
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
	}*/

	while(wynik(t, tmp) > t->tend+eps || wynik(t, tmp) < t->tend-eps) {
		if(wynik(t, tmp) < t->tend)
			a = tmp;
		else
			b = tmp;
		tmp = (a+b)/2;
		printf("a=%g b=%g tmp=%g wyn=%g\n",a,b,tmp, wynik(t, tmp));
	}
	
	return tmp;
}

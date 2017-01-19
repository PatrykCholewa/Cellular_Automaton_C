#include "bisekcja.h"
#include "czas.h"
#include "analizator_danych.h"

static double wynik(cool_t t, double mW) {
	t->stale.mw = mW;
	
	t = przebiegnij(t);
	return wynikosprawdzacz(t);
}

double szukaj_bisekcyjnie( cool_t t) {
	double eps = 0.01;
	double a = wynik(t, 60.0);
	double b = a;
	while(wynik(t, a) - t->tend < 0)
		a /= 2;
	while(wynik(t, b) - t->tend > 0)
		b += b;
	
	while((wynik(t, a)-t->tend)+(wynik(t, b)-t->tend) > eps) {
		double tmp = (a+b)/2;
		if(wynik(t, tmp)-t->tend == t->tempend)
			return tmp;
		else if((wynik(t, tmp)-t->tend) * (wynik(t, a)-t->tend) < 0)
			b = tmp;
		else
			a = tmp;
	}
	
	t->stale.mw = (a+b)/2;
	t = przebiegnij(t);
	
	return (a+b)/2;
}

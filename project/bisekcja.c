#include "bisekcja.h"
#include "czas.h"
#include <stdio.h>

double wynikosprawdzacz( cool_t t) {
        double czas = 0;
        int i = 0;

        while(t->Y[0][i]-t->Y[1][i] > t->dt) {
                czas += t->dt;
                i++;

                if(i == t->Yc)
                        return -1;
        }

        return czas;
}

static double wynik(cool_t t, double mW) {
	t->stale.mw = mW;
	
	t = przebiegnij(t);
	return t->Y[0][t->Yc];
}

double szukaj_bisekcyjnie( cool_t t) {
	double a = 0.001;
	double b = 200.0;
	double tmp = (a+b)/2;
	
	while( wynik(t, tmp) > t->tempend+t->tempeps || wynik(t, tmp) < t->tempend-t->tempeps) {
		if(wynik(t, tmp) < t->tempend)
			b = tmp;
		else
			a = tmp;
		tmp = (a+b)/2;
	}
	
	return tmp;
}

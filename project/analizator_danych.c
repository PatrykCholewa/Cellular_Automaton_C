#include "analizator_danych.h"

double wynikosprawdzacz( cool_t t) {
	double eps = 0.01;
	double czas = 0;
	int i = 0;
	
	while(t->Y[0][i]-t->Y[1][i] > eps) {
		czas += t->dt;
		i++;
	
		if(i == t->Yc)
			return -1;
	}
	
	return czas;
}

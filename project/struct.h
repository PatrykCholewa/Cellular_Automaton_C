#include "aproksymator/splines.h"
#ifndef STRUCT_DEF
typedef struct {
	double A;
	double mb;
	double mw;
	double cb;
	double h;
} const_t;

typedef struct {
	double **Y;
	int Yc; 
	/**
	  *liczba kolumn
	  */
	double dt;
	/**
	  *krok czasowy
	  */
	double tempeps;
	double tempend;
	spline_t *cw;
	const_t stale;
} elem_t, *cool_t;

#define STRUCT_DEF
#endif

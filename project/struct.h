#ifndef STRUCT_DEF
typedef struct {
	double A;
	double mb;
	double mw;
	double cb;
	double h;
	/**
	  *double cw
	  */
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
	double tend;
	double tempend;
	const_t stale;
} elem_t, *cool_t;

#define STRUCT_DEF
#endif

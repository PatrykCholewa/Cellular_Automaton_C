#include <stdio.h>
#include <stdlib.h>


double **alloc(double **x, int k) {
	
	/*	Krotka instrukcja obslugi:
		**x - tablica 2D, ktora sobie zaalokujemy (poki co z 2 wierszami)
		k - obecna ilosc kolumn
		Wiecej informacji pod linkiem: https://media.giphy.com/media/ZxQNtptRbLrdm/giphy.gif
	*/
	
	if(x==NULL) {
		x = (double**) malloc(2*sizeof (double*));
		x[0] = (double*) malloc((k+1)*sizeof (double));
		x[1] = (double*) malloc((k+1)*sizeof (double));
	}else {
		x[0] = realloc(x[0],(k+1)*sizeof (double));
		x[1] = realloc(x[1],(k+1)*sizeof (double));
	}
	
	return x;
}

int main(int argc, char ** argv) {
	double **a;
	int i;
	int n = argc>1 ? atoi(argv[1]) : 10;
	
	
	for(i=0; i<n; i++) {
		a = alloc(a, i);
		a = alloc(a, i);
		a[0][i] = 2*i;
		a[1][i] = 2*i+1;
	}
	
	for(i=0; i<n; i++)
		printf("%g ", a[0][i]);
	printf("\n");
	for(i=0; i<n; i++)
                printf("%g ", a[1][i]);
	printf("\n");
	
	return EXIT_SUCCESS;
}

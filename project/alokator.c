#include <stdio.h>
#include <stdlib.h>

void alloc(double *x, int n) {
	if(n==0) {
		x = malloc(sizeof(double));
	} else {
		void *tmp;
		if((tmp = realloc(x, (n+1)*sizeof(double))) == 0);
			printf("\nMemory allocation error!\n");
	}
}

int main(int argc, char ** argv) {
	double **a;
	int i;
	
	a = malloc(2*sizeof(double*));
	
	for(i=0; i<atoi(argv[1]); i++) {
		alloc(a[0], i);
		alloc(a[1], i);
		a[0][i] = i;
		a[1][i] = i+1;
		printf("%g %g\n", a[0][i], a[1][i]);
	}
	
	return EXIT_SUCCESS;
}

#include "wykreslnik.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void make_plot( char *out, cool_t t) {
	int i;
	char dat_file[7] = "aaaaaaa";
	char dat2_file[7] = "bbbbbbb";
	char cmd_file[7] = "ccccccc";
	mkstemp(dat_file);
	mkstemp(dat2_file);
	mkstemp(cmd_file);
	FILE *tmp1 = fopen(dat_file, "w");	/* pret */
	FILE *tmp2 = fopen(dat2_file, "w");	/* ciecz */
	FILE *cmd = fopen(cmd_file, "w");
	
	for(i=0; i<t->Yc; i++) {
		fprintf(tmp1, "%g %g\n", (double)i*t->dt, t->Y[0][i]);
		fprintf(tmp2, "%g %g\n", (double)i*t->dt, t->Y[1][i]);
	}                                                          
	
	fclose(tmp1);
	fclose(tmp2);
	
	fprintf(cmd, "set terminal png\n");
	fprintf(cmd, "set output '%s'\n", out);
	fprintf(cmd, "plot '%s' with lines t 'temp. preta', '%s' with lines t 'temp. cieczy'\n", dat_file, dat2_file);
	fprintf(cmd, "replot");
	
	fclose(cmd);
	
	execl("/usr/bin/gnuplot", "gnuplot", cmd_file, (char *) NULL);
	
	remove(dat_file);
	remove(dat2_file);
	remove(cmd_file);
}

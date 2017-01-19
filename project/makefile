all :	main.c alloc.c czas.c wykreslnik.c
	gcc -Wall main.c alloc.c czas.c wykreslnik.c

compile : intrp all	

aprox:	libge aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/aproksymator_na_bazie.o aproksymator/gaus/libge.a
	$(CC) -o aproksymator/aprox  aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/aproksymator_na_bazie.o -L aproksymator/gaus -l ge

intrp:	libge aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/interpolator.o aproksymator/gaus/libge.a
	$(CC) -o intrp  aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/interpolator.o -L aproksymator/gaus -l ge

prosta:	aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/prosta.o
	$(CC) -o aproksymator/prosta  aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/ prosta.o	

aproksymator_na_bazie.o:	aproksymator/makespl.h aproksymator/points.h aproksymator/gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator/aproksymator_na_bazie.c

interpolator.o:	aproksymator/makespl.h aproksymator/points.h aproksymator/gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator/interpolator.c

libge:	aproksymator/gaus/matrix.o aproksymator/gaus/pivot.o aproksymator/gaus/piv_ge_solver.o
	ar rvs aproksymator/gaus/libge.a $^

matrix.o:	aproksymator/gaus/matrix.c aproksymator/gaus/matrix.h

pivot.o:	aproksymator/gaus/pivot.c aproksymator/gaus/matrix.h

piv_ge_solver.o:	aproksymator/gaus/piv_ge_solver.c aproksymator/gaus/piv_ge_solver.h aproksymator/gaus/matrix.h

.PHONY: clean

clean:
	-rm aproksymator/gaus/libge.a aproksymator/*.o aproksymator/gaus/*.o

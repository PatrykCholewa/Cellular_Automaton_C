all : main.c alloc.c
	gcc main.c alloc.c

#Nie umie znaleźć libge, choć widzę, że jest libge.a.
aprox: aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/aproksymator_na_bazie.o aproksymator/gaus/libge.a
	$(CC) -o aprox  aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/aproksymator_na_bazie.o -L gaus -l ge

intrp: aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/interpolator.o aproksymator/gaus/libge.a
	$(CC) -o intrp  aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/interpolator.o -L gaus -l ge

prosta: aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/prosta.o
	$(CC) -o prosta  aproksymator/main.o aproksymator/splines.o aproksymator/points.o aproksymator/ prosta.o	

aproksymator_na_bazie.o: aproksymator/makespl.h aproksymator/points.h aproksymator/gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator/aproksymator_na_bazie.c

interpolator.o: aproksymator/makespl.h aproksymator/points.h aproksymator/gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator/interpolator.c

libge: aproksymator/gaus/matrix.o aproksymator/gaus/pivot.o aproksymator/gaus/piv_ge_solver.o
	ar rvs libge.a $^

matrix.o: aproksymator/gaus/matrix.c aproksymator/gaus/matrix.h

pivot.o: aproksymator/gaus/pivot.c aproksymator/gaus/matrix.h

piv_ge_solver.o: aproksymator/gaus/piv_ge_solver.c aproksymator/gaus/piv_ge_solver.h aproksymator/gaus/matrix.h

.PHONY: clean

#Nie działa. Chyba wina tego, że nie umie wejść do folderów.
clean:
	-rm *.o libge.a -l aproksymator aproksymator/gaus	

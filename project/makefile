all :	main.c alloc.c czas.c wykreslnik.c analizator_danych.c bisekcja.c
	gcc -Wall -pedantic main.c alloc.c czas.c wykreslnik.c analizator_danych.c bisekcja.c

compile : splines all	

splines: aproksymator/apr_main.o aproksymator/splines.o aproksymator/points.o libge	
	gcc -o splines aproksymator/apr_main.o aproksymator/splines.o aproksymator/points.o aproksymator/gaus/libge.a 

points.o: aproksymator/points.c aproksymator/points.h

splines.o: aproksymator/splines.c aproksymator/splines.h

apr_main.o: aproksymator/apr_main.c

libge:
	make -C aproksymator/gaus

clean:
	-rm aproksymator/gaus/libge.a aproksymator/*.o aproksymator/gaus/*.o

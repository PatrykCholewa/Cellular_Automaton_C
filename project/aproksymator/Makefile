splines: main.o splines.o points.o libge
	
	gcc -o splines main.o splines.o points.o gaus/libge.a 



points.o: points.c points.h


splines.o: splines.c splines.h


main.o: main.c



.PHONY: clean



clean:
	
	-rm *.o splines gaus/*.o gaus/libge.a



libge:
	make -C gaus


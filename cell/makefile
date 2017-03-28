all : src/main.c src/struct.h src/alloc.o src/gen.o src/life.o src/nbr.o src/bound.o
	gcc -Wall -o cellsim src/main.c src/alloc.o src/gen.o src/life.o src/nbr.o src/bound.o #NIE WIEM, CZY NIE WYSTĄPI PROBLEM PRZY -lpng I OSOBNYM save.o
	mv cellsim ./bin

test : all
	./bin/cellsim ./bin/set.cfg ./bin/map.cfg

src/alloc.o : src/alloc.c src/alloc.h

src/gen.o : src/gen.c src/gen.h

src/save.o : src/save.c src/save.h

src/life.o : src/life.c src/life.h

src/nbr.o : src/nbr.c src/nbr.h

src/bound.o : src/bound.c src/bound.h

.PHONY : clean

clean :
	rm ./src/*.o

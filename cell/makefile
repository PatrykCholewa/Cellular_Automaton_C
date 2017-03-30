all : src/main.c src/struct.h src/alloc.o src/gen.o src/life.o src/nbr.o src/bound.o
	gcc -c src/save.c -lpng
	mv save.o ./src
	gcc -Wall -o cellsim src/main.c src/save.o src/alloc.o src/gen.o src/life.o src/nbr.o src/bound.o -lpng #NIE WIEM, CZY NIE WYSTĄPI PROBLEM PRZY -lpng I OSOBNYM save.o
	mv cellsim ./bin

test : all
	./bin/cellsim ./in/s_glider.cfg ./in/m_glider.cfg
	./bin/cellsim ./in/stdset.cfg ./in/testmap.cfg

src/alloc.o : src/alloc.c src/alloc.h

src/gen.o : src/gen.c src/gen.h

#src/save.o : src/save.c src/save.h

src/life.o : src/life.c src/life.h

src/nbr.o : src/nbr.c src/nbr.h

src/bound.o : src/bound.c src/bound.h

.PHONY : clean

clean :
	rm ./src/*.o

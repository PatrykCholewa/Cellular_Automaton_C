all : src/main.c src/struct.h src/alloc.o src/gen.o src/life.o src/nbr.o src/bound.o src/live.o src/save.c src/save.h
	gcc -c src/save.c -lpng
	mv save.o ./src
	gcc -Wall -o cellsim src/main.c src/save.o src/alloc.o src/gen.o src/life.o src/live.o src/nbr.o src/bound.o -lpng
	mv cellsim ./bin

test : all
	./bin/cellsim ./in/s_glider.cfg ./in/m_glider.cfg
	./bin/cellsim ./in/stdset.cfg ./in/testmap.cfg

src/alloc.o : src/alloc.c src/alloc.h

src/gen.o : srcex/gen.c srcex/gen.h

src/save.o : src/save.c src/save.h

src/life.o : src/life.c src/life.h

src/live.o : src/live.c src/live.h

src/nbr.o : src/nbr.c src/nbr.h

src/bound.o : src/bound.c src/bound.h

.PHONY : clean

clean :
	rm ./src/*.o

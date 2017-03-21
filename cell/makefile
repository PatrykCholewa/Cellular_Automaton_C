all : src/main.c src/struct.h src/alloc.o
	gcc -Wall -o cellsim src/main.c src/alloc.o
	mv cellsim ./bin

test : all
	./bin/cellsim ./bin/map.cfg ./bin/set.cfg

src/alloc.o : src/alloc.c src/alloc.h

.PHONY : clean

clean :
	rm ./src/*.o

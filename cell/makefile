all : src/main.c src/struct.h src/alloc.o src/gen.o
	gcc -Wall -o cellsim src/main.c src/alloc.o src/gen.o
	mv cellsim ./bin

test : all
	./bin/cellsim ./bin/set.cfg ./bin/map.cfg

src/alloc.o : src/alloc.c src/alloc.h

src/gen.o : src/gen.c src/gen.h

src/save.o : src/save.c src/save.h

.PHONY : clean

clean :
	rm ./src/*.o

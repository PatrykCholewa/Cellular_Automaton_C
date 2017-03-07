all : src/main.c src/struct.h src/alloc.o
	gcc -Wall -o cellsim src/main.c src/alloc.o
	cp cellsim ./bin
	rm cellsim

src/alloc.o : src/alloc.c src/alloc.h

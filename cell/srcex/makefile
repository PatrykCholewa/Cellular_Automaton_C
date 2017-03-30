all : main.c struct.h alloc.o gen.o life.o nbr.o bound.o
	gcc -Wall -o cellsim main.c alloc.o gen.o life.o nbr.o bound.o #save.o
	mv cellsim ../bin

test : all
	../bin/cellsim ../in/s_glider.cfg ../in/m_glider.cfg
	../bin/cellsim ../in/stdset.cfg ../in/testmap.cfg

alloc.o : alloc.c alloc.h

save.o : save.c save.h

gen.o : gen.c gen.h

life.o : life.c life.h

nbr.o : nbr.c nbr.h

bound.o : bound.c bound.h

.PHONY : clean

clean :
	rm ./*.o

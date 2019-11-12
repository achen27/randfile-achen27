all: main.o randfile.o
	gcc -o program main.o randfile.o

main.o: main.c randfile.h
	gcc -c main.c randfile.h

randfile.o: randfile.c randfile.h
	gcc -c randfile.c randfile.h

run:
	./program

clean:
	rm *.o
	rm *~

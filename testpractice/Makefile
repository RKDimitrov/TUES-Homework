all: square.out powerOf.out

square.out: square.c
	gcc square.c -o square.out

powerOf.out: powerOf.c maths.o
	gcc powerOf.c maths.o -o powerOf.out

maths.o: maths.c
	gcc -c maths.c -o maths.o

clean:
	rm -f *.o *.out
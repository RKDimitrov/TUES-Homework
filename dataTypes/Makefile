all: clean main.out

main.out: quadraticroots.o main.c
	gcc quadraticroots.o main.c -lm -o main.out 

quadraticroots.o: quadraticroots.h quadraticroots.c
	gcc quadraticroots.c -c -o quadraticroots.o 

clean:
	rm -f *.out *.o
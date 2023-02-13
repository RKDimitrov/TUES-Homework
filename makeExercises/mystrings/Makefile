all: clean helpmenu.out strlenght.out strconcat.out strcompare.out

strconcat.out: strconcat.c mystrings.o
	gcc strconcat.c mystrings.o -o strconcat.out

strlenght.out: strlenght.c mystrings.o
	gcc strlenght.c mystrings.o -o strlenght.out

strcompare.out: strcompare.c mystrings.o
	gcc strcompare.c mystrings.o -o strcompare.out

mystrings.o: mystrings.c mystrings.h
	gcc mystrings.c -c -o mystrings.o

clean:
	rm -f *.out *.o

helpmenu.out:
	gcc helpmenu.c -o helpmenu.out
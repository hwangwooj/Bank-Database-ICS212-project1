project1: stubs.o main.o 
	gcc -o project1 stubs.o main.o

stubs.o: stubs.c
	gcc -ansi -pedantic-errors -Wall -c stubs.c 

main.o: main.c
	gcc -ansi -pedantic-errors -Wall -c main.c

clean : 
	rm *.o project1 records.txt

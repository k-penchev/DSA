all: main.out

main.out: main.c graph.o 
	gcc main.c graph.o -o main.out

graph.o: graph.c
	gcc -c graph.c -o graph.o

clear:
	rm -rf *.o *.out
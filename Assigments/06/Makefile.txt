all: main.out

main.out: main.c heap.o huffman.o 
	gcc main.c heap.o huffman.o -o main.out

heap.o: heap.c
	gcc -c heap.c -o heap.o

huffman.o: huffman.c
	gcc -c huffman.c -o huffman.o 

clear:
	rm -rf *.o *.out
#ifndef HEAP_H
#define HEAP_H

typedef int HeapType;
typedef unsigned int uint;

struct Heap
{
    uint size;
    uint capacity;
    HeapType * buffer;
};

typedef struct Heap Heap;

Heap init();

void push(Heap * heap, HeapType value);
HeapType pop(Heap * heap);
HeapType top(Heap * heap);

int size(Heap * heap);
int empty(Heap * heap);

void clear(Heap * heap);
void destroy(Heap * heap);

#endif

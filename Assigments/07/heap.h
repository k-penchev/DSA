#ifndef HEAP_H
#define HEAP_H

#include "huffman.h"

typedef unsigned int uint;

struct HeapType
{
    BinaryNode * node;
    int key;
};

struct Heap
{
    uint size;
    uint capacity;
    struct HeapType * buffer;
};

typedef struct HeapType HeapType;
typedef struct Heap Heap;

Heap init();

void push(Heap *heap, HeapType value);
HeapType pop(Heap *heap);
HeapType top(Heap *heap);

int size(Heap *heap);
int empty(Heap *heap);

void clear(Heap *heap);
void destroyHeap(Heap *heap);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

typedef unsigned int uint;
typedef int HeapType;

struct Heap
{
    uint size;
    uint capacity;
    HeapType * buffer;
};

typedef struct Heap Heap;

Heap init();

void push(Heap * heap, HeapType v);
HeapType pop(Heap * heap);
HeapType top(Heap * heap);

void destroyHeap();

int main()
{

}
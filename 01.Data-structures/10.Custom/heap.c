#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef unsigned int uint;
typedef int HeapType;

struct Heap
{
    uint size;
    uint capacity;
    HeapType * buffer;
};

typedef struct Heap Heap;

Heap init()
{
    Heap result = 
    {
        .size = 0,
        .capacity = 0,
        .buffer = NULL,
    };

    return result;
}

static void reserve(Heap * heap, uint new_capacity)
{
    if(new_capacity == 0)
    {
        free(heap->buffer);
        heap->buffer = NULL;
        heap->size = 0;
        heap->capacity = 0;
        return;
    }

    HeapType * tmp = realloc(heap->buffer, sizeof(HeapType) * new_capacity);
    assert(tmp != NULL);

    heap->buffer = tmp;
    heap->capacity = new_capacity;

    if(heap->size > heap->capacity)
    {
        heap->size = heap->capacity;
    }
}

static void swap(HeapType * a, HeapType * b)
{
    HeapType t = *a;
    *a = *b;
    *b = t;
}

static void siftUp(Heap * heap, uint idx)
{
    while(idx > 0)
    {
        uint parent = (idx - 1) / 2;
        if(heap->buffer[parent] >= heap->buffer[idx]) break;
        swap(&heap->buffer[parent], &heap->buffer[idx]);
        idx = parent;
    }
}

static void siftDown(Heap * heap, uint idx)
{
    uint n = heap->size;
    while(true)
    {
        uint left = 2 * idx + 1;
        uint right = 2 * idx + 2;
        uint largest = idx;

        if(left < n && heap->buffer[left] > heap->buffer[largest])
        {
            largest = left;
        }

        if(right < n && heap->buffer[right] > heap->buffer[largest])
        {
            largest = right;
        }

        if(largest == idx) break;

        swap(&heap->buffer[idx], &heap->buffer[largest]);
        idx = largest;
    }
}

void push(Heap * heap, HeapType value)
{
    if(heap->size == heap->capacity)
    {
        uint new_capacity = (heap->capacity == 0 ? 1 : heap->capacity * 2);
        reserve(heap, new_capacity);
    }

    heap->buffer[heap->size] = value;
    siftUp(heap, heap->size);
    heap->size += 1;
}

HeapType pop(Heap * heap)
{
    assert(heap->size > 0);

    HeapType result = heap->buffer[0];
    heap->size -= 1;
    if(heap->size > 0)
    {
        heap->buffer[0] = heap->buffer[heap->size];
        siftDown(heap, 0);
    }

    return result;
}

HeapType top(Heap * heap)
{
    assert(heap->size > 0);
    return heap->buffer[0];
}

int empty(Heap * heap)
{
    return (heap->size == 0);
}

void clear(Heap * heap)
{
    free(heap->buffer);
    heap->buffer = NULL;
    heap->size = 0;
    heap->capacity = 0;
}

void destroyHeap(Heap * heap)
{
    free(heap->buffer);
    heap->buffer = NULL;
    heap->size = 0;
    heap->capacity = 0;
}

int main()
{
    Heap heap = init();

    push(&heap, 5);
    push(&heap, 24);
    push(&heap, 7);
    push(&heap, 2);
    push(&heap, 30);
    push(&heap, 17);
    push(&heap, 22);
    push(&heap, 25);

    while(!empty(&heap))
    {
        int v = pop(&heap);
        printf("%d ", v);
    }

    printf("\n");

    destroyHeap(&heap);

    return 0;
}
#include "heap.h"
#include <stdlib.h>
#include <assert.h>

Heap init()
{
    Heap heap =
    {
        .size = 0,
        .capacity = 0,
        .buffer = NULL
    };

    return heap;
}

static void swap(HeapType * a, HeapType * b)
{
    HeapType tmp = *a;
    *a = *b;
    *b = tmp;
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

static void sift_up(Heap * heap, uint index)
{
    while(index > 0)
    {
        uint parent = (index - 1) / 2;

        if(heap->buffer[parent] <= heap->buffer[index]) break;

        swap(&heap->buffer[parent], &heap->buffer[index]);
        index = parent;
    }
}

static void sift_down(Heap * heap, uint index)
{
    while(1)
    {
        uint left = 2 * index + 1;
        uint right = 2 * index + 2;
        uint smallest = index;

        if(left < heap->size && heap->buffer[left] < heap->buffer[smallest])
        {
            smallest = left;
        }

        if(right < heap->size && heap->buffer[right] < heap->buffer[smallest])
        {
            smallest = right;
        }

        if(smallest == index) break;

        swap(&heap->buffer[index], &heap->buffer[smallest]);
        index = smallest;
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
    heap->size += 1;

    sift_up(heap, heap->size - 1);
}

HeapType pop(Heap * heap)
{
    assert(heap->size > 0);

    HeapType result = heap->buffer[0];

    heap->size -= 1;

    if(heap->size > 0)
    {
        heap->buffer[0] = heap->buffer[heap->size];
        sift_down(heap, 0);
    }

    return result;
}

HeapType top(Heap * heap)
{
    assert(heap->size > 0);

    return heap->buffer[0];
}

int size(Heap * heap)
{
    return heap->size;
}

int empty(Heap * heap)
{
    return (heap->size == 0);
}

void clear(Heap * heap)
{
    heap->size = 0;
}

void destroy(Heap * heap)
{
    free(heap->buffer);

    heap->buffer = NULL;
    heap->size = 0;
    heap->capacity = 0;
}

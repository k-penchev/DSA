#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef unsigned int uint;
typedef int VectorType;

struct Vector
{
    uint size;
    uint capacity;
    VectorType * buffer;
};

typedef struct Vector Vector;

Vector init()
{
    Vector v =
    {
        .size = 0,
        .capacity = 0,
        .buffer = NULL
    };

    return v;
}

static void reserve(Vector * v, uint new_capacity)
{
    if(new_capacity == 0)
    {
        free(v->buffer);
        v->buffer = NULL;
        v->size = 0;
        v->capacity = 0;
        return;
    }

    VectorType * tmp = realloc(v->buffer, sizeof(VectorType) * new_capacity);
    assert(tmp != NULL);

    v->buffer = tmp;
    v->capacity = new_capacity;

    if(v->size > v->capacity)
    {
        v->size = v->capacity;
    }
}

void pushBack(Vector * v, VectorType value)
{
    if(v->size == v->capacity)
    {
        uint new_capacity = (v->capacity == 0 ? 1 : v->capacity * 2);
        reserve(v, new_capacity);
    }

    v->buffer[v->size] = value;
    v->size += 1;
}

VectorType popBack(Vector * v)
{
    assert(v->size > 0);
    v->size -= 1;
    return v->buffer[v->size];
}

VectorType back(Vector * v)
{
    assert(v->size > 0);
    return v->buffer[v->size - 1];
}

VectorType at(Vector * v, uint index)
{
    assert(index < v->size);
    return v->buffer[index];
}

void setAt(Vector * v, uint index, VectorType value)
{
    assert(index < v->size);
    v->buffer[index] = value;
}

void insert(Vector * v, uint index, VectorType value)
{
    assert(index <= v->size);

    if(v->size == v->capacity)
    {
        uint new_capacity = (v->capacity == 0 ? 1 : v->capacity * 2);
        reserve(v, new_capacity);
    }

    for(int i = (int)v->size - 1; i >= (int)index; --i)
    {
        v->buffer[i + 1] = v->buffer[i];
    }

    v->buffer[index] = value;
    v->size += 1;
}

void erase(Vector * v, uint index)
{
    assert(index < v->size);

    for(uint i = index; i + 1 < v->size; ++i)
    {
        v->buffer[i] = v->buffer[i + 1];
    }

    v->size -= 1;
}

uint size(Vector * v)
{
    return v->size;
}

uint capacity(Vector * v)
{
    return v->capacity;
}

int empty(Vector * v)
{
    return (v->size == 0);
}

void clear(Vector * v)
{
    v->size = 0;
}

void shrinkToFit(Vector * v)
{
    reserve(v, v->size);
}

void destroyVector(Vector * v)
{
    free(v->buffer);
    v->buffer = NULL;
    v->size = 0;
    v->capacity = 0;
}

int main()
{
    Vector v = init();

    pushBack(&v, 101);
    pushBack(&v, 101);
    pushBack(&v, 102);
    pushBack(&v, 104);

    for(int i = 0 ; i < v.size ; ++i)
    {
        printf("%d ", v.buffer[i]);
    }
    
    return 0;
}
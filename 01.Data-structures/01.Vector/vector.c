#include "vector.h"
#include <stdlib.h>
#include <assert.h>

Vector init()
{
    Vector vec =
    {
        .size = 0,
        .capacity = 0,
        .buffer = NULL
    };

    return vec;
}

static void reserve(Vector * vec, uint new_capacity)
{
    if(new_capacity == 0)
    {
        free(vec->buffer);
        vec->buffer = NULL;
        vec->capacity = 0;
        vec->size = 0;
        return;
    }

    int * tmp = realloc(vec->buffer, sizeof(int) * new_capacity);
    assert(tmp != NULL);

    vec->buffer = tmp;
    vec->capacity = new_capacity;

    if(vec->size > vec->capacity)
    {
        vec->size = vec->capacity;
    }

}

void push_back(Vector * vec, int value)
{
    if(vec->size == vec->capacity)
    {
        uint new_capacity = (vec->capacity == 0 ? 1 : vec->capacity * 2);
        reserve(vec, new_capacity);
    }

    vec->buffer[vec->size] = value;
    vec->size += 1;
}

void pop_back(Vector * vec)
{
    if(vec->size == 0) return;

    vec->size -= 1;
}

int back(Vector * vec)
{
    return vec->buffer[vec->size - 1];
}

int at(Vector * vec, uint index)
{
    return vec->buffer[index];
}

int empty(Vector * vec)
{
    return (vec->size == 0);
}

void clear(Vector * vec)
{
    vec->size = 0;
}

void destroy(Vector * vec)
{
    free(vec->buffer);

    vec->buffer = NULL;
    vec->size = 0;
    vec->capacity = 0;
}

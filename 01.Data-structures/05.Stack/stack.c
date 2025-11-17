#include "stack.h"
#include <stdlib.h>
#include <assert.h>

Stack init()
{
    Stack stack =
    {
        .size = 0,
        .capacity = 0,
        .buffer = NULL
    };

    return stack;
}

static void reserve(Stack * stack, uint new_capacity)
{
    if(new_capacity == 0)
    {
        free(stack->buffer);
        stack->buffer = NULL;
        stack->size = 0;
        stack->capacity = 0;
        return;
    }

    StackType * tmp = realloc(stack->buffer, sizeof(StackType) * new_capacity);
    assert(tmp != NULL);

    stack->buffer = tmp;
    stack->capacity = new_capacity;

    if(stack->size > stack->capacity)
    {
        stack->size = stack->capacity;
    }
}

void push(Stack * stack, StackType value)
{
    if(stack->size == stack->capacity)
    {
        uint new_capacity = (stack->capacity == 0 ? 1 : stack->capacity * 2);
        reserve(stack, new_capacity);
    }

    stack->buffer[stack->size] = value;
    stack->size += 1;
}

StackType pop(Stack * stack)
{
    assert(stack->size > 0);

    stack->size -= 1;
    return stack->buffer[stack->size];
}

StackType top(Stack * stack)
{
    assert(stack->size > 0);

    return stack->buffer[stack->size - 1];
}

int empty(Stack * stack)
{
    return (stack->size == 0);
}

void clear(Stack * stack)
{
    stack->size = 0;
}

void destroy(Stack * stack)
{
    free(stack->buffer);

    stack->buffer = NULL;
    stack->size = 0;
    stack->capacity = 0;
}

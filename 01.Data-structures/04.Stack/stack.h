#ifndef STACK_H
#define STACK_H

typedef int StackType;
typedef unsigned int uint;

struct Stack
{
    uint size;
    uint capacity;
    StackType * buffer;
};

typedef struct Stack Stack;

Stack init();

void push(Stack * stack, StackType value);
StackType pop(Stack * stack);
StackType top(Stack * stack);

int empty(Stack * stack);

void clear(Stack * stack);
void destroy(Stack * stack);

#endif

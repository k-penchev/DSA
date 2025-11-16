#ifndef VECTOR_H
#define VECTOR_H

typedef unsigned int uint;

struct Vector
{
    uint size;
    uint capacity;
    int * buffer;
};

typedef struct Vector Vector;

Vector init();

void push_back(Vector * vec, int value);
void pop_back(Vector * vec);

int back(Vector * vec);
int at(Vector * vec, uint index);
int empty(Vector * vec);

void clear(Vector * vec);
void destroy(Vector * vec);

#endif

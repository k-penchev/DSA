#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef unsigned int uint;

struct Set
{
    uint size;
    int * buffer;
};

typedef struct Set Set;

Set init();

void insert(Set * set, int value);
bool find(Set * set, int value);
bool is_subset(Set * a, Set * b);

Set * set_union(Set * a, Set * b);
Set * set_intersection(Set * a, Set * b);
Set * set_difference(Set * a, Set * b);

void print(Set * set);
void destroy(Set * set);

#endif

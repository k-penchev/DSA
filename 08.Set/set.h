#ifndef SET_H
#define SET_H

typedef int SetType;
typedef unsigned int uint;

struct Set
{
    uint size;
    uint capacity;
    SetType * data;
};

typedef struct Set Set;

Set init();

void insert(Set * set, SetType value);
void erase(Set * set, SetType value);
int contains(Set * set, SetType value);

void printSet(Set * set);
void clear(Set * set);
void destroy(Set * set);

#endif

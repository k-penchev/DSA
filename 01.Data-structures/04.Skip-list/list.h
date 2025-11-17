#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include <stdbool.h>

typedef unsigned int uint;

#define MAX_LEVEL 15

struct Node
{
    int value;
    int level;
    struct Node * pointers[MAX_LEVEL];
};

struct SkipList
{
    uint size;
    struct Node * head;
};

typedef struct Node Node;
typedef struct SkipList SkipList;

Node * create(int value, int level);

SkipList init();

void insert(SkipList * list, int value);

void erase(SkipList * list, int value);

bool search(SkipList * list, int value);

void print(SkipList * list);

void clear(SkipList * list);

#endif
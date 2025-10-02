#ifndef LIST_H
#define LIST_H

typedef int ListType;
typedef unsigned int uint;

struct Node
{
    struct Node * next;
    ListType value;
};

typedef struct Node Node;

void push(Node ** head, uint index, ListType value);
void pushBack(Node ** head, ListType value);
void pushFront(Node ** head, ListType value);

void pop(Node ** head, uint index);
void popFront(Node ** head);
void popBack(Node ** head);

void print(Node ** head);

#endif
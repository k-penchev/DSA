#ifndef LIST_H
#define LIST_H

typedef int ListType;
typedef unsigned int uint;

struct Node
{
    ListType value;
    struct Node * next;
    struct Node * prev;
};

struct LinkedList
{
    uint size;
    struct Node * head;
    struct Node * tail;
};

typedef struct Node Node;
typedef struct LinkedList LinkedList;

LinkedList init();

void pushBack(LinkedList * list, ListType value);
void pushFront(LinkedList * list, ListType value);
void push(LinkedList * list, uint index, ListType value);

ListType popBack(LinkedList * list);
ListType popFront(LinkedList * list);
ListType pop(LinkedList * list, uint index);

void printForward(LinkedList * list);
void printReverse(LinkedList * list);

void destroy(LinkedList * list);

#endif
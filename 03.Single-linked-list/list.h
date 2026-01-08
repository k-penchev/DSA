#ifndef LIST_H
#define LIST_H

typedef int ListType;
typedef unsigned int uint;

struct Node
{
    ListType value;
    struct Node * next;
};

struct LinkedList
{
    struct Node * head;
    uint size;
};

typedef struct Node Node;
typedef struct LinkedList LinkedList;

LinkedList init();

Node * getNode(LinkedList * list, uint index);
ListType * getNodeValue(LinkedList * list, uint index);

void pushBack(LinkedList * list, ListType value);
void pushFront(LinkedList * list, ListType value);
void push(LinkedList * list, uint index, ListType value);

ListType popBack(LinkedList * list);
ListType popFront(LinkedList * list);
ListType pop(LinkedList * list, uint index);

void destroy(LinkedList * list);
void print(LinkedList * list);

#endif
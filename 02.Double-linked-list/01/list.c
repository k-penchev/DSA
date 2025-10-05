#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LinkedList init()
{
    LinkedList list = {
        .head = NULL,
        .tail = NULL,
        .size = 0,
    };

    return list;
}

static Node * createNode(ListType value)
{   
    Node * newNode = malloc(sizeof(Node));
    assert(newNode != NULL);

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->value = value;

    return newNode;
}


void pushFront(LinkedList * list, ListType value)
{
    Node * newNode = createNode(value);

    newNode->next = list->head;
    //newNode->prev = NULL;

    list->head->prev = newNode;

    list->head = newNode;
};

void pushBack(LinkedList * list, ListType value)
{
    Node * newNode = createNode(value);

    newNode->prev = list->tail;
    //newNode->next = NULL;

    list->tail->next = newNode;

    list->tail = newNode;
}

void push(LinkedList * list, uint index, ListType value)
{
    if(index == 0)
    {
        pushFront(list, value);
        return;
    }

    Node * newNode = createNode(value);
    
}


ListType popBack(LinkedList * list);
ListType popFront(LinkedList * list);
ListType pop(LinkedList * list, uint index);

void traverseForward(LinkedList * list);
void traverseReverse(LinkedList * list);

void destroy(LinkedList * list);

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList init()
{
    LinkedList list = {
        .head = NULL,
        .size = 0,
    };

    return list;
}

static Node * createNode(ListType value)
{
    Node * newNode = malloc(sizeof(Node));

    if(newNode == NULL)
    {
        printf("Error allocating memory!");
        exit(0);
    }

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};


static Node * getNode(LinkedList * list, uint index)
{
    Node * current = list->head;

    for(int i = 0  ; i < index ; ++i)
    {
        current = current->next;
    }

    return current;
}

void pushFront(LinkedList * list, ListType value)
{
    Node * newNode = createNode(value);

    newNode->next = list->head;
    list->head = newNode;
    list->size++;
};


void push(LinkedList * list, uint index, ListType value)
{
    if(index > list->size)
    {
        printf("Index out of bounds!");
        exit(0);
    }

    if(index == 0)
    {
        pushFront(list, value);
        return;
    }

    Node * prev = getNode(list, index - 1);
    Node * newNode = createNode(value);
    
    newNode->next = prev->next;
    prev->next = newNode;
    list->size++;
};

void pushBack(LinkedList * list, ListType value)
{
    push(list, list->size, value);
}

ListType popFront(LinkedList * list)
{
    Node * current = list->head;
    list->head = current->next;

    ListType result = current->value;  
    free(current);

    list->size--;
    return result;
};

ListType pop(LinkedList * list, uint index)
{
    if(index < 0)
    {
        printf("Index out of bounds!");
        exit(0);
    }

    if(index == 0)
    {
        return popFront(list);
    }

    Node * prev = getNode(list, index - 1);
    Node * toDelete = getNode(list, index);

    prev->next = toDelete->next;
    ListType result = toDelete->value;

    free(toDelete);
    list->size--;

    return result;
}

ListType popBack(LinkedList * list)
{
    return pop(list, list->size - 1);
}

void destroy(LinkedList * list)
{
    while(list->size)
    {
        popFront(list);
    }
}


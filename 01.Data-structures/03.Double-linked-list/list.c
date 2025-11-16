#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LinkedList init()
{
    LinkedList list =
    {
        .head = NULL,
        .tail = NULL,
        .size = 0
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

static Node * getNode(LinkedList * list, uint index)
{
    assert(index < list->size);

    if(index <= list->size / 2)
    {
        Node * curr = list->head;
        for(uint i = 0 ; i < index ; ++i)
        {
            curr = curr->next;
        }

        return curr;
    }
    else
    {
        Node * curr = list->tail;
        for(uint i = list->size - 1 ; i > index ; --i)
        {
            curr = curr->prev;
        }

        return curr;
    }
}

void pushFront(LinkedList * list, ListType value)
{
    Node * newNode = createNode(value);

    if(list->size == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }

    list->size += 1;
}

void pushBack(LinkedList * list, ListType value)
{
    Node * newNode = createNode(value);

    if(list->size == 0)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size += 1;
}

void push(LinkedList * list, uint index, ListType value)
{
    assert(index <= list->size);

    if(index == 0)
    {
        pushFront(list, value);
        return;
    }

    if(index == list->size)
    {
        pushBack(list, value);
        return;
    }

    Node * nextNode = getNode(list, index);
    Node * prevNode = nextNode->prev;

    Node * newNode = createNode(value);

    newNode->next = nextNode;
    newNode->prev = prevNode;

    prevNode->next = newNode;
    nextNode->prev = newNode;

    list->size += 1;
}

ListType popFront(LinkedList * list)
{
    assert(list->size > 0);

    Node * oldHead = list->head;
    ListType value = oldHead->value;

    if(list->size == 1)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = oldHead->next;
        list->head->prev = NULL;
    }

    free(oldHead);
    list->size -= 1;

    return value;
}

ListType popBack(LinkedList * list)
{
    assert(list->size > 0);

    Node * oldTail = list->tail;
    ListType value = oldTail->value;

    if(list->size == 1)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->tail = oldTail->prev;
        list->tail->next = NULL;
    }

    free(oldTail);
    list->size -= 1;

    return value;
}

ListType pop(LinkedList * list, uint index)
{
    assert(index < list->size);

    if(index == 0)
    {
        return popFront(list);
    }

    if(index == list->size - 1)
    {
        return popBack(list);
    }

    Node * node = getNode(list, index);
    Node * prevNode = node->prev;
    Node * nextNode = node->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    ListType value = node->value;
    free(node);

    list->size -= 1;

    return value;
}

void printForward(LinkedList * list)
{
    Node * curr = list->head;

    while(curr != NULL)
    {
        printf("%d ", curr->value);
        curr = curr->next;
    }

    printf("\n");
}

void printReverse(LinkedList * list)
{
    Node * curr = list->tail;

    while(curr != NULL)
    {
        printf("%d ", curr->value);
        curr = curr->prev;
    }

    printf("\n");
}

void destroy(LinkedList * list)
{
    Node * curr = list->head;

    while(curr != NULL)
    {
        Node * next = curr->next;
        free(curr);
        curr = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

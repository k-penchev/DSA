#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>

static Node * createNode(ListType value)
{
    Node * newNode = malloc(sizeof(Node));

    newNode->next = NULL;
    newNode->value = value;
    
    return newNode;
}

void pushFront(Node ** head, ListType value)
{
    Node * newNode = createNode(value);

    newNode->next = *head;
    *head = newNode;
}

void push(Node ** head, uint index, ListType value)
{
    if(index == 0)
    {
        pushFront(head, value);
        return;
    }

    Node * prev = *head;
    for(int i = 0 ; i < index - 1 && prev != NULL ; ++i)
    {
        prev = prev->next;
    }

    if(prev == NULL) exit(EXIT_FAILURE);

    Node * newNode = createNode(value);

    newNode->next = prev->next;
    prev->next = newNode;
}

void pushBack(Node ** head, ListType value)
{
    Node * newNode = createNode(value);

    if(*head == NULL) //no nodes in the list
    {
        *head = newNode;
        return;
    }

    Node * prev = *head;
    while(prev->next != NULL) //at least one node in the list
    {
        prev = prev->next;
    }

    prev->next = newNode;
}

void popFront(Node ** head)
{
    if(*head == NULL) return;

    Node * delNode = *head;
    *head = delNode->next;

    free(delNode);
}

void pop(Node ** head, uint index)
{
    if(*head == NULL) return;

    if(index == 0)
    {
        popFront(head);
        return;
    }

    Node * prev = *head;
    for(int i = 0 ; i < index - 1 && prev != NULL; ++i)
    {
        prev = prev->next;
    }


    if(prev == NULL || prev->next == NULL) exit(EXIT_FAILURE);

    Node * delNode = prev->next;
    prev->next = delNode->next;
    free(delNode);
}

void popBack(Node ** head)
{
    if(*head == NULL) return;

    Node * prev = *head;

    if(prev->next == NULL) //only one node in the list
    {
        free(prev);
        *head = NULL;
        return;
    }

    while(prev->next->next != NULL) //at least two nodes in the list
    {
        prev = prev->next;
    }

    Node * delNode = prev->next;
    free(delNode);
    prev->next = NULL;
}

void print(Node ** head)
{
    Node * current = *head;

    while(current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("\n");
}

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

LinkedList init()
{
    LinkedList list =
    {
        .head = NULL,
        .size = 0,
    };

    return list;
}

static Node * createNode(ListType value)
{
    Node * newNode = malloc(sizeof(Node));
    assert(newNode != NULL);
    
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

Node * getNode(LinkedList * list, uint index)
{
    if(index > list->size) return NULL;

    Node * current = list->head;

    for(int i = 0  ; i < index ; ++i)
    {
        current = current->next;
    }

    return current;
}

ListType * getNodeValue(LinkedList * list, uint index)
{
    Node * node = getNode(list, index);
    if(node == NULL)
    {
        printf("Index out of bounds!\n");
        exit(EXIT_FAILURE);
    }

    return &(node->value);
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
        printf("Index out of bounds!\n");
        exit(EXIT_FAILURE);
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
    if(list->head == NULL)
    {
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }

    Node * current = list->head;
    list->head = current->next;

    ListType result = current->value;
    free(current);

    list->size--;
    return result;
};

ListType pop(LinkedList * list, uint index)
{
    if(list->head == NULL)
    {
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }

    if(index >= list->size)
    {
        printf("Index out of bounds!\n");
        exit(EXIT_FAILURE);
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
    if(list->size == 0)
    {
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }

    return pop(list, list->size - 1);
}

void destroy(LinkedList * list)
{
    while(list->size)
    {
        popFront(list);
    }
}

void print(LinkedList * list)
{
    Node * current = list->head;

    for(int i = 0 ; i < list->size ; ++i)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

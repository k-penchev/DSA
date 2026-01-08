#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

Node * create(int value, int level)
{
    Node * res = malloc(sizeof(Node));
    assert(res != NULL);

    res->value = value;
    res->level = level;
    for(int i = 0 ; i < MAX_LEVEL ; ++i)
    {
        res->pointers[i] = NULL;
    }

    return res;
}

SkipList init()
{
    SkipList list =
    {
        .size = 0,
        .head = create(0, MAX_LEVEL)   
    };

    return list;
}

void insert(SkipList * list, int value)
{
    Node * update[MAX_LEVEL];
    Node * current = list->head;

    for(int lvl = MAX_LEVEL - 1 ; lvl >= 0 ; --lvl)
    {
        while(current->pointers[lvl] && current->pointers[lvl]->value < value)
        {
            current = current->pointers[lvl];
        }
        update[lvl] = current;
    }

    current = current->pointers[0];   

    int lvl = rand() % MAX_LEVEL;
    Node * new_node = create(value, lvl);

    for(int i = 0 ; i < lvl ; ++i)
    {
        new_node->pointers[i] = update[i]->pointers[i];
        update[i]->pointers[i] = new_node;
    }

    list->size++;
}

void erase(SkipList * list, int value)
{
    Node * update[MAX_LEVEL];
    Node * current = list->head;

    for(int lvl = MAX_LEVEL - 1 ; lvl >= 0 ; --lvl)
    {
        while(current->pointers[lvl] && current->pointers[lvl]->value < value)
        {
            current = current->pointers[lvl];
        }
        update[lvl] = current;
    }

    current = current->pointers[0];

    for(int i = 0 ; i < current->level ; ++i)
    {
        if(update[i]->pointers[i] == current)
        {
            update[i]->pointers[i] = current->pointers[i];
        }
    }

    free(current);
    list->size--;
}

bool search(SkipList * list, int value)
{
    Node * current = list->head;

    for(int lvl = MAX_LEVEL - 1 ; lvl >= 0 ; --lvl)
    {
        while(current->pointers[lvl] && current->pointers[lvl]->value < value)
        {
            current = current->pointers[lvl];
        }
    }

    current = current->pointers[0];
    return current && current->value == value;
}

void print(SkipList * list)
{
    for(int lvl = MAX_LEVEL - 1 ; lvl >= 0 ; --lvl)
    {
        
        
    }
}

void clear(SkipList * list)
{
    
}

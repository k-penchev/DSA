#include "set.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

Set init()
{
    Set new_set =
    {
        .size = 0,
        .buffer = NULL
    };

    return new_set;
}

static void resize(Set * set, int new_size)
{
    if(new_size == 0)
    {
        free(set->buffer);
        set->buffer = NULL;
        return;
    }

    int * tmp = realloc(set->buffer, sizeof(int) * new_size);
    
    set->buffer = tmp;
}

static int lower_bound(Set * set, int value)
{
    if(set->size == 0) return 0;

    int l = -1, r = set->size;
    
    while(l + 1 < r)
    {
        int m = (l + r) / 2;

        if(set->buffer[m] >= value) r = m;
        else l = m;
    }

    return r;
}

int find(Set * set, int value)
{
    if(set->size == 0) return 0;
    
    int index = lower_bound(set, value);
    return(index < set->size && set->buffer[index] == value);
}

void push(Set * set, int value)
{
    if(find(set, value)) return;

    int i = lower_bound(set, value);

    set->size += 1;
    resize(set, set->size);

    for(int j = set->size - 1; j > i; --j)
    {
        set->buffer[j] = set->buffer[j - 1];
    }

    set->buffer[i] = value;
}

int is_subset(Set * a, Set * b)
{
    for(int i = 0 ; i < b->size ; ++i)
    {
        if(!find(a, b->buffer[i])) return 0;
    }

    return 1;
}

Set * set_union(Set * a, Set * b)
{
    Set * c = malloc(sizeof(Set));

    for(int i = 0 ; i < a->size ; ++i)
    {
        push(c, a->buffer[i]);
    }

    for(int i = 0 ; i < b->size ; ++i)
    {
        push(c, b->buffer[i]);
    }

    return c;
}

Set * set_intersection(Set * a, Set * b)
{
    Set * c = malloc(sizeof(Set));

    for(int i = 0 ; i < a->size ; ++i)
    {
        if(find(b, a->buffer[i]))
        {
            push(c, a->buffer[i]);
        }
    }

    return c;
}

Set * set_difference(Set * a, Set * b)
{
    Set * c = malloc(sizeof(Set));

    for(int i = 0 ; i < a->size ; ++i)
    {
        if(!find(b, a->buffer[i]))
        {
            push(c, a->buffer[i]);
        }
    }

    return c;
}

void print(Set * set)
{
    for(int i = 0; i < set->size; ++i)
    {
        printf("%d ", set->buffer[i]);
    }

    printf("\n");
}

void destroy(Set * set)
{
    free(set->buffer);
    
    set->buffer = NULL;
    set->size = 0;
}

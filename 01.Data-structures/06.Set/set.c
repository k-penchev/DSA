#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

Set init()
{
    Set set =
    {
        .size = 0,
        .capacity = 0,
        .data = NULL
    };

    return set;
}

static void reserve(Set * set, uint new_capacity)
{
    if(new_capacity == 0)
    {
        free(set->data);
        set->data = NULL;
        set->capacity = 0;
        set->size = 0;
        return;
    }

    SetType * tmp = realloc(set->data, sizeof(SetType) * new_capacity);
    assert(tmp != NULL);

    set->data = tmp;
    set->capacity = new_capacity;

    if(set->size > set->capacity)
    {
        set->size = set->capacity;
    }
}

static int lower_bound(Set * set, SetType value)
{
    int l = -1;
    int r = set->size;

    while(l < r)
    {
        int m = (l + r) / 2;

        if(set->data[m] >= value) r = m;
        else l = m;
    }

    return r;
}

int contains(Set * set, SetType value)
{
    if(set->size == 0) return 0;

    int pos = lower_bound(set, value);

    return (pos < set->size && set->data[pos] == value);
}

void insert(Set * set, SetType value)
{
    int pos = lower_bound(set, value);

    if(pos < (int)set->size && set->data[pos] == value) return;

    if(set->size == set->capacity)
    {
        uint new_capacity = (set->capacity == 0 ? 1 : set->capacity * 2);
        reserve(set, new_capacity);
    }

    for(int i = (int)set->size ; i > pos ; --i)
    {
        set->data[i] = set->data[i - 1];
    }

    set->data[pos] = value;
    set->size += 1;
}

void erase(Set * set, SetType value)
{
    if(set->size == 0) return;

    int pos = lower_bound(set, value);

    if(pos >= (int)set->size || set->data[pos] != value) return;

    for(uint i = pos + 1 ; i < set->size ; ++i)
    {
        set->data[i - 1] = set->data[i];
    }

    set->size -= 1;
}

void printSet(Set * set)
{
    for(uint i = 0 ; i < set->size ; ++i)
    {
        printf("%d ", set->data[i]);
    }

    printf("\n");
}

void clear(Set * set)
{
    set->size = 0;
}

void destroy(Set * set)
{
    free(set->data);

    set->data = NULL;
    set->size = 0;
    set->capacity = 0;
}

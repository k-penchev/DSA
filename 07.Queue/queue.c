#include "queue.h"
#include <stdlib.h>
#include <assert.h>

Queue init()
{
    Queue queue =
    {
        .size = 0,
        .capacity = 0,
        .head = 0,
        .tail = 0,
        .buffer = NULL
    };

    return queue;
}

static void reserve(Queue * queue, uint new_capacity)
{
    if(new_capacity == 0)
    {
        free(queue->buffer);
        queue->buffer = NULL;
        queue->capacity = 0;
        queue->size = 0;
        queue->head = 0;
        queue->tail = 0;
        return;
    }

    QueueType * tmp = malloc(sizeof(QueueType) * new_capacity);
    assert(tmp != NULL);

    /* copy existing elements in logical order: front -> back */
    for(uint i = 0 ; i < queue->size && i < new_capacity ; ++i)
    {
        tmp[i] = queue->buffer[(queue->head + i) % (queue->capacity == 0 ? 1 : queue->capacity)];
    }

    free(queue->buffer);
    queue->buffer = tmp;

    if(queue->size > new_capacity)
    {
        queue->size = new_capacity;
    }

    queue->capacity = new_capacity;
    queue->head = 0;
    queue->tail = queue->size;
}

void push(Queue * queue, QueueType value)
{
    if(queue->size == queue->capacity)
    {
        uint new_capacity = (queue->capacity == 0 ? 1 : queue->capacity * 2);
        reserve(queue, new_capacity);
    }

    queue->buffer[queue->tail] = value;
    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size += 1;
}

QueueType pop(Queue * queue)
{
    assert(queue->size > 0);

    QueueType value = queue->buffer[queue->head];
    queue->head = (queue->head + 1) % queue->capacity;
    queue->size -= 1;

    return value;
}

QueueType front(Queue * queue)
{
    assert(queue->size > 0);

    return queue->buffer[queue->head];
}

int empty(Queue * queue)
{
    return (queue->size == 0);
}

void clear(Queue * queue)
{
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;
}

void destroy(Queue * queue)
{
    free(queue->buffer);

    queue->buffer = NULL;
    queue->size = 0;
    queue->capacity = 0;
    queue->head = 0;
    queue->tail = 0;
}

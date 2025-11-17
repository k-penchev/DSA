#ifndef QUEUE_H
#define QUEUE_H

typedef int QueueType;
typedef unsigned int uint;

struct Queue
{
    uint size;
    uint capacity;
    uint head;
    uint tail;
    QueueType * buffer;
};

typedef struct Queue Queue;

Queue init();

void push(Queue * queue, QueueType value);
QueueType pop(Queue * queue);
QueueType front(Queue * queue);

int empty(Queue * queue);

void clear(Queue * queue);
void destroy(Queue * queue);

#endif

#include "graph.h"
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

struct Queue
{
    int * items;
    int front;
    int rear;
    int size;
};

typedef struct Queue Queue;

Queue * createQueue(int size)
{
    Queue * q = malloc(sizeof(Queue));
    q->items = malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue * q, int value)
{
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue * q)
{
    return q->items[q->front++];
}

bool isEmpty(Queue * q)
{
    return q->front > q->rear;
}

void bfs(Graph * graph, int node, bool * visited)
{
    Queue * q = createQueue(graph->nodes);
    enqueue(q, node);
    visited[node] = true;

    while(!isEmpty(q))
    {
        int current = dequeue(q);
        printf("%d\n", current);

        for(Node * cur = graph->array[current] ; cur != NULL ; cur = cur->next)
        {
            int to = cur->dest;
            if(!visited[to])
            {
                visited[to] = true;
                enqueue(q, to);
            }
        }
    }

    free(q->items);
}

void dfs(Graph * graph, int node, bool * visited)
{
    printf("%d\n", node);

    visited[node] = true;

    for(Node * cur = graph->array[node] ; cur != NULL ; cur = cur->next)
    {
        int to = cur->dest;

        if(!visited[to]) 
        {
            dfs(graph, to, visited);
        }
    }
}


int main()
{
    int n, m;
    
    FILE * file = fopen("./graph.txt", "r+");
    fscanf(file, "%d %d", &n, &m);

    Graph * graph = createGraph(n);

    for(int i = 0 ; i < m ; ++i)
    {
        int u, v;
        fscanf(file, "%d %d", &u, &v);

        addDirectedEdge(graph, u, v);
        addDirectedEdge(graph, v, u);
    }
    
    bool * vis;
    //printGraph(graph);

    printf("DFS\n");
    vis = calloc(graph->nodes, sizeof(bool));
    dfs(graph, 5, vis);

    printf("BFS\n");
    vis = calloc(graph->nodes, sizeof(bool));
    bfs(graph, 5, vis);

    fclose(file);
    return 0;
}
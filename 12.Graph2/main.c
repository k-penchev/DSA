#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    Graph * graph = createGraph(6);

    addEdge(graph,0,1,4);
    addEdge(graph,0,2,2);
    addEdge(graph,1,3,5);
    addEdge(graph,2,1,1);
    addEdge(graph,2,3,8);
    addEdge(graph,2,4,10);
    addEdge(graph,3,4,2);
    addEdge(graph,3,5,6);
    addEdge(graph,4,5,3);

    int pathSize;

    int * path = dijkstra(graph,0,5,&pathSize);

    for(int i = 0 ; i < pathSize ; ++i)
    {
        printf("%d ",path[i]);
    }
    printf("\n");

    free(path);

    int h[6] = {0,0,0,0,0,0};

    int * path2 = astar(graph,0,5,h,&pathSize);

    for(int i = 0 ; i < pathSize ; ++i)
    {
        printf("%d ",path2[i]);
    }
    printf("\n");

    free(path2);

    return 0;
}
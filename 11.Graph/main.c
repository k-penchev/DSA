#include "graph.h"

int main()
{
    Graph * graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);

    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    addEdge(graph, 3, 4);

    addEdge(graph, 4, 1);
    
    printGraph(graph);

    return 0;
}
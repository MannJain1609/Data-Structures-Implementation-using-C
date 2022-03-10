#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int main()
{
	int v=5;
	struct graph *g1 = create_graph(v);
	addEdge(g1, 0, 1);
	PrintGraph(g1);
    addEdge(g1, 0, 4);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 1, 4);
    addEdge(g1, 2, 3);
    addEdge(g1, 3, 4);
 
    PrintGraph(g1);
	return 0;
}
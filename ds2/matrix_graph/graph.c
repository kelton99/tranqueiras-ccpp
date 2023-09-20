#include <stdlib.h>
#include "graph.h"

graph *create(int n)
{
	graph *g = malloc(sizeof(graph));
	g->n = n;
	g->matrix = calloc(n, sizeof(int*));
	int i;
	for(i = 0; i < n; i++)
		g->matrix[i] = calloc(n, sizeof(int));
	
	return g;
}

void add_vertex(graph *g, int n1, int n2)
{
	g->matrix[n1][n2] = 1;
	g->matrix[n2][n2] = 1;
}

void depth_first(graph *g, int start, int *visited_nodes)
{
	printf("%d ", start);
	visited_nodes[start] = 1;
	for(int i = 0; i < g->n; i++)
		if(g->matrix[start][i] == 1 && (!visited_nodes[i]))
			depth_first(g, i, visited_nodes);
}

int is_connected(graph *g)
{
	int *visited = calloc(g->n, sizeof(int));
    
	depth_first(g, 0, visited);
    
	int count = 0;
	for(int i = 0; i < n; i++)
		if(visited[i])
			count++;
        
	if(g->n == count) {
		puts("The graph is connected");
		return 1;
	}

	puts("The graph isn't connected");
	return 0;
}

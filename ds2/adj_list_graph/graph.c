#include "graph.h"

graph *create(int n)
{
	graph *g = malloc(sizeof(graph));
	g->n = n;
	g->list = calloc(n, sizeof(vertex));
	return g;
}

int count_edges(graph *g)
{
	int result = 0;
	int i;
	for(i = 0; i < g->n; i++) {
		vertex *aux = g->list[i];
		while(aux != NULL) {
			result++;
			aux = aux->neighbors;
		}
	}
	return result;
}

vertex *highest_order(graph *g)
{
	vertex *highest;
	int biggest_count = 0;
	int i;
	for(i = 0; i < g->n; i++) {
		int neighbor_count = 0;
		vertex *aux = g->list[i];
		while(aux != NULL) {
			neighbor_count++;
			aux = aux->neighbors;
		}
		if(!(neighbor_count < biggest_count)) {
			highest = g->list[i];
			biggest_count = neighbor_count;
		}
	}
	return highest;
}

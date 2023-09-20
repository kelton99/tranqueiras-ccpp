typedef struct graph {
	int n;
	int **matrix;
} graph;

graph *create(int n);

void add_vertex(graph *g, int n1, int n2);

void depth_first(graph *g, int start, int *visited_nodes);


int sum_agm(graph *g, int *parent)
{
	int result = 0;
	int i;
	
	for(i = 0; i < g->n; i++)
		result += matriz[i][parent[i]];
	return result;
}

int contains(int *s, int s_size, int num)
{
	int i;
	for(i = 0; i < s_size; i++)
		if(s[i] == num)
			return 1;
	return 0;
}

int smallest_edge(graph *g, int *s)
{
	int result = 2147483647;// max int
	int i;
	int s_size = sizeof(s) / sizeof(int);
	
	
	for(i = 0; i < s_size; i++) {
		int j;
		for(j = 0; j < g->n; j++) {
			if(g->matrix[s_size[i]][j] != 0 && g->matrix[s_size[i]][j] < result && !contains(s, s_size, j)
				result = g->matrix[s_size[i]][j];
		}
	}
	
	return result;
}

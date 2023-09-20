typedef struct vertex vertex;

struct vertex {
	int v;
	vertex *neighbors;
};

typedef struct graph {
	int n;
	vertex **list;
} graph;


graph *create(int n);

int count_edges(graph *g);

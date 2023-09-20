
typedef struct ntree ntree;

struct ntree {
	int value;
	int qtd;
	ntree **children;
};

ntree *create_ntree(int value, int children_qtd);

void pre_order(ntree *n);
void symetric(ntree *n);
void pos_order(ntree *n);
int largest(ntree *t);

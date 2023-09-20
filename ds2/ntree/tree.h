#include <stdlib.h>

typedef struct tree tree;

struct tree {
	int value;
	tree *left; 
	tree *right;
};

tree *create_tree(int value);

void pre_order_search(tree *t);
void symetric_search(tree *t);
void pos_order_search(tree *t);
int sum_odd(tree *t);

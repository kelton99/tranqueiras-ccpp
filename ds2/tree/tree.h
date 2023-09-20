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
void insert_left(tree *t, int value);

int sum_tree(tree *t);
int sum_odd(tree *t);
int count_repetition(tree *t, int value);
int is_equal(tree *t, tree *t2);

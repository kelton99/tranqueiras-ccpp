#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree *create_tree(int value)
{
	tree *t = calloc(1, sizeof(tree));
	t->value = value;
	return t;	
}

void pre_order_search(tree *t)
{
	printf("%d\n", t->value);
	if(t->left != NULL) pre_order_search(t->left);
	if(t->right != NULL) pre_order_search(t->right);
}

void symetric_search(tree *t)
{
	if(t->left != NULL) symetric_search(t->left);
	printf("%d\n", t->value);
	if(t->right != NULL) symetric_search(t->right);
}

void pos_order_search(tree *t)
{
	if(t->left != NULL) pos_order_search(t->left);
	if(t->right != NULL) pos_order_search(t->right);
	printf("%d\n", t->value);
}

int sum_odd(tree *t)
{
    int lsum = 0, rsum = 0;
	if (t->left != NULL)
		lsum = sum_odd(t->left);
	if (t->right != NULL)
		rsum = sum_odd(t->right);
    
    if(t->value % 2 != 0)
        return lsum + rsum + t->value;
    return lsum + rsum;
}

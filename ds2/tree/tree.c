#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree *create_tree(int value)
{
	tree *t = calloc(1, sizeof(tree));
	t->value = value;
	return t;	
}

void insert_left(tree *t, int value)
{
	while(t->left != NULL)
		t = t->left;
	t->left = create_tree(value);
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
	if(t == NULL)
		return 0;
	return sum_odd(t->left) + sum_odd(t->right) + (t->value % 2) * t->value;
}

int count_rep(tree *t, int value)
{
	if(t == NULL)
		return 0;
	return count_rep(t->left, value) + count_rep(t->right, value) + (t->value == value);
}

int is_equal(tree *t, tree *t2)
{
	
	if(t->left != NULL && t2->left != NULL) {
		if(t->left->value == t2->left->value)
			return is_equal(t->left, t2->left);
	}
	
	if(t->right != NULL && t2->right != NULL) {
		if(t->right->value == t2->right->value)
			return is_equal(t->right, t2->right);
	}
	
	return 1;
}

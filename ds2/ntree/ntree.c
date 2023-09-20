#include "ntree.h"
#include <stdlib.h>

ntree *create_ntree(int value, int children_qtd)
{

	ntree *n = calloc(1, sizeof(ntree));
	n->qtd = children_qtd;
	n->value = value;

	if (children_qtd > 0)
		n->children = calloc(children_qtd, sizeof(ntree *));
	else
		n->children = NULL;

	return n;
}
/*
void pre_order(ntree *t)
{
	printf("%d\n", t->value);
	int i;
	for (i = 0; i < t->qtd; i++)
		if (t->children[i] != NULL)
			pre_order(t->children[i]);
}

void post_order(ntree *t)
{
	int i;
	for(i = 0; i < t->qtd; i++)
		if(t->children[i] != NULL) post_order(t->children[i]);
	
	printf("%d\n", t->value);	
}

void symetric(ntree *t)
{
	int i;
	for(i = 0; i < t->qtd / 2; i++)
		if(t->children[i] != NULL) post_order(t->children[i]);
	
	printf("%d\n", t->value);
	for (i = t->qtd / 2; i < t->qtd; i++)
		if(t->children[i] != NULL) post_order(t->children[i]);
}
*/
int largest(ntree *t)
{
	int max = t->value;
	int i;
	
	if(t->children != NULL) {
		for(i = 0; i < t->qtd; i++) {
			if(t->children[i] != NULL){
				int max_next = largest(t->children[i]);
				if(max_next > max)
					max = max_next;
			}
		}
	}
	
	return max;
}

int count_less(tree *t, int value)
{
	if(t == NULL)
		return 0;
	return count_less(t->left, value) + count_less(t->right, value) + (t->value < value);
}


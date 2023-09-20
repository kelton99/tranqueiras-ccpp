#include <stdio.h>
#include <stdlib.h>
#include "ntree.h"

/*
int sum_tree(tree *t)
{
	int lsum = 0, rsum = 0;
	if (t->left != NULL)
		lsum = sum(t->left);
	if (t->right != NULL)
		rsum = sum(t->right);
	return lsum + rsum + t->value;
}


int sum_ntree(ntree *n)
{
	int i, sum = 0;

	for (i = 0; i < n->qtd; i++)
	{
		if (n->children[i] != NULL)
			sum += sum_ntree(n->children[i]);
	}

	return sum + n->value;
}

void add_to_all(ntree *n, value)
{
	int i;

	for (i = 0; i < n->qtd; i++)
		if (n->children[i] != NULL)
			n->children[i] += value;
}

int tree_height(tree *t)
{
	int lefth = 0;
	int righth = 0;

	if (t->left != NULL)
		lefth = tree_height(t->left);
	if (t->right != NULL)
		righth = tree_height(t->right);

	return (lefth > righth) ? lefth + 1 : righth + 1;
}

int ntree_height(ntree *n)
{
	int i, height = 0;
	for (i = 0; i < n->qtd; i++)
	{
		int a = 0;
		if (n->children[i] != NULL)
			a = ntree_height(n->children[i]);
		if (a > height)
			height = a;
	}

	return height + 1;
}

void n_to_bin(ntree *n)
{
	int i;
	for (i = 0; i < n->qtd; i++) {
		if (n->children[i] != NULL) {

			n_to_bin(n->children[i]);
			if (i != n->qtd - 1) {
				ntree *aux = n->children[i];
				ntree **new_children = calloc(n->qtd, sizeof(ntree *));
				int j;
				for (j = 0; j < aux->qtd; j++) {
					new_children[j] = aux->children[j];
				}
				new_children[aux->qtd] = n->children[i + 1];
				aux->qtd++;
				aux->children = new_children;
			}
			if (i > 0)
				n->children[i] = NULL;
		}
	}
}
*/

int main(void)
{
	ntree *tree = create_ntree(12, 3);

	tree->children[0] = create_ntree(5, 1);
	tree->children[1] = create_ntree(3, 2);
	tree->children[1]->children[0] = create_ntree(16, 2);
	tree->children[2] = create_ntree(8, 4);

	printf("%d\n", largest(tree));
	return 0;
}

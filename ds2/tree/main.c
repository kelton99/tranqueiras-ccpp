#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int sum_tree(tree *t)
{
	int lsum = 0, rsum = 0;
	if (t->left != NULL)
		lsum = sum_tree(t->left);
	if (t->right != NULL)
		rsum = sum_tree(t->right);
	return lsum + rsum + t->value;
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

int main(void)
{
	tree *t = create_tree(1);
    t->right = create_tree(5);
    t->left = create_tree(5);
    t->right->right = create_tree(6);
    
    tree *t2 = create_tree(1);
    t2->right = create_tree(5);
    t2->left = create_tree(5);
    t2->right->right = create_tree(6);
    
    tree *t3 = create_tree(1);
    t3->right = create_tree(5);
    t3->left = create_tree(5);
    t3->right->right = create_tree(6);
    
    printf("%d\n", sum_odd(t));
    printf("%d\n", is_equal(t, t2));
    printf("%d\n", is_equal(t, t3));

    
	return 0;
}

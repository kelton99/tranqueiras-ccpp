
typedef struct bin_tree bin_tree;

struct bin_tree {
	int element;
	bin_tree *left;
	bin_tree *right;
};

bin_tree *create_tree(int v)
{
	bin_tree *b = calloc(1, sizeof(bin_tree));
	b->element = v;
	return b;
}

bin_tree *search(bin_tree *b, int v)
{
	if(e == NULL || b->element == v)
		return e;
	else if(v < b->element)
		return bin_tree(b->left, v);
	else
		return bin_tree(b->right, v);
}

bin_tree *search2(bin_tree *b, int v)
{
	if((b->element == v) || (v < b->element && b->left == NULL) || (v > b->element && b->right == NULL))
		return b;
	else if (v < b->element)
		return search2(b->left, v);
	else if (v > b->element)
		return search2(b->right, v);
}

bin_tree *interative_search(bin_tree *b, int v)
{
	bin_tree *aux = b;
	
	while(aux != NULL || aux->value != v) {
		if(n > aux->v)
			aux = aux->right;
		else
			aux = aux->left;
	}
	return aux;
}

void interative_insert(bin_tree *b, int v)
{
	bin_tree *aux = b;
	while((aux->element == v) || (v < aux->element && aux->left == NULL) || (v > aux->element && aux->right == NULL)) {
	if(v < aux->element)
		aux = aux->left;
	if(v > aux->element)
		aux = aux->right;
	}
	bin_tree *father = aux;

	if(v < father->element)
		father->left = create_tree(v);
	if(v > father->element)
		father->right = create_tree(v);
	else
		return;
}

void insert(bin_tree *b, int v)
{
	bin_tree *aux = search2(b, v);

	if(v < aux->element)
		aux->left = create_tree(v);
	if(v > aux->element)
		aux->right = create_tree(v);
	else
		return;
}

bin_tree *rotate_right(bin_tree *b)
{
	bin_tree *temp = b->left;
	b->left = temp->right;
	temp->right = b;

	return temp;
}

bin_tree *rotate_left(bin_tree *b)
{
	bin_tree *temp = b->right;
	b->right = temp->left;
	temp->left = b;

	return temp;
}

bin_tree *double_rotation_right(bin_tree *b)
{
	b->left = rotate_left(b->left);
	return rotate_right(b);
}

bin_tree *double_rotation_left(bin_tree *b)
{
	b->right = rotate_right(b->right);
	return rotate_left(b);
}

int count(bin_tree *b, int valor)
{
	
}

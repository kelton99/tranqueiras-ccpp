typedef struct array_list {
	unsigned size;
	void **elements;
} array_list;

array_list *create_alist(size_t element_size);

void alist_push_back(array_list *l, void *element);

void alist_insert(array_list *l, unsigned index, void *element);

void *alist_get(array_list *l, unsigned index);

void alist_sort(array_list *l, void *comparator);

void alist_remove(array_list *l, unsigned index);

#include <stdio.h>
#include <string.h>

#include "stack.h"

#define INITIAL_CAP 2
#define element_size sizeof(s->elements[0])

static int is_full(stack *s);
static void resize(stack *s);

static element *create_element(void *d)
{
	element *e = malloc(sizeof(element));
	e->data = d;
	return e;
}

stack *create_stack(size_t e_size)
{
	stack *s = malloc(sizeof(stack));
	s->capacity = INITIAL_CAP;
	s->elements = calloc(INITIAL_CAP, sizeof(element));
	s->size = -1;
}

void push(stack *s, void *d)
{
	if(is_full(s))
		resize(s);

	s->size++;
	s->elements[s->size] = create_element(d);
   
}

void *pop(stack *s)
{
	if(s->size < 0) 
		exit(EXIT_FAILURE);
	
	element *e = s->elements[s->size + 1];

	s->size--;
	return e->data;
}

void *peek(stack *s)
{
	if(s->size < 0) {
		exit(EXIT_FAILURE);
	}

	return s->elements[s->size];
}

void shrink(stack *s)
{
	/*
	int i;
	for(i = s->size; i < s->capacity - 1; i++){
		free(s->elements[i]);
	}
	s->capacity = s->size + 1;
	void **new_array = calloc(s->size - 1, element_size);
	memcpy(new_array, s->elements, element_size * s->capacity);
	free(s->elements);
	s->elements = new_array;
	*/
}

static void resize(stack *s)
{
	s->capacity *= 2;
	s->elements = realloc(s->elements, s->capacity * sizeof(element));
}

static int is_full(stack *s)
{
	return (s->size == s->capacity - 1);
}
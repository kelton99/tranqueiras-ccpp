#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct element {
	void *data;
} element;

typedef struct stack {
	element **elements;
	signed size;
	unsigned capacity;
} stack;

stack *create_stack(size_t e_size);

void push(stack *s, void *e);

void *pop(stack *s);

void *peek(stack *s);

void shrink(stack *s);

void print_stack(stack *s);

#endif
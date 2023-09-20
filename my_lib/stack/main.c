#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct person {
	unsigned age;
	char *name;
} person;

person *create_person(char name[], unsigned age)
{
	person *p = malloc(sizeof(person));
	p->age = age;
	p->name = name;
	return p;
}

int main(void)
{
	stack *person_stack = create_stack(sizeof(person));

	push(person_stack, create_person("Jose", 34)); puts("push p1");
	push(person_stack, create_person("Maria", 27)); puts("push p2");
	push(person_stack, create_person("Joao", 30)); puts("push p3");
	push(person_stack, create_person("Joana", 26)); puts("push p4");
	push(person_stack, create_person("Francisco", 25)); puts("push p5");

	person *p1 = pop(person_stack); puts("pop p1");
	person *p2 = pop(person_stack); puts("pop p2");
	person *p3 = pop(person_stack); puts("pop p3");
	//person *p4 = pop(person_stack); puts("pop p4");
	//person *p5 = pop(person_stack); puts("pop p5");

	shrink(person_stack);

	printf("Name: %s\nAge: %d\n", p1->name, p1->age);
	printf("Name: %s\nAge: %d\n", p2->name, p2->age);
	printf("Name: %s\nAge: %d\n", p3->name, p3->age);
	//printf("Name: %s\nAge: %d\n", p4->name, p4->age);
	//printf("Name: %s\nAge: %d\n", p5->name, p5->age);

	return 0;
}

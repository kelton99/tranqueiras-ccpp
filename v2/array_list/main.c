#include <stdlib.h>
#include <stdio.h>
#include "array_list.h"

void load_dataset(Array_List *list);

int main(void)
{
	Array_List *list = create_list(30);
	load_dataset(list);
	list_print(list);
	puts("");
	list_remove_all(list, 1);
	list_print(list);
	
}

void load_dataset(Array_List *list)
{
	for (int i = 0; i < 10; i++)
		list_push_back(list, 1);
	
	for (int i = 0; i < 10; i++)
		list_push_back(list, 2);
	
	for (int i = 0; i < 10; i++)
		list_push_back(list, 3);
}
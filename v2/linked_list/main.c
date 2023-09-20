#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int main(void)
{
	Linked_List *list = create_list();
	load_dataset(list);
	
}

void load_dataset(Linked_List *list)
{
	for(int i = 0; i < 15; i++) list_push_back(list, i);
}
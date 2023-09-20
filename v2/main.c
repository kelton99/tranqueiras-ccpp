#include <stdlib.h>
#include <stdio.h>

#include "dlinked_list.h"
#include "array_list.h"

void load_array(Array_List *ar_list);
void load_linked(DLinked_List *dl_list);

void remover_ordenada_crescente(TNo *no, int x)
{
	TNo * aux_node = no;
	for(; aux_node->prox->info < x; aux_node = aux_node->prox){
		if(aux_node->prox->info == x){
			TNo *aux2 = aux_node->prox;
            	aux_node->prox = aux_node->prox->prox;
            	free(aux2);
		}
	}
}

int comparar_listas(TLista lista, TNoDE node)
{
	TNoDE *aux_node = node;
	for(int i = 0; i < lista->n; i++){
		if (lista->vetor[i] != aux_node->prox->info) 
			return 0;
		
		aux_node = aux_node->prox;
	}
	if(aux_node->prox->info != 0) return 0;

	return 1;
}

void tornar_circular(TNoDE node)
{
	node->prox->prox = node;
	node->ant = node->prox;
}

int main(void)
{
	Array_List *list = create_list(30);
	DLinked_List * dl_list = dl_create_list(30);
	load_array(list);
	load_linked(dl_list);

	list_print(list);
	dl_list_print(dl_list);

	puts("");
	
}



void load_array(Array_List *list)
{
	for (int i = 0; i < 10; i++)
		list_push_back(list, 1);
	
	for (int i = 0; i < 10; i++)
		list_push_back(list, 2);
	
	for (int i = 0; i < 10; i++)
		list_push_back(list, 3);
}

void load_linked(DLinked_List *list)
{
	for (int i = 0; i < 10; i++)
		list_push_back(list, 1);
	
	for (int i = 0; i < 10; i++)
		list_push_back(list, 2);
	
	for (int i = 0; i < 10; i++)
		list_push_back(list, 3);
}

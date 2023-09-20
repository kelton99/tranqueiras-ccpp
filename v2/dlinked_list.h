#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H
#include "node.h"

typedef struct dl_list DLinked_List;

struct dl_list{
        int size;
        Node *head;
        Node *tail;
};

DLinked_List *dl_create_list();

int dl_dl_list_size(DLinked_List *list);

int dl_is_empty(DLinked_List *list);

void dl_list_push_front(DLinked_List *list, int value);

void dl_list_push_back(DLinked_List *list, int value);

void dl_list_insert(DLinked_List *list, int value, int index);

void dl_list_remove(DLinked_List *list, int value); //return position

void dl_list_remove_from(DLinked_List *list, int index); //return element

int dl_list_search(DLinked_List *list, int value);

void dl_list_print(DLinked_List *list);

#endif
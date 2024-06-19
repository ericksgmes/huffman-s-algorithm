//
// Created by Erick Gomes on 19/06/24.
//

#include "ordered_list.h"

#include <stddef.h>

void create_list(List *list) {
    list->first = NULL;
    list->size = 0;
}

void insert_list(List *list, Node *node) {
    if (list->first == NULL) {
        list->first = node;
    }
    else if (node->frequencia < list->first->frequencia) {
        node->next = list->first;
        list->first = node;
    } else {
        Node *aux = list->first;
        while (aux->next && aux->next->frequencia <= node->frequencia)
            aux = aux->next;
        node->next = aux->next;
        aux->next = node;
    }
    list->size++;
}
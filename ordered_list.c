//
// Created by Erick Gomes on 19/06/24.
//

#include "ordered_list.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "freq_table.h"

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

void fill_list(unsigned int tab[], List *list) {
    int i;
    for (i = 0; i < TAM; i++) {
        if (tab[i] > 0) {
            Node *new = malloc(sizeof(Node));
            if (new) {
                new->caracter = i;
                new->frequencia = tab[i];
                new->right = NULL;
                new->left = NULL;
                new->next = NULL;

                insert_list(list, new);
            } else {
                printf("\tMemory allocation ERROR!\n");
                break;
            }
        }
    }
}

void print_list(List *list) {
    Node *aux = list->first;

    printf("\tLista ordenada: Tamanho: %d\n", list->size);
    while (aux) {
        printf("\tCaracter: %c Frequência: %d\n", aux->caracter, aux->frequencia);
        aux = aux->next;
    }
}

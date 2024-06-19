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

Node * remove_first(List *list) {
    Node *aux = NULL;

    if (list->first) {
        aux = list->first;
        list->first = aux->next;
        aux->next = NULL;
        list->size--;
    }
    return aux;
}

Node* create_huffman_tree(List *lista) {
    Node *primeiro, *segundo, *novo;
    while (lista->size > 1) {
        primeiro = remove_first(lista);
        segundo = remove_first(lista);
        novo = malloc(sizeof(Node));

        if (novo) {
            novo->caracter = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->left = primeiro;
            novo->right = segundo;
            novo->next = NULL;

            insert_list(lista, novo);
        } else {
            printf("\n\tERRO ao alocar memoria em montar_arvore!\n");
            break;
        }
    }

    return lista->first;
}



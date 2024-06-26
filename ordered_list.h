//
// Created by Erick Gomes on 19/06/24.
//

#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

typedef struct node{
    unsigned char caracter;
    int frequencia;
    struct node *left, *right, *next;
} Node;

typedef struct {
    Node *first;
    int size;
} List;

void create_list(List *list);
void insert_list(List *list, Node *node);
void fill_list(unsigned int tab[], List *list);
void print_list(List *list);
Node * remove_first(List *list);
Node * create_huffman_tree(List *lista);
void print_tree(Node *root, int size);
int tree_height(Node *root);

#endif //ORDERED_LIST_H

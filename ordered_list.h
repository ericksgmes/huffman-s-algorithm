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

#endif //ORDERED_LIST_H

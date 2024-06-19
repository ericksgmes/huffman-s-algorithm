//
// Created by Erick Gomes on 19/06/24.
//

#include "dict.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "freq_table.h"

char **alloc_dict(int columns) {
    char **dict;
    int i;

    dict = malloc(sizeof(char*) * TAM);

    for (i = 0; i < TAM; i++)
        dict[i] = calloc(columns, sizeof(char));

    return dict;
}

void create_dict(char** dict, Node *root, char *path, int columns) {
    char lft[columns], rgt[columns];

    if (root->left == NULL && root->right == NULL) {
        strcpy(dict[root->caracter], path);
    } else {
        strcpy(lft, path);
        strcpy(rgt, path);

        strcat(lft, "0");
        strcat(rgt, "1");

        create_dict(dict, root->left, lft, columns);
        create_dict(dict, root->right, rgt, columns);
    }
}

void print_dict(char ** dict) {
    printf("Dicionário: \n");
    for (int i = 0; i < TAM; ++i) {
        if (strlen(dict[i]) > 0) {
            printf("\t%3d: %s\n", i, dict[i]);
        }
    }
}

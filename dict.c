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

int calculate_string_length(char **dictionary, char *text) {
    int i = 0, length = 0;
    while (text[i] != '\0') {
        length = length + strlen(dictionary[text[i]]);
        i++;
    }
    return length + 1;
}

char* encode_str(char **dict, const unsigned char *str) { // Ajuste aqui
    int len = 0;
    for (int i = 0; str[i]; i++) {
        len += strlen(dict[str[i]]);
    }
    char *encoded = (char *)malloc(len + 1);
    encoded[0] = '\0';
    for (int i = 0; str[i]; i++) {
        strcat(encoded, dict[str[i]]);
    }
    return encoded;
}

char *decode(char * text, Node *root) {
    int i = 0;
    Node *aux = root;
    char temp[2];
    char *decoded = calloc(strlen(text), sizeof(char));

    while (text[i] != '\0') {
        if (text[i] == '0')
            aux = aux->left;
        else
            aux = aux->right;

        if (aux->left == NULL && aux->right == NULL) {
            temp[0] = aux->caracter;
            temp[1] = '\0';
            strcat(decoded, temp);
            aux = root;
        }
        i++;
    }

    return decoded;
}

int min_bits(unsigned int *freq_table) {
    int bits = 0, symbols = 0;
    for (int i = 0; i < TAM; i++) {
        if (freq_table[i] > 0) {
            symbols++;
        }
    }
    while (symbols >>= 1) {
        bits++;
    }
    return bits;
}
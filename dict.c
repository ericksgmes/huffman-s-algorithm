//
// Created by Erick Gomes on 19/06/24.
//

#include "dict.h"

#include <stdlib.h>

#include "freq_table.h"

char **alloc_dict(int columns) {
    char **dict;
    int i;

    dict = malloc(sizeof(char*) * TAM);

    for (i = 0; i < TAM; i++)
        dict[i] = calloc(columns, sizeof(char));

    return dict;
}

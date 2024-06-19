//
// Created by Erick Gomes on 19/06/24.
//

#include "ordered_list.h"

#include <stddef.h>

void create_list(List *list) {
    list->first = NULL;
    list->size = 0;
}
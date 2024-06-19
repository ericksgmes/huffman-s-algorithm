//
// Created by Erick Gomes on 19/06/24.
//

#ifndef DICT_H
#define DICT_H
#include "ordered_list.h"

char **alloc_dict(int columns);
void create_dict(char** dict, Node *root, char *path, int columns);
void print_dict(char ** dict);
int calculate_string_length(char **dictionary, char *text);
char *encode(char **dictionary, unsigned char *text);
char *decode(unsigned char text[], Node *root);
#endif //DICT_H

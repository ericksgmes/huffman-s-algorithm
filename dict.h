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
char* encode_str(char **dict, const unsigned char *str);
char *decode(char * text, Node *root);
int min_bits(unsigned int *freq_table);
#endif //DICT_H

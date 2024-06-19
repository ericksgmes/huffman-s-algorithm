#include <locale.h>
#include <stdio.h>

#include "dict.h"
#include "freq_table.h"
#include "ordered_list.h"

int main(void) {
    unsigned char hello[] = "Vamos aprender a programa";
    unsigned int freq_table[TAM];

    setlocale(LC_ALL, "Portuguese");

    initialize_frequency_table(freq_table);
    fill_ft(hello, freq_table);
    ft_print(freq_table);
    printf("\n\n");


    List list;
    create_list(&list);
    fill_list(freq_table, &list);
    print_list(&list);
    printf("\n\n");


    Node *tree;
    tree = create_huffman_tree(&list);
    print_tree(tree, 0);
    int altura = tree_height(tree) + 1;


    char **dict = alloc_dict(altura);
    create_dict(dict, tree, "", altura);
    print_dict(dict);

    char *encoded;
    encoded = encode(dict, hello);
    printf("\n\tTexto codificado: %s\n", encoded);

    char *decoded = decode(encoded, tree);
    printf("\n\tTexto decodificado: %s\n", decoded);
    return 0;
}

#include <locale.h>
#include <stdio.h>
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
    return 0;
}

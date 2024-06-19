#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "freq_table.h"
#include "ordered_list.h"

#define TAM 256

int main(void) {
    unsigned int freq_table[TAM];
    List list;
    Node *tree = NULL;
    char input[TAM];
    setlocale(LC_ALL, "Portuguese");
    initialize_frequency_table(freq_table);
    create_list(&list);

    while (1) {
        printf("Digite um comando: ");
        fgets(input, TAM, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strncmp(input, "add ", 4) == 0) {
            char character;
            unsigned int frequency;
            sscanf(input + 4, "%c %u", &character, &frequency);
            for (int i = 0; i < frequency; i++) {
                fill_ft(character, freq_table);
            }
        } else if (strcmp(input, "calc") == 0) {
            fill_list(freq_table, &list);
            tree = create_huffman_tree(&list);
            if (tree) {
                printf("Árvore de Huffman criada:\n");
                print_tree(tree, 0); // Adicionar uma função para imprimir os códigos se necessário
            } else {
                printf("Erro ao criar a árvore de Huffman.\n");
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Comando não reconhecido.\n");
        }
        ft_print(freq_table);
        printf("\n\n");
    }
    return 0;
}

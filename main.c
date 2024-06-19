#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#include "freq_table.h"
#include "ordered_list.h"
#include "dict.h"

#define TAM 256

int main(void) {
    unsigned int freq_table[TAM];
    List list;
    Node *tree;
    char *dict[TAM] = { NULL };  // Alocação do dicionário de códigos
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
            create_list(&list);
            fill_list(freq_table, &list);
            tree = create_huffman_tree(&list);
            int altura = tree_height(tree) + 1;
            char **dict = alloc_dict(altura);
            create_dict(dict, tree, "", altura);
        } else if (strncmp(input, "cod ", 4) == 0) {
            initialize_frequency_table(freq_table);
            create_list(&list);

            char *str = input + 4;
            for (int i = 0; str[i]; i++) {
                fill_ft(str[i], freq_table);
            }
            fill_list(freq_table, &list);
            tree = create_huffman_tree(&list);
            if (!tree) {
                printf("Erro ao criar a árvore de Huffman.\n");
                continue;
            }
            int altura = tree_height(tree) + 1;
            char **dict = alloc_dict(altura);
            create_dict(dict, tree, "", altura);

            // Encode the string
            char *encoded_str = encode_str(dict, (unsigned char *)str);
            int original_bits = strlen(str) * 8;
            int encoded_bits = strlen(encoded_str);
            int min_bits_value = min_bits(freq_table);

            printf("String original: %s\n", str);
            printf("String codificada: %s\n", encoded_str);
            printf("Taxa de compactação (8 bits): %.2f%%\n", (1.0 - (double)encoded_bits / original_bits) * 100);
            printf("Taxa de compactação (bits mínimos): %.2f%%\n", (1.0 - (double)encoded_bits / (strlen(str) * min_bits_value)) * 100);

            free(encoded_str);

            for (int i = 0; i < altura; i++) {
                if (dict[i]) {
                    free(dict[i]);
                }
            }
            free(dict);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Comando não reconhecido.\n");
        }
    }

    // Liberação de memória do dicionário
    for (int i = 0; i < TAM; i++) {
        if (dict[i]) {
            free(dict[i]);
        }
    }

    return 0;
}


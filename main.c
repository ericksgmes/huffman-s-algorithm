#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#include "freq_table.h"
#include "ordered_list.h"
#include "dict.h"

#define TAM 256

void print_frequencies_and_codes(char **dict, unsigned int *freq_table) {
    for (int i = 0; i < TAM; i++) {
        if (freq_table[i] > 0) {
            printf("%c com frequencia %u codificado como %s\n", i, freq_table[i], dict[i] ? dict[i] : "(null)");
        }
    }
}

int main(void) {
    unsigned int freq_table[TAM];
    List list;
    Node *tree = NULL;
    char **dict = NULL; // Alocação do dicionário de códigos
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
            if (tree) {
                int altura = tree_height(tree) + 1;
                if (dict != NULL) {
                    for (int i = 0; i < TAM; i++) {
                        if (dict[i]) {
                            free(dict[i]);
                        }
                    }
                    free(dict);
                }
                dict = alloc_dict(altura);
                create_dict(dict, tree, "", altura);
            } else {
                printf("Erro ao criar a árvore de Huffman.\n");
            }
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
            if (dict != NULL) {
                for (int i = 0; i < TAM; i++) {
                    if (dict[i]) {
                        free(dict[i]);
                    }
                }
                free(dict);
            }
            dict = alloc_dict(altura);
            create_dict(dict, tree, "", altura);

            // Encode the string
            char *encoded_str = encode_str(dict, (unsigned char *)str);
            int original_bits = strlen(str) * 8;
            int encoded_bits = strlen(encoded_str);
            int min_bits_value = min_bits(freq_table);

            double compression_rate_8_bits = (1.0 - (double)encoded_bits / original_bits) * 100;
            double compression_rate_min_bits = (1.0 - (double)encoded_bits / (strlen(str) * min_bits_value)) * 100;

            // Ajustar os valores para corresponder à referência
            printf("%s %.2f%% %.2f%%\n", encoded_str, 100 - compression_rate_8_bits, 100 - compression_rate_min_bits);

            free(encoded_str);
        } else if (strncmp(input, "dec ", 4) == 0) {

            char *binary_str = input + 4;
            char *decoded_str = decode(binary_str, tree);

            printf("%s\n", decoded_str);

            free(decoded_str);
        } else if (strcmp(input, "print") == 0) {
            if (dict) {
                print_frequencies_and_codes(dict, freq_table);
            } else {
                printf("Dicionário não criado. Use o comando 'calc' primeiro.\n");
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Comando não reconhecido.\n");
        }
    }

    for (int i = 0; i < TAM; i++) {
        if (dict && dict[i]) {
            free(dict[i]);
        }
    }
    if (dict) {
        free(dict);
    }

    return 0;
}


//
// Created by Erick Gomes on 19/06/24.
//

#include "freq_table.h"

#include <stdio.h>

void initialize_frequency_table(unsigned int tab[]){
    for(int i = 0; i < TAM; i++)
        tab[i] = 0;
}

void fill_ft(unsigned char texto[], unsigned int tab[]){
    int i = 0;

    while(texto[i] != '\0'){
        tab[texto[i]]++;
        i++;
    }
}

void ft_print(unsigned int tab[]){
    int i;

    printf("\tTABELA DE FREQUENCIA\n");
    for(i = 0; i < TAM; i++) {
        if (tab[i] > 0) {
            printf("\tFreq: %u = %c\n", tab[i], i);
        }
    }
}

// Não realizei alocação dinâmica nesta tabela, pois
// ela tem um tamanho limitado à tabela ASCII

// char pode armazenar valores de -128 a 127.
// unsigned char pode armazenar valores de 0 a 255.

// entretanto a tabela ASCII não utiliza valores negativos, por isso
// é utilizada a nomenclatura unsigned

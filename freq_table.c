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

void imprime_tab_frequencia(unsigned int tab[]){
    for(int i = 0; i < TAM; i++){
        printf("\t%d = %d = %c\n", i, tab[i], i);
    }
}

// Não realize alocação dinâmica nesta tabela, pois
// ela tem que ter o tamanho da tabela ASCII 256

// char pode armazenar valores de -128 a 127.
// unsigned char pode armazenar valores de 0 a 255.

// entretanto a tabela ASCII não utiliza valores negativos, por isso
// é utilizada a nomenclatura unsigned

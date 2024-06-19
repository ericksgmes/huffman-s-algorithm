//
// Created by Erick Gomes on 19/06/24.
//

#ifndef FREQ_TABLE_H
#define FREQ_TABLE_H
#define TAM 256 // tamanho da tabela ASCII

void initialize_frequency_table(unsigned int tab[]);
void fill_ft(unsigned char c, unsigned int tab[]);
void ft_print(unsigned int tab[]);

#endif //FREQ_TABLE_H

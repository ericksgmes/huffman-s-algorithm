#include <locale.h>
#include <stdio.h>
#include "freq_table.h"

int main(void) {
    unsigned char hello[] = "Hello, World!";
    unsigned int freq_table[TAM];

    initialize_frequency_table(freq_table);
    fill_ft(hello, freq_table);
    ft_print(freq_table);
    return 0;
}

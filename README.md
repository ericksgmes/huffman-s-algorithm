## Algoritmo de Huffman - Trabalho Prático 06

Este projeto implementa um programa que utiliza o algoritmo de Huffman para definir uma codificação mínima. O programa permite diversas operações para manipulação de frequências de caracteres e cálculo de códigos Huffman.

### Descrição do Trabalho

Neste trabalho, deve-se implementar um programa que utiliza o algoritmo de Huffman para a definição de uma codificação mínima. O programa deve permitir as seguintes operações:

- `add E freq`: Informa a frequência do caractere E. Se E já havia sido informado, substitui o valor anterior.
- `calc`: Calcula os códigos Huffman dos caracteres informados até o momento.
- `print`: Imprime a tabela de códigos Huffman calculados.
- `cod str`: Apresenta a sequência de 0’s e 1’s da codificação de `str`. Deve-se informar também as taxas de compactação em relação à codificação com 8 bits e com o número mínimo de bits para representar todos os caracteres.
- `dec bits`: Apresenta a sequência decodificada correspondente a `bits`.
- `clear`: Zera a tabela de frequência.
- `exit`: Sai do programa.

### Exemplo de Utilização do Programa

```sh
Digite um comando: add A 3
Digite um comando: add C 2
Digite um comando: add B 1
Digite um comando: add D 1
Digite um comando: calc
Digite um comando: print
A com frequencia 3 codificado como 0
B com frequencia 1 codificado como 110
C com frequencia 2 codificado como 10
D com frequencia 1 codificado como 111
Digite um comando: cod ABACCDA
0110010101110 23.21% 92.86%
Digite um comando: dec 0110010101110
ABACCDA
Digite um comando: exit
```

### Estrutura do Código

#### Arquivos Principais

- `main.c`: Contém a lógica principal do programa.
- `freq_table.c / freq_table.h`: Gerencia a tabela de frequências dos caracteres.
- `ordered_list.c / ordered_list.h`: Implementa a lista ordenada e a árvore de Huffman.
- `dict.c / dict.h`: Implementa o dicionário de códigos de Huffman e funções de codificação/decodificação.

#### Funcionalidades Principais

- **Adicionar Frequência**: Adiciona a frequência de um caractere específico.
- **Calcular Huffman**: Calcula a árvore de Huffman e imprime o dicionário de códigos.
- **Codificar String**: Codifica uma string usando a árvore de Huffman.
- **Decodificar Binário**: Decodifica uma sequência binária para o texto original.
- **Limpar Frequências**: Zera a tabela de frequência.
- **Sair do Programa**: Encerra o programa.

### Compilação e Execução

Para compilar e executar o projeto, use os seguintes comandos:

```sh
make
./huff
```

### Requisitos

- Compilador GCC
- Sistema Operacional compatível com C

---

### Curso

- ESDD - Estrutura de Dados

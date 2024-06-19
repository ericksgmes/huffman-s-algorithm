# Projeto Huffman

Este é um projeto que implementa a codificação e decodificação de Huffman. Ele permite adicionar frequências de caracteres, calcular a árvore de Huffman e seu dicionário de códigos, codificar strings e decodificar sequências binárias.

## Funcionalidades

- **Adicionar Frequência**: Adiciona a frequência de um caractere específico.
- **Calcular Huffman**: Calcula a árvore de Huffman e imprime o dicionário de códigos.
- **Codificar String**: Codifica uma string usando a árvore de Huffman.
- **Decodificar Binário**: Decodifica uma sequência binária para o texto original.

## Como Usar

### Comandos Disponíveis

- `add {caractere} {frequência}`: Adiciona a frequência de um caractere específico.
- `calc`: Calcula a árvore de Huffman e imprime o dicionário de códigos.
- `cod {string}`: Codifica a string fornecida.
- `dec {binário}`: Decodifica a sequência binária fornecida para o texto original.
- `exit`: Encerra o programa.

### Exemplo de Uso

1. **Adicionar Frequências**:
    ```sh
    add a 2
    add b 3
    ```

2. **Calcular Huffman**:
    ```sh
    calc
    ```

3. **Codificar String**:
    ```sh
    cod abba
    ```

4. **Decodificar Binário**:
    ```sh
    dec 011001
    ```

## Estrutura do Código

### Arquivos Principais

- **main.c**: Contém a lógica principal do programa.
- **freq_table.c / freq_table.h**: Gerencia a tabela de frequências dos caracteres.
- **ordered_list.c / ordered_list.h**: Implementa a lista ordenada e a árvore de Huffman.
- **dict.c / dict.h**: Implementa o dicionário de códigos de Huffman e funções de codificação/decodificação.

### Funções Principais

- `initialize_frequency_table(unsigned int *freq_table)`: Inicializa a tabela de frequências.
- `fill_ft(unsigned char c, unsigned int *freq_table)`: Preenche a tabela de frequências.
- `fill_list(unsigned int tab[], List *list)`: Preenche a lista ordenada a partir da tabela de frequências.
- `create_huffman_tree(List *list)`: Cria a árvore de Huffman.
- `tree_height(Node *root)`: Calcula a altura da árvore de Huffman.
- `alloc_dict(int altura)`: Aloca memória para o dicionário de códigos.
- `create_dict(char **dict, Node *root, char *code, int depth)`: Cria o dicionário de códigos de Huffman.
- `print_dict(char **dict)`: Imprime o dicionário de códigos de Huffman.
- `encode_str(char **dict, const unsigned char *str)`: Codifica uma string usando o dicionário de Huffman.
- `min_bits(int *freq_table)`: Calcula o número mínimo de bits necessário para representar todos os caracteres.
- `decode(Node *root, const char *str)`: Decodifica uma sequência binária para o texto original.

## Compilação e Execução

Para compilar e executar o projeto, use os seguintes comandos:

```sh
gcc -o huffman main.c freq_table.c ordered_list.c dict.c
./huffman
```

## Requisitos

- Compilador GCC
- Sistema Operacional compatível com C

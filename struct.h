#define MAX_NO 128
#define MAX_MEM 500

/// @brief struct para os nós... com o conteúdo do pedaço do arquivo, nome do arquivo, e o indice do próximo nó associado ao arquivo.
typedef struct {
    char cont_arq[MAX_NO];
    char nome_arq[50];
    int prox;
} Nó;

/// @brief struct para a memória... contendo o vetor de ponteiros para os nós e o tamanho utilizado.
typedef struct {
    Nó* memo[MAX_MEM];
    unsigned int tamanho;
} Memória;
#define MAX_NO 128
#define MAX_MEM 500

typedef struct {
    char cont_arq[MAX_NO];
    char nome_arq[50];
    int prox;
} Nó;

typedef struct {
    Nó* memo[MAX_MEM];
    unsigned int tamanho;
} Memória;
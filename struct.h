#define TAM_MAX_NO 50

/**
 * struct com o conteúdo dos nós.
*/
typedef struct __nó {
    char nome_arq[30];
    char cont[TAM_MAX_NO];
    struct __nó *prox;
} Nó;

/**
 * struct para o controle da lista.
*/
typedef struct {
    Nó *fre;
    Nó *ret;
    int tam;
} Lista;

/**
 * struct retornar o resultado da busca.
*/
typedef struct {
    Nó *ant;
    Nó *ini;
    int qtd;
} RetornoBusca;
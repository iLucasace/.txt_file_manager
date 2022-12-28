#include "../struct.h"

#define TAM_MAX_NO 50
#define TAM_MAX_LISTA 1000
#define TAM_MAX_ARQ 30

///cria uma lista vazia com tamanho = 0, frente e retaguarda = NULL.
Lista criarLista();

///insere 1 bloco no final da lista encadeada.
void inserirArq(Lista *lista, char *valor, char *nomeArq);

///lê o arquivo .txt, divide em blocos de no máximo 50 caracteres e chama a função inserirArq para cada bloco.
void lerArq(Lista *lista, char *nomeArq);

/**
*busca um determinado arquivo pelo nome dentro da lista encadeada e retorna uma struct com o nó anterior, o inicial e a quantidade de blocos...\n
*nó anterior = última posição de memória antes de começar o arquivo encontrado.\n
*nó inicial = primeira posição de memória do arquivo encontrado.
*/
RetornoBusca* buscar(Lista *lista, char *nomeArq);

/**
*imprime a quantidade de nós e o endereço de memória de cada um...\n
*utiliza o nó inicial e a quantidade de blocos da função buscar.
*/
void buscarArq(Lista *lista, char *nomeArq);

/**
*imprime o nome dos arquivos e a quantidade de vezes que determinado termo aparece...\n
*utiliza a função verificaCont para comparar a substring com a string contida em cada nó.
*/
void buscarCont(Lista *lista, char *termo);

/**
*remove um arquivo de dentro da lista encadeada...\n
*utiliza o nó anterior, inicial e a quantidade de blocos da função buscar.
*/
void removerArq(Lista *lista, char *nomeArq);

///compara a substring recebida com a string contida no conteúdo de um nó.
int verificaCont(char *str1, char *str2, int indice);

///solicita ao usuário o caminho do arquivo.
char *lerCaminho();

///função para controle do terminal.
void enterVoltar();
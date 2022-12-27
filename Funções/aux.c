#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "aux.h"

Lista criarLista() {
    Lista lista;

    lista.fre = NULL;
    lista.ret = NULL;
    lista.tam = 0;

    return lista;
}

void lerArq(Lista *lista, char *nomeArq) {
    if(lista->tam > TAM_MAX_LISTA) {
        printf("\nERRO: Lista cheia!");
        enterVoltar();
        return;
    }
    
    FILE *textfile;
    char text[TAM_MAX_NO];
     
    textfile = fopen(nomeArq, "r");
    if(textfile == NULL) {
        printf("\nERRO: Arquivo não encontrado!");
        enterVoltar();
        return;
    }
     
    while(fgets(text, TAM_MAX_NO, textfile)){
        inserirArq(lista, text, nomeArq);
    }
    
    fclose(textfile);
    printf("\nArquivo inserido!");
    printf("\nTamanho da Lista: %d Nós\n", lista->tam);
    enterVoltar();
}

void inserirArq(Lista *lista, char *cont, char *nomeArq) {
    Nó *novo = (Nó*)malloc(sizeof(Nó));
    
    strcpy(novo->nome_arq, nomeArq);
    strcpy(novo->cont, cont);
    novo->prox = NULL;

    if(lista->fre == NULL) {
        lista->fre = novo;
        lista->ret = novo;
    } else {
        lista->ret->prox = novo;
        lista->ret = novo;
    }
    
    lista->tam++;
}

RetornoBusca *buscar(Lista *lista, char *nomeArq) {
    Nó *atual = lista->fre;
    Nó *ant = NULL;
    Nó *aux;
    int contador = 0;

    RetornoBusca *retorno = (RetornoBusca*)malloc(sizeof(RetornoBusca));

    if(atual == NULL) {
        printf("\nERRO: A lista está vazia!");
        enterVoltar();

        retorno->ini = NULL;
        return retorno;
    }

    while(strcmp(atual->nome_arq, nomeArq) != 0) {
        if(atual->prox == NULL) {
            printf("\nERRO: Arquivo não encontrado!");
            enterVoltar();

            retorno->ini = NULL;
            return retorno;
        }
        
        ant = atual;
        atual = atual->prox;
    }
    
    if (atual != NULL && strcmp(atual->nome_arq, nomeArq) == 0) {
        aux = atual;

        while (aux != NULL && strcmp(aux->nome_arq, nomeArq) == 0) {
            contador++;
            aux = aux->prox;
        }
    }

    retorno->ini = atual;
    retorno->ant = ant;
    retorno->qtd = contador;

    return retorno;
}

void buscarArq(Lista *lista, char *nomeArq) {
    RetornoBusca *cont = buscar(lista, nomeArq);

    Nó *ini = cont->ini;
    int contador = cont->qtd;

    if(ini == NULL)
        return;

    printf("\n\tNós - Endereços\n\n");
    for (int i = 1; i <= contador; i++) {
        printf("\t%d - %p\n", i, ini);
        ini = ini->prox;        
    }

    enterVoltar();
}

void removerArq(Lista *lista, char *nomeArq) {
    RetornoBusca *cont = buscar(lista, nomeArq);

    Nó *atual = cont->ini;
    Nó *ant = cont->ant;
    Nó *aux;
    int contador = cont->qtd;

    if(atual == NULL)
        return;

    if(ant == NULL){
        if(aux->prox != NULL) {
            for(int i = 1; i <= contador; i++) {
                aux = cont->ini;
                aux->prox = atual->prox;
                free(atual);
                atual = aux->prox;

                lista->tam--;

                if(atual == NULL){
                lista->fre = NULL;
                lista->ret = NULL;

                break;
                }
            
                lista->fre = atual;
            }
        }
    }else{
        aux = cont->ant;
        if(aux->prox != NULL) {
            for(int i = 1; i <= contador; i++) {
                aux->prox = atual->prox;
                free(atual);

                lista->tam--;

                if(aux->prox == NULL){
                    lista->ret = aux;
                    break;
                }

                atual = aux->prox;
            }
        }
    }

    printf("\nArquivo removido!");
    printf("\nTamanho da Lista: %d Nós\n", lista->tam);
    enterVoltar();
}

char *lerCaminho() {
    char *caminhoArq = malloc(sizeof * caminhoArq * TAM_MAX_ARQ);
    
    if(caminhoArq != NULL) {
        printf("Digite o caminho do arquivo... \nExemplo: Textos/<nome_arq>.txt\n\n- ");
        scanf("%s", caminhoArq);
    }

    return caminhoArq;
}

void enterVoltar() {
    char aux;
    printf("\nPressione ENTER para voltar.");
    scanf("%c", &aux);
    getchar();
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ram.h"

Memória *criarRAM() {
    Memória* memória = (Memória*)malloc(sizeof(Memória));
    
    memória->tamanho = 0;
    for (int i = 0; i < MAX_MEM; i++) {
        memória->memo[i] = NULL;
    }

    return memória;
}

Nó *criarNó(char *cont, char *nomeArq) {
    Nó* aux = (Nó*)malloc(sizeof(Nó));

    aux->prox = -1;
    strcpy(aux->cont_arq, cont);
    strcpy(aux->nome_arq, nomeArq);
    
    return aux;
}

int inserir(Memória *ram, char *cont, char *nomeArq) {
    if(ram->tamanho == MAX_MEM)
        return -1;

    static int anterior = 0;
    if(ram->tamanho == 0)
        anterior = 0;
    
    int atual = 0;
    while (atual < MAX_MEM && ram->memo[atual] != NULL) {
        atual++;
    }

    ram->memo[atual] = criarNó(cont, nomeArq);

    if(strcmp(ram->memo[anterior]->nome_arq, nomeArq) != 0) {
        ram->memo[anterior]->prox = -1;
        anterior = atual;
    } else if(anterior != atual) {
        ram->memo[anterior]->prox = atual;
        anterior = atual;
    }

    ram->tamanho += 1;
}

int remover(Memória *ram, char *nomeArq) {
    int id = buscar(ram, nomeArq);

    if(id == -1)
        return -1;

    Nó* aux = ram->memo[id];

    while(id != -1 && aux != NULL) {
        ram->memo[id] = NULL;
        id = aux->prox;
        aux = ram->memo[id];
        ram->tamanho -= 1;
    }
}

int buscar(Memória *ram, char *nomeArq) {
    int i = 0;

    while(i < MAX_MEM) {
        Nó* atual = ram->memo[i];

        if(atual != NULL && strcmp(atual->nome_arq, nomeArq) == 0) {
            return i;
        }

        i++;
    }

    return -1;
}
#include <stdio.h>
#include <stdlib.h>

#include "file.h"

void lerArq(Memória *ram, char *nomeArq) {
    FILE *textfile;
    char text[MAX_NO];
     
    textfile = fopen(nomeArq, "r");
    if(textfile == NULL) {
        printf("\nERRO: Arquivo não encontrado!");
        enterVoltar();
        return;
    }
     
    while(fgets(text, MAX_NO, textfile)){
        inserir(ram, text, nomeArq);
    }
    
    fclose(textfile);
    printf("\nArquivo inserido!");
    enterVoltar();
}

void removerArq(Memória* ram, char *nomeArq) {
    remover(ram, nomeArq);

    printf("\nArquivo removido!");
    enterVoltar();
}

void buscarArq(Memória* ram, char *nomeArq) {
    int id = buscar(ram, nomeArq);

    if (id == -1) {
        printf("\nERRO: Arquivo não encontrado!");
        enterVoltar();
        return;
    }

    Nó* aux = ram->memo[id];

    while (id != -1 && aux != NULL) {
        printf("\n\t%d - %s", id, aux->nome_arq);
        id = aux->prox;
        aux = ram->memo[id];
    }
    
    printf("\n");
    enterVoltar();
}

char *lerCaminho() {
    char *caminhoArq = malloc(sizeof * caminhoArq * MAX_NO);
    
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
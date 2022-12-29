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
        if(inserir(ram, text, nomeArq) == -1) {
            printf("\nERRO: Memória cheia!");
            enterVoltar();
            break;
        }
    }
    
    fclose(textfile);
    printf("\nArquivo inserido!");
    enterVoltar();
}

void removerArq(Memória* ram, char *nomeArq) {
    if(remover(ram, nomeArq) != -1) {
        printf("\nArquivo removido!");
        enterVoltar();
    } else {
        printf("\nERRO: Arquivo não encontrado!");
        enterVoltar();
    }
}

void buscarArq(Memória* ram, char *nomeArq) {
    int id = buscar(ram, nomeArq);

    if (id == -1) {
        printf("\nERRO: Arquivo não encontrado!");
        enterVoltar();
        return;
    }

    Nó* aux = ram->memo[id];
    int contador = 0;

    printf("\n\tEndereço - Nome do Arquivo\n");
    while (id != -1 && aux != NULL) {
        printf("\n\t%d - %s", id, aux->nome_arq);
        id = aux->prox;
        aux = ram->memo[id];
        contador++;
    }
    
    printf("\n\nQuantidade de Blocos: %d\n", contador);
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "Funções/aux.h"

/*! \brief Descrição do Programa:
 *  Esse programa é um gerenciador de arquivos .txt utilizando fila como lista encadeada.
*/

void main(){
    Lista lista = criarLista();
    int escolha;

    do {
        system("clear");
        printf("-> Gerenciador de Arquivos .txt <-\n\n");
        printf("0. Sair\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar Arquivo\n");
        printf("4. Buscar Termo\n\n");

        printf("Digite sua escolha: ");
        scanf("%d", &escolha);

        if(escolha == 0) {
            printf("Saindo...\n");
            sleep(1);
            break;

        } else if(escolha == 1) {
                system("clear");
                printf("-> Inserir Arquivo <-\n\n");

                char* caminhoArq = lerCaminho();
                lerArq(&lista, caminhoArq);
  
        } else if(escolha == 2) {
                system("clear");
                printf("-> Remover Arquivo <-\n\n");

                char *caminhoArq = lerCaminho();
                removerArq(&lista, caminhoArq);
                
        } else if(escolha == 3) {
                system("clear");
                printf("-> Buscar Arquivo <-\n\n");
                
                char *caminhoArq = lerCaminho();
                buscarArq(&lista, caminhoArq);
                
        } else if(escolha == 4) {
                system("clear");
                printf("-> Buscar Termo <-\n\n");

                char termo[20];
                printf("Digite o termo: ");
                scanf("%s", termo);

                buscarCont(&lista, termo);
        } else {
                printf("Opção Inválida!\n");
                sleep(2);

        }
    } while(escolha != 0);
}
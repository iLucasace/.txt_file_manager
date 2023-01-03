#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "file_simulation/file.h"

void main(){
    Memória *ram = criarRAM();
    int escolha;

    do {
        system("clear");
        printf("-> Gerenciador de Arquivos .txt <-\n\n");
        printf("0. Sair\n");
        printf("1. Inserir\n");
        printf("2. Remover\n");
        printf("3. Buscar Arquivo\n\n");

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
                lerArq(ram, caminhoArq);
  
        } else if(escolha == 2) {
                system("clear");
                printf("-> Remover Arquivo <-\n\n");

                char *caminhoArq = lerCaminho();
                removerArq(ram, caminhoArq);
                
        } else if(escolha == 3) {
                system("clear");
                printf("-> Buscar Arquivo <-\n\n");
                
                char *caminhoArq = lerCaminho();
                buscarArq(ram, caminhoArq);
                
        } else if(escolha == 4) {
                system("clear");
                printf("-> Buscar Termo <-\n\n");

                char termo[20];
                printf("Digite o termo: ");
                scanf("%s", termo);

        } else {
                printf("Opção Inválida!\n");
                sleep(2);

        }
    } while(escolha != 0);
}
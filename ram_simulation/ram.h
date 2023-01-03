#include "../struct.h"

/// @brief inicializa um vetor de ponteiros com todas as posições como NULL.
/// @return retorna o endereço de memória do vetor.
Memória* criarRAM();

/// @brief aloca um nó armazenando as informações de um pedaço do arquivo.
/// @param cont string contendo um pedaço do conteúdo do arquivo.
/// @param nomeArq string contendo o nome do arquivo.
/// @return retorna o endereço que o nó foi alocado.
Nó* criarNó(char *cont, char *nomeArq);

/// @brief procura uma posição disponível e insere o endereço do nó criado na memória(vetor).
/// @param ram endereço do vetor.
/// @param cont string contendo um pedaço do conteúdo do arquivo.
/// @param nomeArq string contendo o nome do arquivo.
/// @return retorna -1 se o vetor de ponteiros (memória) estiver cheia.
int inserir(Memória *ram, char *cont, char *nomeArq);

/// @brief utiliza a função de busca para achar a posição do arquivo na memória(vetor), e remove caso exista.
/// @param ram endereço do vetor.
/// @param nomeArq string contendo o nome do arquivo.
/// @return retorna -1 caso o arquivo não exista na memória(vetor).
int remover(Memória *ram, char *nomeArq);

/// @brief percorre a memória(vetor) procurando o arquivo pelo nome.
/// @param ram endereço do vetor.
/// @param nomeArq string contendo o nome do arquivo.
/// @return retorna o indíce do vetor contendo o primeiro nó do arquivo, ou -1 caso não exista na memória(vetor).
int buscar(Memória *ram, char *nomeArq);
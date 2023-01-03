#include "../ram_simulation/ram.h"

/// @brief recebe o caminho do arquivo e divide o conteúdo em partes de 128 caracteres, chamando a função de ram.h/inserir para cada parte.\n caso a memória(vetor) fique cheia durante a iserção dos nós, todos os nós relacionados aquele arquivo são removidos pela função ram.h/remover e é exibido uma mensagem de erro.
/// @param ram endereço do vetor.
/// @param nomeArq string contendo o nome do arquivo.
void lerArq(Memória *ram, char *nomeArq);

/// @brief chama a função ram.h/remover e exibe a mensagem de sucesso caso o retorno seja diferente de -1. 
/// @param ram endereço do vetor.
/// @param nomeArq string contendo o nome do arquivo.
void removerArq(Memória* ram, char *nomeArq);

/// @brief recebe o indíce do primeiro nó relacionado ao arquivo da função ram.h/buscar e imprime o endereço de todos os nós associados ao mesmo arquivo. 
/// @param ram endereço do vetor.
/// @param nomeArq string contendo o nome do arquivo.
void buscarArq(Memória* ram, char *nomeArq);

/// @brief função para ler o caminho do arquivo.
/// @return retorna o endereço.
char *lerCaminho();

/// @brief função para controle do terminal.
void enterVoltar();
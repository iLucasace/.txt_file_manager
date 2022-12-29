#include "../struct.h"

Memória* criarRAM();
Nó* criarNó(char *cont, char *nomeArq);
int inserir(Memória *ram, char *cont, char *nomeArq);
int remover(Memória *ram, char *nomeArq);
int buscar(Memória *ram, char *nomeArq);
#include "../struct.h"

Memória* criarRAM();
Nó* criarNó(char *cont, char *nomeArq);
void inserir(Memória *ram, char *cont, char *nomeArq);
void remover(Memória *ram, char *nomeArq);
int buscar(Memória *ram, char *nomeArq);
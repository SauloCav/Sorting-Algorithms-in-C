#include <stdio.h>
#include <stdlib.h>

typedef struct repositoriodeprodutos Repo;
typedef struct produto Prod;

Prod* criaProduto(int cod, float val);

Repo* criarRepositorio(int n);

int adicionar(Repo* re, int cod, float val);

void quickSort(Repo* re, int ini, int fim);

void esvaziar(Repo* re);

void printRespositorio(Repo* re);

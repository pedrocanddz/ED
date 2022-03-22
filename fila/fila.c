#include <malloc.h>
#include "fila.h"

void inicializa(fila *f)
{
    fila *start;
    start = malloc(sizeof(fila));
    start->prox = start; //determina fila vazia
}

int vazia(fila *f)
{
    if (f->prox == f)
        return 1;
    return 0;
}

void insere(fila *f, int val)
{
    fila *new;
    new = malloc(sizeof(fila));
    new->prox = f->prox;
    f->prox = new;
    f->valor = val;
}

int tira(fila *f)
{
    if(vazia(f) == 1)
        return;
    fila *remove;
    remove = f->prox;
    int x = remove->valor;
    f->prox = remove->prox;
    free(remove);
    return x;
}

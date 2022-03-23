#include <stdio.h>
#include <malloc.h>

#include "fila.h"

void inicializa(fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}
int vazia (fila *f)
{
    return f->inicio == NULL;
}
void insere(fila *f, int val)
{
    node *in = malloc(sizeof(node));
    in->valor = val;
    in->prox = NULL; // insere no fim
    if(f->fim != NULL)
        f->fim->prox = in;
    if(f->inicio == NULL) //1 elemento
        f->inicio = in;
    f->fim = in;
}
int tira(fila *f)
{
    if (!vazia(f)){
        
        node *out = f->inicio;
        int x = out->valor;
        f->inicio = out->prox;
        free(out);
        if(f->inicio == NULL)
            f->fim = NULL;  
        return x;  
    }
    return -1;
}
// void inicializa(fila *f)
// {
//     fila *start;
//     start = malloc(sizeof(fila));
//     start->prox = start; //determina fila vazia
// }

// int vazia(fila *f)
// {
//     if (f->prox == f)
//         return 1;
//     return 0;
// }

// void insere(fila *f, int val)
// {
//     fila *new;
//     new = malloc(sizeof(fila));
//     new->prox = f->prox;
//     f->prox = new;
//     new->valor = val;
// }

// int tira(fila *f)
// {
//     if(vazia(f) == 1){
//         printf("vazia");
//         return -1;
//     }
//     fila *remove;
//     remove = f->prox;
//     int x = remove->valor;
//     f->prox = remove->prox;
//     free(remove);
//     return x;
// }

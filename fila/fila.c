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
    if(f->fim != NULL) //caso em q tem mais de 1 elemento
        f->fim->prox = in;
    if(f->inicio == NULL) // caso em que tem nenhum elemento
        f->inicio = in;
    f->fim = in;
}
int tira(fila *f) // se fila nao estiver vazia
{                 // retiro o elemento no comeco da fila e retorno ele
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

void imprimeLista(fila *f)
{
    node *p;
    p = f->inicio;

    while (p != NULL)
    {
        if (p->prox != NULL) // formatacao da saida
            printf("%d ", p->valor);
        else
            printf("%d\n", p->valor);
        
        
        p = p->prox; // iteração pela fila
    }
    
}
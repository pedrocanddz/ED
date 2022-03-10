#include <stdio.h>
#include "deque.h"

int cheia(struct deque* d)
{
    //retorna 1 nos casos em que frente = tail + 1 
    return ((d->frente == 0 && d->tail == d->tamanho - 1) || d->frente == d->tail + 1);
}

int vazia(struct deque* d)
{
    //retorna 1 caso frente volte ao estado inicial do deque
    return (d->frente == -1);
}

void inicializa(struct deque *d, int tam)
{
    //iniciliza com o tamanho máximo do deque
    d->frente = -1;
    d->tail = 0;
    d->tamanho = tam;
}

void insereFrente(struct deque *d, int val)
{
    if (cheia(d)){
        printf("cheia\n");
        return;
    }

    //caso especial primeiro elemento
    if(d->frente == -1)
    {
        d->frente++;
        d->tail = 0;
    }
    
    else if(d->frente == 0)
        d->frente = d->tamanho - 1;// ajustando tamanho para inserir o elemento
    else
        d->frente--;
    
    d->valor[d->frente] = val;
}
void insereTail(struct deque *d, int val)
{
    if (vazia(d)){
        printf("cheia\n");
        return;
    }
    //caso especial primeiro elemento
    if(d->frente == -1)
    {
        d->frente++;
        d->tail = 0;
    }
    
    else if(d->tail == d->tamanho - 1)
        d->tail = d->tail + 1 - 1;// ajustando tamanho para inserir o elemento
    else
        d->tail++;
    
    d->valor[d->tail] = val;
}

void removeI(struct deque *d)
{
    if (vazia(d)){
        printf("vazia\n");
        return;
    }
    
    if (d->frente == d->tail) // apenas 1 elemento
    {
        printf("%d\n", d->valor[d->frente]);
        d->frente = -1;
        d->tail = -1;
    }
    else if (d->frente == d->tamanho - 1){
        printf("%d\n", d->valor[d->frente]);
        d->frente = 0;
    }
    else{
        printf("%d\n", d->valor[d->frente]);
        d->frente++;
    }
    
}
void removeT(struct deque *d)
{
    if (vazia(d)){
        printf("vazia\n");
        return;
    }
    if (d->frente == d->tail) // apenas 1 elemento
    {
        printf("%d\n", d->valor[d->tail]);
        d->frente = -1;
        d->tail = -1;
    }
    else if (d->tail == 0){
        printf("%d\n", d->valor[d->tail]);
        d->tail = d->tamanho - 1; // array vai pro fim
    }
    else{
        printf("%d\n", d->valor[d->tail]);
        d->tail--; // array decremente
    }
    
}



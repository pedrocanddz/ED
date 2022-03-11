#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"
void inicializa(deque *d, int t)
{
    d->valor = malloc(sizeof(int) * t);
    d->tamanhoT = t;
    d->tamanhoFila = 0;
    d->head = 0;
    d->tail = 0;
}

bool vazia(deque* d)
{
    return (d->tamanhoFila == 0);
}

bool cheia(deque* d)
{
    return (d->tamanhoFila == d->tamanhoT);
}

void insereT(deque *d, int val)
{
    printf("%d\n", !cheia(d));
    if(cheia(d)){
        printf("Fouses");
        return;
    }
    d->valor[d->tail] = val;
    d->tamanhoFila++;
    
    if(d->tail >= d->tamanhoT)
        d->tail = 0;
    else
        d->tail++;
}

void insereH(deque *d, int val)
{
    printf("%d\n",!cheia(d));
    if (cheia(d)){
        printf("Fouses");
        return;
    }
    d->valor[d->head] = val;
    d->tamanhoFila++;

    if(d->head <= 0)
        d->head = d->tamanhoT - 1;//final do array
    else
        d->head--;
}

void removeH(deque *d)
{
    printf("%d\n",!vazia(d));
    if(vazia(d)){
        printf("vazia\n");
        return;
    }

    printf("%d\n",d->valor[d->head]);
    if(d->head >= d->tamanhoT)
        d->head = 0;
    else
        d->head++;
    d->tamanhoFila--;
    
}
void removeT(deque *d)
{
    printf("%d\n", !vazia(d));
    if(vazia(d)){
        printf("vazia\n");
        return;
    }

    printf("%d\n",d->valor[d->tail]);
    if(d->tail <= 0)
        d->tail = d->tamanhoT - 1;
    else
        d->tail--;
    
    d->tamanhoFila--;
    
}
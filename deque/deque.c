#include <stdio.h>
#include "deque.h"
void inicializa(deque *d, int t)
{
    d->tamanhoT = t;
    d->tamanhoFila = 0;
    d->head = 0;
    d->tail = 0;
}

int vazia(deque* d)
{
    if(d->tamanhoFila == 0)
        return 1;
    return 0;
}

int cheia(deque* d)
{
    if(d->tamanhoFila == d->tamanhoT)
        return 1;
    return 0;
}

void insereI(deque *d, int val)
{
    if (cheia(d) == 1){
        printf("cheia\n");
        return;
    }

    if(d->head <= 0)
        d->head = d->tamanhoT - 1;//final do array
    else
        d->head--;
    d->valor[d->head] = val;
    d->tamanhoFila++;
}

void insereF(deque *d, int val)
{
    if(cheia(d) == 1){
        printf("cheia\n");
        return;
    }
    d->valor[d->tail] = val;
    d->tamanhoFila++;
    
    d->tail = (d->tail + 1) % d->tamanhoT;
}


void removeI(deque *d)
{
    if(vazia(d) == 1){
        printf("vazia\n");
        return;
    }
    
    printf("%d\n",d->valor[d->head]);
    if(d->head >= d->tamanhoT - 1)
        d->head = 0;
    else
        d->head++;
    d->tamanhoFila--;
    
}
void removeF(deque *d)
{
    if(vazia(d) == 1){
        printf("vazia\n");
        return;
    }

    if(d->tail <= 0)
        d->tail = d->tamanhoT - 1;
    else
        d->tail--;
    printf("%d\n",d->valor[d->tail]);
    
    d->tamanhoFila--;
    
}
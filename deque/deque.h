#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>


typedef struct
{
    int *valor;
    int head;
    int tail;
    int tamanhoT;
    int tamanhoFila;
} deque;

void inicializa(deque *d, int t);
bool vazia(deque* d);
bool cheia(deque* d);
void insereT(deque *d, int val);
void insereH(deque *d, int val);
void removeH(deque *d);
void removeT(deque *d);

#endif
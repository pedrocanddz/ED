#ifndef DEQUE_H
#define DEQUE_H


typedef struct
{
    int valor[550000];
    int head;
    int tail;
    int tamanhoT;
    int tamanhoFila;
} deque;

void inicializa(deque *d, int t);
int vazia(deque* d);
int cheia(deque* d);
void insereF(deque *d, int val);
void insereI(deque *d, int val);
void removeI(deque *d);
void removeF(deque *d);

#endif
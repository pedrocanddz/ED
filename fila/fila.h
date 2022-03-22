#ifndef FILA_H
#define FILA_H


typedef struct pos
{
    int valor;
    int tam;
    struct pos *prox;
} fila;

void inicializa(fila *f);
int vazia(fila *f);
void insere(fila *f, int val);
int tira(fila *f);

#endif
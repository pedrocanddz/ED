#ifndef FILA_H
#define FILA_H


typedef struct node
{
    int valor;
    struct node *prox;
} node;

typedef struct {
    node *inicio;
    node *fim;
} fila;

void inicializa(fila *f);
int vazia(fila *f);
void insere(fila *f, int val);
int tira(fila *f);
void imprimeLista(fila *f);

#endif
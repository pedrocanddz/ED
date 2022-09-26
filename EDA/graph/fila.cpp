#include <iostream>

typedef struct {
    int frente;
    int tras;
    int tamanho;
    int nElementos;
    int *array;
}fila;

fila* inicializarFila(int size){
    fila* f = (fila*) malloc(sizeof(fila));
    //fila* f = (fila*) calloc(1, sizeof(fila));
    
    f->array = (int*) malloc(sizeof(int) * size);
    f->tamanho = size;
    f->nElementos = 0;
    f->frente = 0;
    f->tras = size - 1;
    return f;
}

void destroiFila(fila *f){
    free(f->array);
}

int vazia(fila *f){
    return f->nElementos == 0;
}

void insereFila(fila *f, int val){
    f->tras = (f->tras + 1) % f->tamanho;
    f->array[f->tras] = val;
    f->nElementos ++;
}

int retiraFila(fila *f){
    int item = f->array[f->frente];
    f->frente = (f->frente + 1) % f->tamanho;
    f->nElementos --;
    return item;
}
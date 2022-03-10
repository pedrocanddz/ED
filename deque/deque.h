#ifndef DEQUE_H
#define DEQUE_H


struct deque
{
    int valor[550000];
    int tail;
    int frente;
    int tamanho;  
};

int cheia(struct deque* d);
int vazia(struct deque* d);
void inicializa(struct deque *d, int tam);
void insereFrente(struct deque *d, int val);
void insereTail(struct deque *d, int val);
void removeI(struct deque *d);
void removeT(struct deque *d);


#endif
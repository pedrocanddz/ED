#ifndef DEQUE_H
#define DEQUE_H

typedef struct node{
    int valor;
    struct node* prev;
    struct node* next;
}node;

typedef struct deque
{
    struct node* head;
    struct node* end;  
    int elementos;
}deque;

int vazia(deque* d);
void inicializa(deque* d);
void insereInicio(deque* d, int val);
void insereFim(deque* d, int val);
void deleteInicio(deque *d);
void deleteLast(deque *d);

#endif
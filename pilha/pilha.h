#ifndef PILHA_H
#define PILHA_H

int bemFormada (char s[], int tam);
void initialize (int *t);
void push (char y, char pilha[], int *t);
char pop (char pilha[], int *t);
int empty (int *t);

#endif
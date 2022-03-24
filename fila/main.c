//Atividade 11
//Aluno : Pedro Henrique Candido de Sousa
//RA    : 800863

#include <stdio.h>
#include "fila.h"

void reverte(fila *f)
{
    if(vazia(f)) // caso base
        return;
    int x = tira(f);
    reverte(f);
    insere(f, x);
}  

int main()
{
    fila f;
    inicializa(&f);
    int num;
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++)
    {
        int x;
        scanf("%d", &x);
        insere(&f, x);
    }

    reverte(&f);
    imprimeLista(&f);

    return 0;
}
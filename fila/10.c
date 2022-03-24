#include <stdio.h>
#include "fila.h"

void reverte(fila *f)
{
    if(vazia(f))
        return;
    int x = tira(f);
    reverte(f);
    printf("%d\n", x);
}

int main()
{
    fila f;
    inicializa(&f);
    insere(&f, 8);
    insere(&f, 7);
    insere(&f, 6);
    reverte(&f);
    // printf("%d\n", tira(&f));
    // printf("%d\n", tira(&f));
    // printf("%d\n", tira(&f));
    return 0;
}
#include <stdio.h>
#include "fila.h"

int main()
{
    fila f;
    inicializa(&f);
    insere(&f, 8);
    insere(&f, 7);
    insere(&f, 6);
    printf("%d\n", tira(&f));
    printf("%d\n", tira(&f));
    printf("%d\n", tira(&f));
    return 0;
}
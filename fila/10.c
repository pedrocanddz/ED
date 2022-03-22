#include <stdio.h>
#include "fila.h"

int main()
{
    fila f;
    inicializa(&f);
    insere(&f, 8);
    printf("%d %d\n", tira(&f), tira(&f));

    return 0;
}
#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main()
{
    char c[100000];
    int testes;
    scanf("%d", &testes);

    // for(int i = 0; i < testes; i++)
    // {
    //     scanf("%s", &c);
    // }
    for(int i = 0 ; i < testes; i++){
    scanf("%s", &c[0]);

    //printf("%s\n", c);
    
    if(bemFormada(c, strlen(c)))
        printf("S\n");
    else
        printf("N\n");
    }
    return 0;
}

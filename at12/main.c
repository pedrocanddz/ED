#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "deque.h"

int main()
{
    int val, n, m;
    char func[8];
    deque d;
    inicializa(&d);

    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n ; i++)
    {
        int funcint = 0;
        scanf("%s", func);

        if(strcmp(func, "insereI") == 0){
            funcint = 1;
        }
        else if(strcmp(func, "insereF") == 0){
            funcint = 2;
        }
        else if(strcmp(func, "removeI") == 0){
            funcint = 3;
        }
        else{
            funcint = 4;
        }
        switch (funcint)
        {
        case 1: // insereI
            scanf(" %d", &val);
            insereInicio(&d, val);
            break;       
        case 2: // insereF
            scanf("%d", &val);
            insereFim(&d, val);
            break;     
        case 3: // removeI
            deleteInicio(&d);
            break;     
        case 4: // removeF
            deleteLast(&d);
            break;
        }
    }

    return 0;
}
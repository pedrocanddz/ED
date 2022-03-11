#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "deque.h"

int main()
{
    int val = 0, n, m;
    char func[8];
    
    deque d;
    inicializa(&d, m);

    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n ; i++)
    {
        int funcint = 0;
        scanf("%s", &func);

        if(strcmp(func, "insereH") == 0){
            scanf(" %d", &val);
            insereH(&d, val);
        }
        else if(strcmp(func, "insereT") == 0){
            scanf("%d", &val);
            insereT(&d, val);
        }
        else if(strcmp(func, "removeH") == 0){
            removeH(&d);
        }
        else{
            removeT(&d);
        }
    }

    return 0;
}
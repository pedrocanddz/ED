#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "deque.h"

int main()
{
    int val = 0, n, m;
    char func[8];
    
    struct deque d;
    inicializa(&d, m);

    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n ; i++)
    {
        int funcint = 0;
        scanf("%s", &func);

        if(strcmp(func, "insereI") == 0){
            scanf(" %d", &val);
            insereFrente(&d, val);
        }
        else if(strcmp(func, "insereF") == 0){
            scanf("%d", &val);
            insereTail(&d, val);
        }
        else if(strcmp(func, "removeI") == 0){
            removeI(&d);
        }
        else{
            removeT(&d);
        }
    }

    return 0;
}
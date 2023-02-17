#include <stdio.h>
#include <string.h>
#include "deque.h"

int main()
{
    int val = 0, n, m;
    char func[8];
    
    deque d;

    scanf("%d %d", &n, &m);
    inicializa(&d, m);
    
    for(int i = 0; i < n ; i++)
    {
        scanf("%s", func);

        if(strcmp(func, "insereI") == 0){
            scanf(" %d", &val);
            insereI(&d, val);
        }
        else if(strcmp(func, "insereF") == 0){
            scanf("%d", &val);
            insereF(&d, val);
        }
        else if(strcmp(func, "removeI") == 0){
            removeI(&d);
        }
        else{
            removeF(&d);
        }
    }

    return 0;
}
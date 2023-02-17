#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "deque.h"

int main()
{
    int val, n, m;
    char func[8];
    struct deque* head = NULL;

    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n ; i++)
    {
        int funcint = 0;
        int tam = tamanhoDeque(head);
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
        if(tam >= m){
            printf("cheia\n");
            break;
        }
            insereInicio(&head, val);
            break;       
        case 2: // insereF
            scanf("%d", &val);
        if(tam >= m){
            printf("cheia\n");
            break;
        }
            insereFim(&head, val);
            break;     
        case 3: // removeI
        if(tam == 0){
            printf("vazia\n");
            break;
        }       
            deleteInicio(&head, head);
            break;     
        case 4: // removeF
        if(tam == 0){
            printf("vazia\n");
            break;
        }
            deleteLast(&head, head);
            break;
        }
    }

    return 0;
}
#include <stdio.h>
#include <malloc.h>
#include <string.h>


struct deque
{
    int valor;
    struct deque* before;
    struct deque* next;  
};

void insereInicio(struct deque** head, int val);
void insereFim(struct deque** head, int val);
int tamanhoDeque(struct deque* deque);
void deleteInicio(struct deque** head, struct deque* home);
void deleteLast(struct deque** head, struct deque* last);

int main()
{
    int val, n, m;
    char func[8];
    struct deque* head = NULL; //head do deque

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
        if(tamanhoDeque(head) >= m){
            printf("cheio");
            break;
        }
            insereInicio(&head, val);
            break;       
        case 2: // insereF
            scanf("%d", &val);
        if(tamanhoDeque(head) >= m){
            printf("cheio");
            break;
        }
            insereFim(&head, val);
            break;     
        case 3: // removeI
        if(tamanhoDeque(head) == 0){
            printf("vazio");
            break;
        }       
            deleteInicio(&head, head);
            break;     
        case 4: // removeF
        if(tamanhoDeque(head) == 0){
            printf("vazio");
            break;
        }
            deleteLast(&head, head);
            break;
        }
    }
}
void insereInicio(struct deque** head, int val)
{
    struct deque* new_deque = (struct deque*)malloc(sizeof(struct deque));
 
    new_deque->valor = val;
 
    new_deque->next = (*head);
    new_deque->before = NULL;
 
    if ((*head) != NULL)
        (*head)->before = new_deque;

    (*head) = new_deque;
}

void insereFim(struct deque** head, int val)
{
    struct deque* new_deque
        = (struct deque*)malloc(sizeof(struct deque));
 
    struct deque* last = *head;
 
    new_deque->valor = val;
 
    new_deque->next = NULL;

    if (*head == NULL) {
        new_deque->before = NULL;
        *head = new_deque;
        return;
    }
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_deque;
 
    new_deque->before = last;
 
    return;
}
int tamanhoDeque(struct deque* deque)
{
    int tam = 0;
    struct deque* next;
    while(deque != NULL)
    {
        next = deque;
        deque = deque->next;
        tam++;
    }
    return tam;

}

void deleteLast(struct deque** head, struct deque* last)
{
    while (last->next != NULL) {
        last = last->next;
    }
    if (*head == last)
        *head = last->next;

    printf("%d\n", last->valor);

    if(last->before != NULL){
        last->before->next = NULL;
    }

    free(last);

}
void deleteInicio(struct deque** head, struct deque* home)
{
    if (*head == home)
        *head = home->next;
 
    if (home->next != NULL)
        home->next->before = home->before;

    if (home->before != NULL)
        home->before->next = home->next;

    printf("%d\n", home->valor);

    free(home);
    return;
}


#include <stdio.h>
#include <malloc.h>
#include "deque.h"

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
    struct deque* new_deque = (struct deque*)malloc(sizeof(struct deque));
 
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
    while(deque != NULL)
    {
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
#include <stdio.h>
#include <malloc.h>
#include "deque.h"

int vazia(deque* d)
{
    return (d->head == NULL);
}

void inicializa(deque* d)
{
    d->head = NULL;
    d->end = NULL;
    d->elementos = 0;
}
void insereInicio(deque* d, int val)
{
    node* nova_node = (node*)malloc(sizeof(node));
 
    nova_node->valor = val;
    nova_node->prev = NULL;
    if(d->head == NULL)
        nova_node->next = NULL;
    
    if (d->head != NULL)
        d->head->prev = nova_node;
    d->elementos++;
    d->head = nova_node;
}

void insereFim(deque* d, int val)
{
    node* n = (node*)malloc(sizeof(node));
 
 
    n->valor = val;
 
    n->next = NULL;

    if (d->head == NULL) {
        n->prev = NULL;
        d->head = n;
        return;
    }
    
    d->end->next = n;
    d->elementos++;
    n->prev = d->end;
 
    return;
}

void deleteLast(deque *d)
{
    // while (last->next != NULL) {
    //     last = last->next;
    // }
    // if (head == last)
    //     head = last->next;
    if(vazia(d)){
        printf("vazia\n");
        return;
    }
    node *remove = d->end;
    printf("%d\n", remove->valor);

    if(remove->prev != NULL){
        remove->prev->next = NULL;
    }

    free(remove);

}
void deleteInicio(deque *d)
{
    node *n = d->head;
    if(vazia(d)){
        printf("vazia\n");
        return;
    }
    
    if (n->next == NULL)
        d->head = NULL;
    else{
        d->head = n->next;
    }
    printf("%d\n", n->valor);

    free(n);
    return;
}
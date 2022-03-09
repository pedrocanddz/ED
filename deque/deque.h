#ifndef DEQUE_H
#define DEQUE_H


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

#endif
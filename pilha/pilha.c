#include <stdio.h>
#include "pilha.h"

int bemFormada (char s[], int tam) 
{
    int pos;
    char pilha[100000] = {0};
   initialize (&pos);
   for (int i = 0; i < tam; i++) {
      char c;
      switch (s[i]) {
         case ')':if (empty (&pos)) 
                     return 0;
                  c = pop (pilha, &pos);
                  if (c != '(') 
                     return 0;
                  break;
         case ']':if (empty (&pos)) 
                     return 0;
                  c = pop (pilha, &pos);
                  if (c != '[') 
                     return 0;
                  break;
         case '}':if(empty(&pos)) 
                     return 0;
                  c = pop(pilha, &pos);
                  if(c != '{') 
                     return 0;
                   
                  break;
         default:  push (s[i], pilha, &pos);
         break;
      }
   }
   return empty (&pos);
}

void initialize (int *pos) {
   *pos = 0;
}

void push (char c, char pilha[], int *pos) {
   pilha[(*pos)++] = c;
}

char pop (char pilha[], int *pos) {
   return pilha[--*pos];
} 

int empty (int *pos) {
   return *pos <= 0;
}
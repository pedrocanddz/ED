#include <iostream>
//Atividade 3
//Nome: Pedro Henrique Candido de Sousa 
//RA: 800863
typedef struct node{
    char dado;
    struct node *esq, *dir;
}node;


using namespace std;

node* newNode(char valor);
void destroy(node* root);
node* constroiArvore(char in[], char pre[], int intervaloMin, int intervaloMax, int tamanho_total, int* pre_index);
void pos_order( node *p );
int main()
{
    int n;
    char *in_ordem, *pre_ordem;
    int testes;
    cin >> testes;
    
    for(int i = 0; i < testes; i++){
        cin >> n;
        pre_ordem = (char*) malloc(sizeof(char) * n);
        in_ordem = (char*) malloc(sizeof(char) * n);

        for(int i = 0; i < n; i++)
            cin >> pre_ordem[i];
        for(int i = 0; i < n; i++)
            cin >> in_ordem[i];
        int pre_index = 0;
        int *ponteiro_index = &pre_index;
        node* root = constroiArvore(in_ordem, pre_ordem,  0, n - 1, n, ponteiro_index);

        pos_order(root);
        cout << endl;
        free(pre_ordem);
        free(in_ordem);
        destroy(root);
    }
    return 0;
}

node* newNode(char valor)
{
    node* no = (node *) malloc(sizeof(node*));
    no->dado = valor;
    no->dir = no->esq = NULL;
    return no;
}

void destroy(node* root)
{
    if(root){

        destroy(root->esq);
        destroy(root->dir);
        free(root);
    }
    return;
}

node* constroiArvore(char in[], char pre[], int intervaloMin, int intervaloMax, int tamanho_total, int* pre_index)
{
    //n = 6
    //pre_ordem[A, B, C, D, E, F]
    //pré ordem mostr a raiz de cada sub arvore
    //in_ordem[C, B, A, E, D, F]
    //em um ponto qualquer do array acima, todos os pontos antes dele estão a sua esquerda e os pontos depois estão na direita
    //          A
    //         / \'
    //        B   D
    //      /    / \'
    //     C    E   F
    if(intervaloMin > intervaloMax)
        return NULL;
    
    char valor = pre[(*pre_index)++]; // ponteiro necessario para recursão

    node* no = newNode(valor);
    


    if(intervaloMin == intervaloMax) 
        return no;
    
    int index_in;
    for(int i = intervaloMin; i <= intervaloMax; i++)
        if(in[i] == valor){
            index_in = i;
            break;
        }

    no->esq = constroiArvore(in, pre, intervaloMin, index_in - 1, tamanho_total, pre_index); // todos os elementos a esquerda do ponto
    no->dir = constroiArvore(in, pre, index_in + 1, intervaloMax, tamanho_total, pre_index); // todos os elementos a direita do ponto
    
    return no;
}

void pos_order( node *p ) {
    if( p ) {
    pos_order(p->esq);
    pos_order(p->dir);
    cout << p->dado;
    }
    return;
}  
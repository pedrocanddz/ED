#include <iostream>
/*Atividade 4
*Nome: Pedro Henrique Candido de Sousa
*RA: 800863
*/


typedef struct node {
    int data;
    int level;
    struct node *left;
    struct node *right;
} node;

void preordem(node* root);// função que imprime a árvore em pré-ordem
void inordem(node* root);// função que imprime a árvore em in-ordem
void posOrdem(node* root);// função que imprime a árvore em pos-ordem
node* inicializa(int val);// retorna um nó inicializado
node* insere(node* root, node* p, int level); // insere novo nó na árvore de forma ordenada
int maxHeight(node *root); // retorna a maior altura da arvore
void inNivel(node* root, int level); // imprime os nós de um nível específico buscando na árvore

using namespace std;

int main(){
    node *root = NULL;
    int n;
    cin >> n;

    //inicializa e insere um nó na árvore
    for(int  i = 0; i < n; i++){
        int x;
        cin >> x;
        node* inserir = inicializa(x);
        root = insere(root, inserir, 1);
    }

    cout << "Pr.:";
    preordem(root);
    cout << endl;

    cout << "In.:";
    inordem(root);
    cout << endl;

    cout << "Po.:";
    posOrdem(root);
    cout << endl;
    cout << "Ni.:";
    //para cada nível da árvore, imprime todos os nós do nível
    for(int i = 1; i <= maxHeight(root); i++)
        inNivel(root, i);
    cout << endl;

    return 0;
}
int maxHeight(node *root){
    if(root == NULL)
        return 0;
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
}
void inNivel(node* root, int level){
    if(root == NULL)
        return;
    if(root->level == level){
        cout << " " << root->data ;
    }else{
    inNivel(root->left, level);
    inNivel(root->right, level);
    }

}
void preordem(node* root){
    if(root){
        cout << " " << root->data ;
        preordem(root->left);
        preordem(root->right);
    }
}
void inordem(node* root)
{
    if(root){
        inordem(root->left);
        cout << " " << root->data ;
        inordem(root->right);
    }
}
void posOrdem(node* root){
    if(root){
        posOrdem(root->left);
        posOrdem(root->right);
        cout << " " << root->data ;
    }
}

node* inicializa(int val)
{
    node* p = (node *)malloc(sizeof(node));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

node* insere(node* root, node* p, int level){
    if(root == NULL){
        p->level = level;
        root = p;
    }
    else{
        if(p->data < root->data){
            root->left = insere(root->left, p, ++level);
        }
        else{
            root->right = insere(root->right, p, ++level);
        }
    }
    return root;
}

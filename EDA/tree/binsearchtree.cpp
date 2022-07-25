#include <iostream>


typedef struct node {
    int data;
    int level;
    struct node *left;
    struct node *right;
} node;
void preordem(node* root);
void inordem(node* root);
void posOrdem(node* root);
node* inicializa(int val);
node* insere(node* root, node* p, int level);
int maxHeight(node *root);
using namespace std;
int main(){
    node *root = NULL;
    int n;
    cin >> n;
    for(int  i = 0; i < n; i++){
        int x;
        cin >> x;
        node* inserir = inicializa(x);
        root = insere(root, inserir, 1);
    }
    cout << "Pr.: ";
    preordem(root);
    cout << endl;

    cout << "In.: ";
    inordem(root);
    cout << endl;

    cout << "Po.: ";
    posOrdem(root);
    cout << endl;
    cout << (maxHeight(root)) << endl;

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
        cout << root->data << " ";
    }else{
        inNivel(root->left, level);
        inNivel(root->right, level);
    }
}
void preordem(node* root){
    if(root){
        cout << root->data << " ";
        preordem(root->left);
        preordem(root->right);
    }
}
void inordem(node* root)
{
    if(root){
        inordem(root->left);
        cout << root->data << " ";
        inordem(root->right);
    }
}
void posOrdem(node* root){
    if(root){
        posOrdem(root->left);
        posOrdem(root->right);
        cout << root->data << " ";
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

#include <iostream>


typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;
void preordem(node* root);
void inordem(node* root);
void posOrdem(node* root);
node* inicializa(int val);
node* insere(node* root, node* p);

using namespace std;
int main(){
    node *root = NULL;
    int n;
    cin >> n;
    for(int  i = 0; i < n; i++){
        int x;
        cin >> x;
        node* inserir = inicializa(x);
        root = insere(root, inserir);
    }
    preordem(root);
    cout << endl;
    inordem(root);
    cout << endl;
    posOrdem(root);
    cout << endl;
    return 0;
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

node* insere(node* root, node* p){
    if(root == NULL){
        root = p;
    }
    else{
        if(p->data < root->data){
            root->left = insere(root->left, p);
        }
        else{
            root->right = insere(root->right, p);
        }
    }
    return root;
}

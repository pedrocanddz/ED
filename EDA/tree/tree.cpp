#include <iostream>
#include <string>
typedef struct node{
    int num;
    struct node *left;
    struct node *right;
    struct node *pai;
}node;

typedef struct tree{
    int num;
    struct tree *child;
    struct tree *pai;
}tree;

void iniciliarTree(tree a[], int i, int n)
{
    a[i].num = i + 1;
    a[i].child = (tree *) malloc(sizeof(tree) * n);
    a[i].pai = NULL;
}

using namespace std;

void iniciliza(node root[], int i);
void linkaNode(node a[], int n1, int n2);
void removeNode(node a[], int n);
int lowestCommomAncestor(node a[], int n1, int n2, int t);

int main()
{
    int n, m;
    cin >> n >> m;

    node *tree = new node [n]; 

    for(int  i = 0 ; i < n; i++)
        iniciliza(tree, i);

    // cout << lowestCommomAncestor(tree, 1, 1, n) << endl;
    // linkaNode(tree, 1, 2);
    // linkaNode(tree, 3, 2);
    // linkaNode(tree, 4, 3);
    // cout << lowestCommomAncestor(tree, 1, 4, n) << endl;
    // cout << lowestCommomAncestor(tree, 3, 4, n) << endl;
    // removeNode(tree, 4);
    // linkaNode(tree, 5, 3);
    // cout << lowestCommomAncestor(tree, 1, 5, n) << endl;
    string function;
    int x = 0, y = 0;
    for(int  i = 0; i < m; i++)
    {
        cin >> function ;
        if(function.compare("lca") == 0){
            cin >> x >> y;
            printf("%d\n", lowestCommomAncestor(tree, x, y, n));
        }        
        if(function.compare("link") == 0){
            cin >> x >> y;
            linkaNode(tree, x, y);
        }
        if(function.compare("cut") == 0){
            cin >> x;
            removeNode(tree,  x);
        }
    }


    return 0;
}

void iniciliza(node root[], int i){
    root[i].num = i + 1;
    root[i].left = NULL;
    root[i].right = NULL;
    root[i].pai = NULL;
}

void linkaNode(node a[], int n1, int n2)
{
    int filho = n1 - 1;
    int pai = n2 - 1;
    if(a[pai].left != NULL){
        a[filho].pai = &a[pai];
        if(a[filho].pai->left != NULL){
            a[filho].pai->right = &a[filho];
        }
        else{
            a[filho].pai->left = &a[filho];
        }
    }else{
        a[filho].pai = &a[pai];
        if(a[filho].pai->left != NULL){
            a[filho].pai->right = &a[filho];
        }
        else{
            a[filho].pai->left = &a[filho];
        }
    }
}

void removeNode(node a[], int n)
{
    node *cut = &a[n - 1];
    if(cut->pai->left == cut){
        cut->pai->left = NULL;
    }else{
        cut->pai->right = NULL;
    }

    a[n - 1].pai = NULL;

}

int lowestCommomAncestor(node a[], int n1, int n2, int t)
{
    int *path_n1 = new int [t];
    int *path_n2 = new int [t];
    node *path1 = &a[n1 - 1];
    node *path2 = &a[n2 - 1];
    int i = 0;
    while(path1->pai != NULL){
        path_n1[i++] = path1->num; 
        path1 = path1->pai;
    }   
    path_n1[i] = path1->num;
    int j = 0;
    while(path2->pai != NULL){   
        path_n2[j++] = path2->num; 
        path2 = path2->pai;
    }
    path_n2[j] = path2->num;
    
    int raiz = path_n1[i];
    //cout << path_n1[i - 1] << " " << path_n2[j - 1] << endl;
    while (path_n1[i--] == path_n2[j--])
    {
        raiz = path_n1[i + 1];
    }
    free(path_n1);
    free(path_n2);
    return raiz;
}
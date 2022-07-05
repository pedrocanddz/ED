#include <iostream>
#include <string>

typedef struct tree
{
    int num;
    struct tree *child;
    struct tree *pai;
} tree;

using namespace std;

void inicializaTree(tree a[], int i, int n);
void linkaTree(tree a[], int n1, int n2);
void removeTree(tree a[], int n);
int lowestCommomAncestor(tree a[], int n1, int n2, int t);

int main()
{
    int n, m;
    cin >> n >> m;

    // node *tree = new node [n];
    tree *a = new tree[n];

    for (int i = 0; i < n; i++)
        inicializaTree(a, i, n);

    string function;
    int x = 0, y = 0;
    for(int  i = 0; i < m; i++)
    {
        cin >> function ;
        if(function.compare("lca") == 0){
            cin >> x >> y;
            printf("%d\n", lowestCommomAncestor(a, x, y, n));
        }
        if(function.compare("link") == 0){
            cin >> x >> y;
            linkaTree(a, x, y);
        }
        if(function.compare("cut") == 0){
            cin >> x;
            removeTree(a,  x);
        }
    }

    return 0;
}

void inicializaTree(tree a[], int i, int n)
{
    a[i].num = i + 1;
    a[i].child = new tree[n];
    a[i].pai = NULL;
}
void linkaTree(tree a[], int n1, int n2)
{
    int filho = n1 - 1;
    int pai = n2 - 1;

    a[filho].pai = &a[pai];
    a[pai].child[filho] = a[filho];
}

void removeTree(tree a[], int n)
{
    int index = n - 1;
    tree *cut = &a[index]; 
    cut->pai = NULL;
    
}
int lowestCommomAncestor(tree a[], int n1, int n2, int t)
{
    int *path_n1 = new int [t];
    int *path_n2 = new int [t];
    tree *path1 = &a[n1 - 1];
    tree *path2 = &a[n2 - 1];
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
    while (path_n1[i] == path_n2[j] && i >= 0 && j >= 0)
    {
        i--;
        j--;
    }
        raiz = path_n1[i];
    free(path_n1);
    free(path_n2);
    return raiz;
}
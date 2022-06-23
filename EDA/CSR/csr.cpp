#include <iostream>

using namespace std;

typedef struct{
    int row,col,dado;
}matrix;

int achaPos(int a[], int b[], int c[],int k, int x, int y);
void printaCSR(int a[], int b[], int c[], int k, int m);
void ordenaMatrix(matrix a[], int k);

int main ()
{   
    int k, col, row, dado;
    cin >> k;
    

    int *a = new int [k] ;
    int *b = new int [k];
    int *c = new int [k] {};
    matrix *m = (matrix *)malloc(sizeof(matrix) * k);
    
    for(int i = 0; i < k; i++){
		cin >> m[i].row >> m[i].col >> m[i].dado;
	}

    ordenaMatrix(m, k);

    for(int i = 0; i < k; i++){
        a[i] = m[i].dado;
        b[i] = m[i].col;
        c[m[i].row + 1]++;
    }

    for(int i = 1; i <= m[k - 1].row + 1; i++) // Soma progressiva o argumento R
        c[i] = c[i-1] + c[i];   
    
    //printaCSR(a, b, c, k, m[k - 1].row + 1);

    int x , y;
    do
    {
        
        cin >> x >> y;  // x e y sao as coordenadas da matriz
        if(x == -1 && y == -1)
            break;
        printf("(%d,%d) = %d\n", x, y, achaPos(a, b, c, k, x, y));
    } while (x != -1 && y != -1);
    

    free(m);
    free(a);
    free(b);
    free(c);
    
    return 0;
}
int achaPos(int a[], int b[], int c[], int x, int y)
{
    int intervalo = c[x] - c[x+1];
    int valor = 0;
    if(intervalo == 0)
        return 0;
    else
    {
        for(int i = b[c[x]]; i < b[c[x + 1] - 1]; i++)
        {
            if(b[i] == y)
            {
                valor = a[i];
                break;
            }
        }
        return valor;
    }
}

int achaPos(int a[], int b[], int c[], int k, int x, int y){
    int intervalo = c[x] - c[x + 1];
    int valor = 0;
    if(intervalo == 0)
        return 0;
    for(int i = c[x]; i < c[x + 1]; i++){
        int comp = b[i];
            if(comp == y){
                valor = a[i];
                break;
            }
    }
    return valor;
}
void printaCSR(int a[], int b[], int c[], int k, int m)
{
        cout << "A = ";
    for(int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << "B = ";
        for(int i = 0; i < k; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl << "R = ";
        for(int i = 0; i < m + 1; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}
void ordenaMatrix(matrix a[], int k)
{
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(a[i].row < a[j].row || (a[i].row == a[j].row && a[i].col < a[j].col))
            {
                matrix aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}
#include <iostream>

using namespace std;

typedef struct{
    int row,col,dado;
}matrix;

int achaPos(int a[],int b[], int c[], int x, int y);
void printaCSR(int a[], int b[], int c[], int k, int m);
void ordenaMatrix(matrix a[], int k);

int main ()
{   
    int k, col, row, dado;
    cin >> k;
    int a[100000], b[100000], c[100000]= {0};
    matrix *m = (matrix *)malloc(sizeof(matrix) * k);
    
    for(int i = 0; i < k; i++){
		cin >> m[i].row >> m[i].col >> m[i].dado;
	}
    ordenaMatrix(m, k);
    cout << endl;
    for(int i = 0; i < k; i++){
        a[i] = m[i].dado;
        b[i] = m[i].col;
        c[m[i].row + 1]++;
    
    //    cout << m[i].row << " " << m[i].col << " " << m[i].dado << endl;
    }
    //printaCSR(a, b, c, k);
    int x, y;

    do
    {
        cin >> x >> y;
        printf("(%d,%d) = %d\n", x, y, achaPos(a, b, c, x, y));    

    } while (x != -1 && y != -1);
    int u = m[k - 1].row;  
    printaCSR(a, b, c, k, u);

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
            if(a[i].row < a[j].row && a[i].col < a[j].col)
            {
                matrix aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}
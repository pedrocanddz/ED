#include <iostream>

using namespace std;

typedef struct{
    int row,col,dado;
}matrix;

void printaCSR(int a[], int b[], int c[], int k);
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
        
        cout << m[i].row << " " << m[i].col << " " << m[i].dado << endl;
    }
    //printaCSR(a, b, c, k);


    return 0;
}

void printaCSR(int a[], int b[], int c[], int k)
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
        for(int i = 0; i < k; i++)
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
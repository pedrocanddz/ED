#include <iostream>

using namespace std;

typedef struct{
    int row,col,dado;
}matrix;

void printaCSR(int a[], int b[], int c[], int k);

int main ()
{   
    int k, col, row, dado;
    cin >> k;
    int a[100000], b[100000], c[100000]= {0};
    int d[100000]= {0};
    matrix *m = (matrix *)malloc(sizeof(matrix) * k);
    
    printaCSR(a, b, c, k);


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
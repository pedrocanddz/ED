//Atividade 01
//Nome: Pedro Henrique Candido de Sousa
//RA: 800863
#include <iostream>

using namespace std;

typedef struct{
    int row,col,dado;
}matrix;

int achaPos(int a[], int b[], int c[],int k, int x, int y, int linhas);
void mergeMatriz(matrix a[], int esq, int meio, int dir);
void mergeSortMatriz(matrix a[], int esq, int dir);
int main ()
{   
    int k, col, row, dado;
    cin >> k;

    matrix *m = (matrix *)malloc(sizeof(matrix) * k);
    
    for(int i = 0; i < k; i++)
		cin >> m[i].row >> m[i].col >> m[i].dado;

    mergeSortMatriz(m, 0, k-1); // Ordena a entrada para inserir nos vetores CSR

    int linhas = m[k-1].row; //Ultimo valor da matriz representa o valor máximo de linhas
    int *a = new int [k] ;
    int *b = new int [k];
    int *c = new int [linhas + 2] {};

    for(int i = 0; i < k; i++){
        a[i] = m[i].dado;
        b[i] = m[i].col;
        c[m[i].row + 1]++;
    }   

    for(int i = 1; i <= linhas + 1; i++)
        c[i] = c[i-1] + c[i];   
    
    int x , y;
    do
    {
        cin >> x >> y;  // x e y sao as coordenadas da matriz
        if(x == -1 && y == -1)
            break;
        printf("(%d,%d) = %d\n", x, y, achaPos(a, b, c, k, x, y, linhas + 1));
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

int achaPos(int a[], int b[], int c[], int k, int x, int y, int linhas){//Recebe uma cordenada x,y e retorna o valor na matriz CSR, caso não ache retorna 0
    if(x > linhas)
        return 0;
    int valor = 0;
    for(int i = c[x]; i < c[x + 1]; i++){
        int comp = b[i];
            if(comp == y){
                valor = a[i];
                break;
            }
    }
    return valor;
}

void mergeMatriz(matrix a[], int esq, int meio, int dir) //junta as matrizes ordenando por linha e depois coluna
{
    int i, j, k;
    int left_index = meio - esq + 1;
    int right_index = dir - meio;
    //Matrizes temporarias esquerda e direita
    matrix *L = (matrix *)malloc(sizeof(matrix) * left_index); 
    matrix *R = (matrix *)malloc(sizeof(matrix) * right_index);
    for(i = 0; i < left_index; i++)
        L[i] = a[esq + i];
    for(j = 0; j < right_index; j++)
        R[j] = a[meio + 1 + j];
    i = 0;
    j = 0;
    k = esq;
    while(i < left_index && j < right_index)
    {
        if(L[i].row < R[j].row || (L[i].row == R[j].row && L[i].col <= R[j].col))
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < left_index)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < right_index)
    {
        a[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void mergeSortMatriz(matrix a[], int esq, int dir) //Merge Sort recursivo
{
    if(esq < dir)
    {
        int meio = (esq + dir) / 2;
        mergeSortMatriz(a, esq, meio);
        mergeSortMatriz(a, meio + 1, dir);
        mergeMatriz(a, esq, meio, dir);
    }
}



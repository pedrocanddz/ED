/* Atividade 8, Porcas e Parafusos
Nome: Pedro Henrique Candido de Sousa
RA: 800863*/

#include <stdio.h>

void pareia(int A[], int B[], int n);
int partition(int v[], int vb[], int imin, int imax);
void quickSort(int v[], int vb[], int imin, int imax);

int main()
{
    int i=0;
    int parafuso[200000]={0}, porcas[200000]={0};
    int nTotal=0;

    scanf("%d", &nTotal);
    
    for(i = 0; i < nTotal; i++)
        scanf("%d", &porcas[i]);
    for(i = 0; i < nTotal; i++)
        scanf("%d", &parafuso[i]);

    // pareia(porcas, parafuso, nTotal);
    quickSort(porcas, parafuso, 0 ,nTotal - 1);

    for(i = 0; i < nTotal; i++){
        printf("%d - %d\n", porcas[i], parafuso[i]);
    }

    return 0;
}

void pareia(int A[], int B[], int n)//faz os pares com os dois vetores
{
  int aux;
  for(int i = 0; i < n; i ++){
    int k = i;
    while (B[i] != A[k]){
      k++;
    }
    aux = A[i];
    A[i] = A[k]; 
    A[k] = aux;
  }
}

int partition(int v[], int vb[], int imin, int imax)
{ // pivo

  int pivob = vb[imax];
  int i = imin;
  int ia = imin;
  int aux, auxb;
  for (int j = imin; j < imax; j++)
  {
    if (v[j] <= pivob ){
      aux = v[j];
      v[j] = v[i];
      v[i] = aux;

      // auxb = v[j];
      // v[j] = vb[i];
      // vb[i] = auxb;

      i++;
    }
  }
  aux = v[i];
  v[i] = vb[imax];
  vb[imax] = aux;

  int pivoa = v[imax];
  for(int j = imin; j <imax; j++)
    if (vb[j] <= pivoa){
      auxb = vb[j];
      vb[j] = v[ia];
      v[ia] = auxb;

      ia ++;
    }


  auxb = vb[ia];
  vb[ia] = v[imax];
  v[imax] = auxb;
  
  return i;
}

void quickSort(int v[], int vb[], int imin, int imax)
{ 
  if (imin < imax)
  {
    int part = partition(v, vb, imin, imax);
    quickSort(v, vb, imin, part - 1);
    quickSort(v, vb,  part + 1, imax);
  } 
}
#include <stdio.h>

void selectionSort(int vetor[], int n);
int bSearch( int vetor[], int key, int vmin, int n );

int main()
{
    int nE = 0,nG = 0, e[10000] = {0}, g[1000000] = {0};

    scanf("%d", &nE);

    for(int i = 0; i < nE; i++)
        scanf("%d", &e[i]);
    
    scanf("%d", &nG);
    
    for(int i = 0;i < nG; i++)
        scanf("%d", &g[i]);
    selectionSort(e, nE);

    for(int i = 0;i < nG; i++)
    {
        int result = bSearch(e, g[i], e[0], nE);
        if(result == -1){
            printf("descartar\n");
        }else{
            printf("%d\n", e[result]);
        }
    }
    

    return 0;
}


int bSearch( int vetor[], int key, int vmin, int n )
{// busca binaria padrao
	int imax = n-1;
	int imin = 0;
	while( imax >= imin )
	{
		int imid = imin + ((imax - imin) / 2);		
		if( key > vetor[imid] )
			imin = imid + 1;
		else if( key < vetor[imid])
			imax = imid - 1;
		else
			return imid;
	}
    if (key < vmin){//recursividade para pegar casos alem
	    return -1;
    }else{
        return bSearch(vetor, key-1, vmin, n);
    }	

}

void selectionSort(int vetor[], int n)//selection sort padrao
{
    int aux = 0;
    for(int i = 0;i < n - 1; i++){
        int index_min = i;
        for(int j = i + 1; j < n; j++){
            if (vetor[j] < vetor[index_min])
            index_min = j;
        }
        aux = vetor[i];
        vetor[i] = vetor[index_min];
        vetor[index_min] = aux;
    }
}
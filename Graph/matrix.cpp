#include <iostream>

typedef struct {
    int v;
    int a;
    int **adj;
} MatrixGraph;

void iniciar(MatrixGraph *g, int n, int m)
{
    g->v = n;
    g->a = m;
    g->adj = (int**) malloc(sizeof(int*) * n);
    for(int i = 0; i < g->v ; i++)
        g->adj[i] = (int *)malloc(sizeof(int) * g->v);
}
void addEdge(MatrixGraph *g, int u, int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    MatrixGraph g;
    iniciar(&g, n, m);
    return 0;
}
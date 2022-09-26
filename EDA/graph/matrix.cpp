#include <iostream>

typedef struct {
    int v;
    int a;
    int **adj;
} *Graph;

void iniciar(Graph g, int n, int m)
{
    g->v = n;
    g->a = m;
}
void addEdge(Graph g, int u, int v)
{
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    Graph g;
    iniciar(g, n, m);
    return 0;
}
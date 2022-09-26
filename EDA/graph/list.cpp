#include <iostream>
#include "fila.cpp"
typedef struct node{
    int vertice;
    struct node *next;
} link;


typedef struct{
    int v;
    int a;
    link **adj;
} Graph;

using namespace std;
void inicializar(Graph *g, int n, int m);
void destroiGraph(Graph *g);
void adicionaArco(Graph *g, int u, int v);
void dfsR(Graph *g, int vertice, int *visitados);
void dfs(Graph *g);
void bfs(Graph *g);
void printaAdjGraph(Graph *g);

int main(){
    int n = 7, m = 6;
    //cin >> n >> m;
    
    Graph g;
    inicializar(&g, n, m);
    for (int i = 0; i < 4; i++){
        int u, v;
        cin >> u >> v;
        adicionaArco(&g, u, v);
    }
    //printaAdjGraph(&g);
    bfs(&g);
    return 0;
}

void dfsR(Graph *g, int vertice, int *visitados){
    visitados[vertice] = 1;
    
    //process
    cout << g->v << "\n";
    for(link* v = g->adj[vertice]; v != NULL; v = v->next){
        if (!visitados[v->vertice])
            dfsR(g, v->vertice, visitados);
    }
}

void dfs(Graph *g){
    int *vis = (int *) malloc(sizeof(int) * g->v);
    for(int i = 0; i < g->v; i++)
        vis[i] = 0;
    for(int i = 0; i < g->v; i++)
        if(!vis[i])
            dfsR(g, i, vis);
}

void inicializar(Graph *g, int n, int m){
    //g = (Graph*) malloc(sizeof(Graph));
    g->v = n;
    g->a = m;
    g->adj = (link**) malloc(n * sizeof(link*));
    for(int i = 0; i < n; i++)
        g->adj[i] = NULL;
}

void destroiGraph(Graph *g){
    for(int i = 0; i < g->v; i++)
    {
        link* t = g->adj[i];
        while(t != NULL)
        {
            link* aux = t;
            t = t->next;
            free(aux);
        }
    }
    g->v = g->a = 0;
    free(g->adj);
    free(g);
}
void adicionaArco(Graph *g, int u, int v){
    link* n = (link*) malloc(sizeof(link));
    n->vertice = v;
    n->next = g->adj[u];
    g->adj[u] = n;
    
}

void bfs(Graph *g){
    int *vis =(int*) malloc(sizeof(int) * g->v);
    for(int i = 0; i < g->v; i++){
        vis[i] = 0;
    }

    fila *f = inicializarFila(g->v);
    insereFila(f, g->adj[0]->vertice);

    while(!vazia(f)){
        int retirado = retiraFila(f);
        cout << retirado;
        vis[retirado - 1] = 1;
        link* n = g->adj[retirado - 1];
        cout << g->adj[0]->vertice << "\n";
        for(link* t = g->adj[retirado - 1]; t != NULL; t = t->next){
            if(!vis[t->vertice])
                insereFila(f, t->vertice);
        }
    }
    destroiFila(f);
}

void printaAdjGraph(Graph *g){
    for(int  i = 0 ; i < g->v; i++){
        cout << "Vertex : " << i << "\n";
        cout << "Adjacencias : ";
        for(link* t = g->adj[i]; t != NULL; t = t->next){
            cout << t->vertice << " ";
        }
        cout << "\n";
    }
}
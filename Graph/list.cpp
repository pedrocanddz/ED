#include <iostream>
#include "fila.cpp"
#include "matrix.cpp"
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
int bfsBipartition(Graph *g);
void printaAdjGraph(Graph *g);

int main(){
    int n = 7, m = 6;
    //cin >> n >> m;
    
    Graph g;
    inicializar(&g, n, m);
    for (int i = 0; i < 5; i++){
        int u, v;
        cin >> u >> v;
        adicionaArco(&g, u, v);
    }
    //printaAdjGraph(&g);
    cout << bfsBipartition(&g) << "\n";

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

int bfsBipartition(Graph *g){
    int *vis =(int*) malloc(sizeof(int) * g->v);
    int *color = (int*) malloc(sizeof(int) * g->v);

    for(int i = 0; i < g->v; i++)
		vis[i] = 0;
    

    fila *f = inicializarFila(g->v);
    insereFila(f, 0);
    color[0] = 1;
    while(!vazia(f)){
        int retirado = retiraFila(f);
        vis[retirado] = 1;
        // cout << "Cor: " << color[retirado] << "\n";
        // cout << "Valor retirado: " << retirado << "\n";
        for(link* t = g->adj[retirado]; t != NULL; t = t->next)
            if(!vis[t->vertice]){
                insereFila(f, t->vertice);
                color[t->vertice] = !color[retirado];
            }else{
                if(color[t->vertice] == color[retirado])
                    return 0;               
            }             
    }
    destroiFila(f);
    return 1;
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

Graph *matrix2list(MatrixGraph *m){
    Graph *l = (Graph*) malloc(sizeof(Graph));
    l->a = m->a;
    l->v = m->v;
    l->adj = (link**) malloc(sizeof(link*) * l->v);
    for(int i = 0 ; i < l->v; i++)
        l->adj[i] = NULL;
    
    for(int i = 0; i < l->v; i++)
        for(int j = 0; j < l->v; j++)
            if(m->adj[i][j] == 1){
                link *t = (link*) malloc(sizeof(link));
                t->vertice = j;
                t->next = l->adj[i];
                l->adj[i] = t;
            }
}

MatrixGraph  *list2matrix(Graph *l){
    MatrixGraph *m = (MatrixGraph*)malloc(sizeof(MatrixGraph));
    m->a = l->a;
    m->v = l->v;
    m->adj = (int**)malloc(sizeof(int*) * m->v);

    for(int i = 0; i < m->v ; i++)
        m->adj[i] = (int*)malloc(sizeof(int) * m->v);
    
    for(int i = 0; i < m->v; i++)
        for(link *t = l->adj[i]; t!= NULL; t = t->next)
            m->adj[i][t->vertice];
}

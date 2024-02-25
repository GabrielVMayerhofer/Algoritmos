#include <stdio.h>
#include <stdlib.h>

typedef struct graph{
    int **matriz;
    int numEdge;
    int *visited;
} Graph;

Graph criar(int n){
    Graph g;
    g.visited = (int *)malloc(n * sizeof(int));

    g.matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        g.matriz[i] = (int *)malloc(n * sizeof(int));
    

    for (int i = 0; i < n; i++) 
        g.visited[i] = 0;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            g.matriz[i][j] = 0;

    g.numEdge = 0;
    return g; 
}
int first(Graph g, int v, int n){
    for(int i = 0; i < n - 1; i++)
        if(g.matriz[v][i] != 0)
            return i;
    return n;
}
int next(Graph g, int v, int w, int n){
    for(int i = w + 1; i < n - 1; i++)
        if(g.matriz[v][i] != 0)
            return i;
    return n;
}
void setEdge(Graph g, int i, int j){
    g.matriz[i][j] = 1;
    g.matriz[j][i] = 1;
    g.numEdge++;
}
void delEdge(Graph g, int i, int j){
    g.matriz[i][j] = 0;
    g.matriz[j][i] = 0;
    g.numEdge--;
}
void DFS(Graph g, int i, int n){
    g.visited[i] == 1;
    int w = first(g, i, n);
    while(w < n){
        if(g.visited[w] == 0)
            DFS(g, w, n);
        w = next(g, i, w, n);
    }
}
void traverse(Graph g, int n){
    for(int i = 0; i < n - 1; i++)
        g.visited[i] = 0;
    for(int i = 0; i < n - 1; i++)
        if(g.visited[i] == 0)
            DFS(g, i, n);    //BFS ou DFS
}
void limpa(Graph g, int n){
    for (int i = 0; i < n; i++) 
        free(g.matriz[i]);
    free(g.matriz);
    free(g.visited);
}

int main(){

}
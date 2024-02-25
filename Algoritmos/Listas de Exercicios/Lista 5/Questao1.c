#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph {
    int **matriz;
    int *visited;
    int allVisited;
    int cycle;
} Graph;

Graph *criar(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->visited = (int *)malloc(n * sizeof(int));
    g->matriz = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        g->matriz[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        g->visited[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g->matriz[i][j] = 0;

    g->allVisited = 0;
    g->cycle = 0;
    return g;
}

int first(Graph *g, int v, int n) {
    for (int i = 0; i < n; i++)
        if (g->matriz[v][i] != 0)
            return i;
    return n;
}

int next(Graph *g, int v, int w, int n) {
    for (int i = w + 1; i < n; i++)
        if (g->matriz[v][i] != 0)
            return i;
    return n;
}

void setEdge(Graph *g, int i, int j) {
    g->matriz[i][j] = 1;
}


void hasCycleUtil(Graph *g, int v, int n) {
    if (g->visited[v] == 1) 
        g->cycle = 1;

    if (g->visited[v] == 0) {
        g->visited[v] = 1;

        for (int i = 0; i < n; i++) 
            if (g->matriz[v][i] == 1) 
                hasCycleUtil(g, i, n);
    }

    g->visited[v] = 2;
}

int hasCycle(Graph *g, int n) {
    for (int i = 0; i < n; i++) 
        if (g->visited[i] == 0) 
            hasCycleUtil(g, i, n);
        
    return g->cycle;
}

void toposort(Graph *g, int i, int n, int *stack, int *proximo) {
    int esperar = 0;
    for(int j = 0; j < n; j++){
        if(g->matriz[j][i] == 1 && g->visited[j] == 0)
            esperar = 1;
    }
    if(esperar == 0){
        g->allVisited++;
        g->visited[i] = 1;
        stack[(*proximo)++] = i;
        int w = first(g, i, n);
        while (w < n) {
            if (g->visited[w] == 0) 
                toposort(g, w, n, stack, proximo);
            w = next(g, i, w, n);
        }
    }
    
}

void traverseDFS(Graph *g, int n, int *stack, int *top) {
    for(int i = 0; i < n; i++)
        g->visited[i] = 0;
    int i = 0;
    while(g->allVisited != n){
        int j = i % n;
        if(g->visited[j] == 0)
            toposort(g, j, n, stack, &(*top));
        i++;
    }
}


void limpa(Graph *g, int n) {
    for (int i = 0; i < n; i++)
        free(g->matriz[i]);
    free(g->matriz);
    free(g->visited);
}

int main() {
    long int vertices;
    long long int ops;
    scanf("%ld %lld", &vertices, &ops);
    Graph *graph = criar(vertices);
    for (long long int i = 0; i < ops; i++) {
        long int u, v;
        scanf("%ld %ld", &u, &v);
        setEdge(graph, u-1, v-1);
    }
    int *stack = (int *)malloc(vertices * sizeof(int));
    int top = 0;
    graph->cycle = hasCycle(graph, vertices);
    traverseDFS(graph, vertices, stack, &top);
    for(int i = 0; i < vertices; i++)
        printf("%d ", stack[i] + 1);

    limpa(graph, vertices);
    free(stack);
    return 0;
}
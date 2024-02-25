#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph {
    int **matriz;
    int *visited;
    int *cycleFinder;
    int cycle;
} Graph;

Graph *criar(int n) {
    Graph *g = malloc(sizeof(Graph));
    g->visited = (int *)calloc(n, sizeof(int));
    g->cycleFinder = (int *)calloc(n, sizeof(int));
    g->matriz = (int **)calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        g->matriz[i] = (int *)calloc(n, sizeof(int));

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

int auxCycle(Graph *g, int n, int node) {
    if (g->visited[node] == 0) {
        g->visited[node] = 1;
        g->cycleFinder[node] = 1;

        for (int i = 0; i < n; ++i) 
            if (g->matriz[node][i]) {
                if (g->visited[i] == 0 && auxCycle(g, n, i)){
                    g->cycle = 1;
                    return 1; 
                }
                else if (g->cycleFinder[i]){
                    g->cycle = 1;
                    return 1;
                } 
            }
    }

    g->cycleFinder[node] = 0;
    return 0;
}

int hasCycle(Graph *g, int n) {
    for (int i = 0; i < n; ++i) 
        if (auxCycle(g, n, i)){
            g->cycle = 1;
            return 1; 
        }

    return 0; 
}


int dfs(Graph *g, int i, int n, int *stack, int *proximo) {
    g->visited[i] = 1;

    int hasCycle = 0;

    for (int w = 0; w < n; w++) {
        if (g->matriz[i][w]) {
            if (g->visited[w] == 0) {
                hasCycle = dfs(g, w, n, stack, proximo);
                if (hasCycle)
                    return 1;  // Cycle detected in the subtree
            } else if (g->visited[w] == 1) {
                g->cycle = 1;  // Cycle detected
                return 1;
            }
        }
    }

    g->visited[i] = 2;  // Mark as processed
    stack[(*proximo)++] = i;

    return hasCycle;
}

void toposort(Graph *g, int i, int n, int *stack, int *proximo) {
    for (int j = 0; j < n; j++) {
        if (g->matriz[j][i] == 1 && g->visited[j] == 0) {
            return; // Wait for incoming edges
        }
    }

    g->visited[i] = 1;

    stack[(*proximo)++] = i;
    int w = first(g, i, n);
    while (w < n) {
        if (g->visited[w] == 0) {
            toposort(g, w, n, stack, proximo);
        }
        w = next(g, i, w, n);
    }
}

void traverseDFS(Graph *g, int n, int *stack, int *top) {
    for (int t = 0; t < n; t++) {
        if (g->cycle == 1)
            break;
        if (g->visited[t] == 0) {
            g->cycle = dfs(g, t, n, stack, top);
            toposort(g, t, n, stack, top);
        }
    }
}

void limpa(Graph *g, int n) {
    for (int i = 0; i < n; i++)
        free(g->matriz[i]);
    free(g->matriz);
    free(g->visited);
    free(g->cycleFinder);
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
    
    traverseDFS(graph, vertices, stack, &top);

    if(graph->cycle == 1)
        printf("Sandro fails.");
    else{
        
        for(int i = 0; i < vertices; i++)
            printf("%d ", stack[i] + 1);
    }
    

    limpa(graph, vertices);
    free(stack);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct graph {
    int **matriz;
    int numEdge;
    int *visited;
} Graph;

typedef struct queue {
    int primeiro;
    int ultimo;
    int *fila;
} Fila;

Fila *criarFila() {
    Fila *q = malloc(sizeof(Fila));
    q->primeiro = -1;
    q->ultimo = -1;
    q->fila = (int *)malloc(500 * sizeof(int));
    return q;
}

void enqueue(Fila *q, int i, int n) {
    if (q->ultimo == n - 1) {
        printf("full");
    } else {
        if (q->primeiro == -1)
            q->primeiro = 0;
        q->ultimo++;
        q->fila[q->ultimo] = i;
    }
}

int dequeue(Fila *q) {
    int item;
    if (q->ultimo == -1) {
        printf("full");
    } else {
        item = q->fila[q->primeiro];
        q->primeiro++;
        if (q->primeiro > q->ultimo) {
            q->primeiro = -1;
            q->ultimo = -1;
        }
    }
    return item;
}

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

    g->numEdge = n;
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
    g->matriz[j][i] = 1;
    g->numEdge++;
}

void BFS(Graph *g, int i, int n) {
    Fila *queue = criarFila();
    enqueue(queue, i, n);
    while (queue->ultimo != -1) {
        int v = dequeue(queue);
        int w = first(g, v, n);
        while (w < n) {
            if (g->visited[w] == 0) {
                g->visited[w] = 1;
                enqueue(queue, w, n);
                printf("%d ", w);
            }
            w = next(g, v, w, n);
        }
    }
    printf("\n");
    free(queue->fila);
    free(queue);
}

void DFS(Graph *g, int i, int n) {
    g->visited[i] = 1;
    printf("%d ", i);
    int w = first(g, i, n);
    while (w < n) {
        if (g->visited[w] == 0) {
            DFS(g, w, n);
        }
        w = next(g, i, w, n);
    }
}

void traverseBFS(Graph *g, int r, int n) {
    g->visited[r] = 1;
    printf("%d ", r);
    BFS(g, r, n);
}

void traverseDFS(Graph *g, int r, int n) {
    g->visited[r] = 1;
    DFS(g, r, n);
}

void limpa(Graph *g, int n) {
    for (int i = 0; i < n; i++)
        free(g->matriz[i]);
    free(g->matriz);
    free(g->visited);
}

int main() {
    int vertices, ops;
    scanf("%d %d", &vertices, &ops);
    Graph *grafo = criar(vertices);
    for (int i = 0; i < ops; i++) {
        char op[4];
        int u, v;
        int vert;
        scanf("%3s", op);
        if (strcmp(op, "add") == 0) {
            scanf("%d %d", &u, &v);
            setEdge(grafo, u, v);
        } else if (strcmp(op, "BFS") == 0) {
            scanf("%d", &vert);
            traverseBFS(grafo, vert, vertices);
        } else if (strcmp(op, "DFS") == 0) {
            scanf("%d", &vert);
            traverseDFS(grafo, vert, vertices);
            printf("\n");
        }
    }
    limpa(grafo, vertices);

    return 0;
}
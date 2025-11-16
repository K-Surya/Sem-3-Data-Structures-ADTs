#include <stdio.h>
#include <stdlib.h>

struct Graph {
    int adj[20][20];
    int n;
    char vertices[20]; 
};

int visited[20];

void create(struct Graph *G) {
    int edges;
    printf("Enter the no. of vertices: ");
    scanf("%d", &G->n);

    for (int i = 0; i < G->n; i++)
        G->vertices[i] = 'A' + i;

    for (int i = 0; i < G->n; i++)
        for (int j = 0; j < G->n; j++)
            G->adj[i][j] = 0;

    printf("Enter the no. of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (e.g., AB, BC):\n");
    for (int i = 0; i < edges; i++) {
        char src, dest;
        scanf(" %c%c", &src, &dest);
        int u = src - 'A';
        int v = dest - 'A';
        G->adj[u][v] = 1;
    }
}

void disp(struct Graph *G) {
    printf("\nAdjacency Matrix:\n   ");
    for (int i = 0; i < G->n; i++)
        printf("%c ", G->vertices[i]);
    printf("\n");

    for (int i = 0; i < G->n; i++) {
        printf("%c ", G->vertices[i]);
        for (int j = 0; j < G->n; j++)
            printf("%d ", G->adj[i][j]);
        printf("\n");
    }
}

void BFS(struct Graph *G, int start) {
    int queue[20], front = 0, rear = 0;
    int visited[20] = {0};

    printf("\nBFS Traversal starting from %c: ", G->vertices[start]);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%c ", G->vertices[v]);
        for (int i = 0; i < G->n; i++) {
            if (G->adj[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

void DFSUtil(struct Graph *G, int v) {
    visited[v] = 1;
    printf("%c ", G->vertices[v]);
    for (int i = 0; i < G->n; i++) {
        if (G->adj[v][i] && !visited[i])
            DFSUtil(G, i);
    }
}

void DFS(struct Graph *G, int start) {
    for (int i = 0; i < G->n; i++)
        visited[i] = 0;
    printf("\nDFS Traversal starting from %c: ", G->vertices[start]);
    DFSUtil(G, start);
    printf("\n");
}

int isPath(struct Graph *G, int src, int dest) {
    int visited[20] = {0};
    int queue[20], front = 0, rear = 0;

    visited[src] = 1;
    queue[rear++] = src;

    while (front < rear) {
        int v = queue[front++];
        if (v == dest)
            return 1;
        for (int i = 0; i < G->n; i++) {
            if (G->adj[v][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    return 0;
}

void findConnectedComponents(struct Graph *G) {
    for (int i = 0; i < G->n; i++)
        visited[i] = 0;

    printf("\nConnected Components:\n");
    for (int i = 0; i < G->n; i++) {
        if (!visited[i]) {
            DFSUtil(G, i);
            printf("\n");
        }
    }
}




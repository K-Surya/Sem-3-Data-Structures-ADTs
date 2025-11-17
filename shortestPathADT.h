#include <stdio.h>
#include <stdlib.h>
#include "graphADT.h"

#define INF 999

// Function to create and populate the weighted graph
void createWeightedGraph(struct Graph *G) {
    int edges;
    printf("Enter the no. of vertices (max 20): ");
    scanf("%d", &G->n);

    for (int i = 0; i < G->n; i++)
        G->vertices[i] = 'A' + i;

    // Initialize all entries to INF (no direct edge)
    for (int i = 0; i < G->n; i++) {
        for (int j = 0; j < G->n; j++) {
            G->adj[i][j] = INF;
        }
        G->adj[i][i] = 0; // Distance of a vertex from iteslf is 0
    }

    printf("Enter the no. of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges and their weights (e.g., AB 5, CD 10):\n");
    for (int i = 0; i < edges; i++) {
        char src, dest;
        int weight;
        scanf(" %c%c %d", &src, &dest, &weight);
        int u = src - 'A';
        int v = dest - 'A';
        if (u >= 0 && u < G->n && v >= 0 && v < G->n) {
            G->adj[u][v] = weight;
            // G->adj[v][u] = weight; // Uncomment for an undirected graph..
        } else {
            printf("Invalid vertex entered. Edge skipped.\n");
            i--;
        }
    }
}

// Function to display the adjacency matrix (weights)
void dispWeightedGraph(struct Graph *G) {
    printf("\nWeighted Adjacency Matrix:\n    ");
    for (int i = 0; i < G->n; i++)
        printf("%c  ", G->vertices[i]);
    printf("\n");

    for (int i = 0; i < G->n; i++) {
        printf("%c: ", G->vertices[i]);
        for (int j = 0; j < G->n; j++) {
            if (G->adj[i][j] == INF) {
                printf("INF"); // Print INF for no direct edge
            } else {
                printf("%3d", G->adj[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }
}

// Supporter function to print the shortest path
void printPath(struct Graph *G, int path[], int i){
    if(path[i] == -1){
        printf("%c", G->vertices[i]);
        return;
    }

    printPath(G, path, path[i]);
    printf("->%c", G->vertices[i]);
}

// Find the next vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INF;
    int min_index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Shortest path using Dijkstra's algorithm..
void dijkstra(struct Graph *G, int start) {
    int n = G->n;
    int dist[20];
    int visited[20];
    int path[20];

    // Initialize all distances as INFand visited as 0
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        path[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[start] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the next shortest unvisited node
        int u = minDistance(dist, visited, n);

        // If all reachable node has been processed, break the loop
        if(u == -1) break; 

        visited[u] = 1;

        // Relaxation
        for (int v = 0; v < n; v++) {
            if (!visited[v] && G->adj[u][v] != INF && dist[u] != INF && dist[u] + G->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + G->adj[u][v];
                path[v] = u;
            }
        }
    }

    // Print the constructed distance array
    printf("\nShortest path distances from vertex %c:\n", G->vertices[start]);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("Distance to %c: No Path\n", G->vertices[i]);
        } else {
            printf("Distance to %c: %d\n", G->vertices[i], dist[i]);
            printf("Path : ");
            printPath(G, path, i);
            printf("\n");
        }
    }
}

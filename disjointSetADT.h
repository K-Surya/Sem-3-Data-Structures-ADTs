#include <stdio.h> 
#include <stdlib.h>

struct DisjointSets {
    int parent[100];
    int rank[100];
};

struct DisjointSets* makeSet(int n) {
    struct DisjointSets *ds = (struct DisjointSets*) malloc(sizeof(struct DisjointSets));
    for (int i = 1; i <= n; i++) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }
    return ds;
}

int find(struct DisjointSets* ds, int x) {
    if (ds->parent[x] != x)
        ds->parent[x] = find(ds, ds->parent[x]);   
    return ds->parent[x];
}

void unionSets(struct DisjointSets* ds, int a, int b) {
    a = find(ds, a);  
    b = find(ds, b);  

    if (a != b) { 
        if (ds->rank[a] < ds->rank[b])
            ds->parent[a] = b;          
        else if (ds->rank[a] > ds->rank[b])
            ds->parent[b] = a;
        else {
            ds->parent[b] = a;
            ds->rank[a]++;
        }
    }
}

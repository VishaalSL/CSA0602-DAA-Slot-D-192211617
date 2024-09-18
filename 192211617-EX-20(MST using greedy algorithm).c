#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int src, dest, weight;
} Edge;
typedef struct {
    int parent, rank;
} Subset;
int compare(const void *a, const void *b) {
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (xroot != yroot) {
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
}
void kruskalMST(Edge edges[], int V, int E) {
    Edge result[V];
    int e = 0; 
    int i; 
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    qsort(edges, E, sizeof(Edge), compare);
    for (i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    i = 0;
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    int minimumCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", minimumCost);
    free(subsets);
}
int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    printf("Enter the edges (src dest weight):\n");
    int j;
    for (j = 0; j < E; ++j) {
        scanf("%d %d %d", &edges[j].src, &edges[j].dest, &edges[j].weight);
    }
    kruskalMST(edges, V, E);
    free(edges);
    return 0;
}


#include <stdio.h>
#include <limits.h>

#define V 5  // Number of vertices
#define E 8  // Number of edges

// Edge structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};

// Function to implement Bellman-Ford Algorithm
void bellmanFord(struct Edge edges[], int V, int E, int src) {
    int dist[V];  // Array to store the shortest distance from the source
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // Initialize distances as infinite
    }
    dist[src] = 0;  // Distance to the source is always 0

    // Relax all edges V-1 times
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[edges[j].u] != INT_MAX && dist[edges[j].u] + edges[j].weight < dist[edges[j].v]) {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        if (dist[edges[i].u] != INT_MAX && dist[edges[i].u] + edges[i].weight < dist[edges[i].v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Print the distance array
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    // Define the graph's edges
    struct Edge edges[] = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0; // Source vertex
    bellmanFord(edges, V, E, source);

    return 0;
}

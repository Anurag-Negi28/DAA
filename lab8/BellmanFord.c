#include <stdio.h>
#include <limits.h>

// Maximum number of vertices
#define MAX_VERTICES 100

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Function to initialize the distances array
void initializeDistances(int distances[], int source, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        if (i == source) {
            distances[i] = 0;
        } else {
            distances[i] = INT_MAX;
        }
    }
}

// Function to relax an edge
void relax(int distances[], struct Edge edge) {
    if (distances[edge.source] != INT_MAX &&
        distances[edge.source] + edge.weight < distances[edge.destination]) {
        distances[edge.destination] = distances[edge.source] + edge.weight;
    }
}

// Bellman-Ford algorithm
void bellmanFord(int numVertices, int numEdges, struct Edge edges[], int source) {
    int distances[MAX_VERTICES];
    initializeDistances(distances, source, numVertices);

    // Relax edges repeatedly
    for (int i = 1; i < numVertices; i++) {
        for (int j = 0; j < numEdges; j++) {
            relax(distances, edges[j]);
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < numEdges; i++) {
        if (distances[edges[i].source] != INT_MAX &&
            distances[edges[i].source] + edges[i].weight < distances[edges[i].destination]) {
            printf("Graph contains a negative weight cycle. Bellman-Ford does not work for this graph.\n");
            return;
        }
    }

    // Print the shortest distances
    printf("Shortest distances from source %d:\n", source);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: %d\n", i, distances[i]);
    }
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Edge edges[MAX_VERTICES];

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].source, &edges[i].destination, &edges[i].weight);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    bellmanFord(numVertices, numEdges, edges, source);

    return 0;
}

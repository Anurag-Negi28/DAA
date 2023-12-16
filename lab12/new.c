#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent a graph
struct Graph
{
    int V;
    int **adjMatrix;
};

// Function to create a graph
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for the adjacency matrix
    graph->adjMatrix = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++)
    {
        graph->adjMatrix[i] = (int *)malloc(V * sizeof(int));
    }

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;
}

// Function to print the minimum spanning tree
void printMST(int parent[], struct Graph *graph)
{
    printf("Minimum Spanning Tree:\n");
    for (int i = 1; i < graph->V; i++)
    {
        int src = parent[i];
        int dest = i;
        int weight = graph->adjMatrix[src][dest];

        printf("(%d, %d) - %d\n", src + 1, dest + 1, weight);
    }
}

// Function to construct and find the minimum spanning tree
void findMinimumSpanningTree(struct Graph *graph)
{
    int parent[graph->V];  // Array to store constructed MST
    int key[graph->V];     // Key values used to pick minimum weight edge
    bool mstSet[graph->V]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < graph->V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;     // Make key 0 so that this vertex is picked as the first vertex
    parent[0] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < graph->V - 1; count++)
    {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u;
        int min = INT_MAX;
        for (int v = 0; v < graph->V; v++)
        {
            if (!mstSet[v] && key[v] < min)
            {
                u = v;
                min = key[v];
            }
        }

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of the adjacent vertices of the picked vertex
        for (int v = 0; v < graph->V; v++)
        {
            if (!mstSet[v] && graph->adjMatrix[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);

    // Find and print the shortest path between vertices 1 and 7
    printf("\nShortest path between 1 and 4:\n");
    int dest = 3; // Vertex 7 (0-based index)
    while (parent[dest] != -1)
    {
        printf("%d <- ", dest + 1);
        dest = parent[dest];
    }
    printf("%d\n", dest + 1);
}

int main()
{
    int V;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    // Create a graph
    struct Graph *graph = createGraph(V);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph->adjMatrix[i][j]);
        }
    }

    // Find the minimum spanning tree and shortest path between vertices 1 and 7
    findMinimumSpanningTree(graph);

    // Free dynamically allocated memory
    for (int i = 0; i < V; i++)
    {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}

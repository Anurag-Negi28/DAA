#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph
{
    int V, E;
    struct Edge *edges;
};

// Function to create a graph
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge *)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    graph->edges[graph->E].src = src;
    graph->edges[graph->E].dest = dest;
    graph->edges[graph->E].weight = weight;
    graph->E++;
}

// Function to print the adjacency matrix with row and column indices
void printAdjacencyMatrix(struct Graph *graph)
{
    printf("Adjacency Matrix:\n");

    // Print column indices
    printf("\t");
    for (int i = 0; i < graph->V; i++)
    {
        printf("d%d\t", i);
    }
    printf("\n");

    // Initialize an empty matrix with 0 values
    int adjacencyMatrix[graph->V][graph->V];
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // Fill the matrix with the weights of edges
    for (int i = 0; i < graph->E; i++)
    {
        int src = graph->edges[i].src;
        int dest = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight; // Update this line to ensure symmetry
    }

    // Print the adjacency matrix
    for (int i = 0; i < graph->V; i++)
    {
        // Print row index
        printf("d%d\t", i);

        for (int j = 0; j < graph->V; j++)
        {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to relax an edge
void relax(int distances[], struct Edge edge)
{
    if (distances[edge.src] != INT_MAX &&
        distances[edge.src] + edge.weight < distances[edge.dest])
    {
        distances[edge.dest] = distances[edge.src] + edge.weight;
    }
}

// Bellman-Ford algorithm
void bellmanFord(int numVertices, int numEdges, struct Edge edges[], int source, int destination)
{
    int distances[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        distances[i] = INT_MAX;
    }
    distances[source] = 0;

    // Relax edges repeatedly
    for (int i = 1; i < numVertices - 1; i++)
    {
        for (int j = 0; j < numEdges; j++)
        {
            relax(distances, edges[j]);
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < numEdges; i++)
    {
        if (distances[edges[i].src] != INT_MAX &&
            distances[edges[i].src] + edges[i].weight < distances[edges[i].dest])
        {
            printf("Graph contains a negative weight cycle.\n");
            return;
        }
    }

    // Print the shortest distance from source to destination
    printf("Shortest distance from vertex %d to vertex %d: %d\n", source, destination, distances[destination]);
}

// Function to print the minimum spanning tree in adjacency matrix format
void printMST(int parent[], struct Graph *graph)
{
    printf("Minimum Spanning Tree (Adjacency Matrix Format):\n");

    // Initialize an empty matrix with 0 values
    int adjacencyMatrix[graph->V][graph->V];
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }

    // Fill the matrix with the weights of edges in the MST
    for (int i = 1; i < graph->V; i++)
    {
        int src = parent[i];
        int dest = i;
        int weight = 0;

        // Search for the edge in the graph's edges array
        for (int j = 0; j < graph->E; j++)
        {
            if (graph->edges[j].src == src && graph->edges[j].dest == dest)
            {
                weight = graph->edges[j].weight;
                break;
            }
        }

        // Update the matrix with the weight of the edge
        adjacencyMatrix[src][dest] = weight;
        adjacencyMatrix[dest][src] = weight;
    }

    // Print the adjacency matrix
    for (int i = 0; i < graph->V; i++)
    {
        // Print row index
        printf("d%d\t", i);

        for (int j = 0; j < graph->V; j++)
        {
            printf("%d\t", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to construct and find the minimum spanning tree
void findMinimumSpanningTree(struct Graph *graph)
{
    int parent[graph->V];
    int key[graph->V];
    bool mstSet[graph->V];

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < graph->V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include the first vertex in MST
    key[0] = 0;
    parent[0] = -1;

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
            if (!mstSet[v] && graph->edges[u].weight < key[v])
            {
                parent[v] = u;
                key[v] = graph->edges[u].weight;
            }
        }
    }

    // Print the constructed MST in adjacency matrix format
    printMST(parent, graph);
}

int main()
{
    // Provide the graph data at compile time
    struct Edge edges[] = {
        {0, 1, 9},
        {0, 2, 22},
        {0, 3, 31},
        {0, 4, 31},
        {0, 5, 22},
        {0, 6, 10},
        {0, 7, 3},

        {1, 2, 13},
        {1, 3, 21},
        {1, 4, 22},
        {1, 5, 13},
        {1, 6, 3},
        {1, 7, 10},

        {2, 3, 9},
        {2, 4, 10},
        {2, 5, 3},
        {2, 6, 13},
        {2, 7, 22},

        {3, 4, 3},
        {3, 5, 10},
        {3, 6, 22},
        {3, 7, 31},

        {4, 5, 9},
        {4, 6, 22},
        {4, 7, 31},

        {5, 6, 13},
        {5, 7, 22},

        {6, 7, 9},
    };
    int V = 8;
    int E = sizeof(edges) / sizeof(edges[0]);

    // Create a graph
    struct Graph *graph = createGraph(V, E);

    // Copy the provided edges to the graph
    for (int i = 0; i < E; i++)
    {
        graph->edges[i] = edges[i];
    }

    // Print the adjacency matrix
    printAdjacencyMatrix(graph);

    // Find the minimum spanning tree
    findMinimumSpanningTree(graph);

    // User input for source and destination vertices
    int source, destination;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    printf("Enter the destination vertex: ");
    scanf("%d", &destination);

    // Find the minimum distance using Bellman-Ford algorithm
    bellmanFord(V, E, edges, source, destination);

    // Free allocated memory
    free(graph->edges);
    free(graph);

    return 0;
}

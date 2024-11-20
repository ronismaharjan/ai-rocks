#include <stdio.h>

#define MAX_VERTICES 5  // Maximum number of vertices in the graph

// Function to add an edge to the graph (undirected)
void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int src, int dest) {
    // For an undirected graph, add edge in both directions
    graph[src][dest] = 1;
    graph[dest][src] = 1;
}

// Function to print the adjacency list of the graph
void printAdjacencyList(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < numVertices; j++) {
            if (graph[i][j] == 1) {
                printf("%d -> ", j);
            }
        }
        printf("NULL\n");
    }
}

// Function to print the adjacency matrix of the graph
void printAdjacencyMatrix(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to perform DFS on the graph
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int vertex, int numVertices) {
    // Mark the current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all adjacent vertices of the current vertex
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, i, numVertices);
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};  // Initialize the graph to 0 (no edges)
    int visited[MAX_VERTICES] = {0};  // Array to track visited vertices
    int numVertices = MAX_VERTICES;   // Number of vertices in the graph

    // Add edges to the graph using addEdge function
    addEdge(graph, 0, 1);  // Add edge between vertex 0 and 1
    addEdge(graph, 0, 2);  // Add edge between vertex 0 and 2
    addEdge(graph, 1, 3);  // Add edge between vertex 1 and 3
    addEdge(graph, 1, 4);  // Add edge between vertex 1 and 4
    addEdge(graph, 2, 0);  // Add edge between vertex 2 and 0 (duplicate of 0->2, undirected graph)
    
    // Print the adjacency list of the graph
    printAdjacencyList(graph, numVertices);
    
    // Print the adjacency matrix of the graph
    printAdjacencyMatrix(graph, numVertices);

    // Perform DFS starting from vertex 0
    int startVertex = 0;
    printf("\nDFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, visited, startVertex, numVertices);

    return 0;
}

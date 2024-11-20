#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Queue structure for BFS
struct Queue {
    int items[V];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an item
void enqueue(struct Queue* q, int value) {
    if (q->rear == V - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an item
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

// Function to add an edge between two vertices
void addEdge(int graph[V][V], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;  // Because the graph is undirected
}

// Function to print the current contents of the queue
void printQueue(struct Queue* q) {
    printf("Queue contains: ");
    if (!isEmpty(q)) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
    }
    printf("\n");
}

// Function to perform BFS on the graph
void bfs(int graph[V][V], int start) {
    bool visited[V] = {false};
    struct Queue q;
    initQueue(&q);

    // Start BFS from the given start vertex
    visited[start] = true;
    enqueue(&q, start);

    while (!isEmpty(&q)) {
        int current = dequeue(&q);
        printf("Visited %d\n", current);

        // Print current queue contents
        printQueue(&q);

        // Visit all the adjacent vertices of the dequeued node
        for (int i = 0; i < V; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }

        // After visiting all adjacent nodes, reset the queue for the next round
        printf("Resetting queue\n");
    }
}

int main() {
    int graph[V][V] = {0};  // Initialize the graph with 0s (no edges)

    // Add edges using addEdge function
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 4);

    // Perform BFS starting from vertex 0
    printf("BFS Traversal starting from vertex 0:\n");
    bfs(graph, 0);  // Perform BFS starting from vertex 0

    return 0;
}

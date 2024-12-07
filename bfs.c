#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int numVertices;

typedef struct {
    int items[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Queue is empty now
    } else {
        q->front++;
    }
    return item;
}

// BFS Function
void bfs(int startVertex) {
    // Create a queue for BFS
    Queue q;
    initQueue(&q);

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = true;
    enqueue(&q, startVertex);

    // Perform BFS
    while (!isEmpty(&q)) {
        // Dequeue a vertex from the queue
        int vertex = dequeue(&q);

        // Print the vertex as a character (A, B, C, ...)
        printf("%c ", 'A' + vertex);

        // Enqueue all unvisited adjacent vertices
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    // Input: Number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Initialize adjacency matrix and visited array
    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Initialize all vertices as not visited
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    // Start BFS traversal from vertex 0 (or any vertex you choose)
    printf("BFS Traversal starting from vertex A:\n");
    bfs(0);

    return 0;
}

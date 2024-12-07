#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int numVertices;

void dfs(int vertex) {
    // Mark the current node as visited
    visited[vertex] = true;
    
    // Print the current vertex as a character (A, B, C, ...)
    printf("%c ", 'A' + vertex);

    // Recur for all the adjacent vertices that haven't been visited yet
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfs(i);
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

    // Start DFS traversal from vertex 0 (or any vertex you choose)
    printf("DFS Traversal starting from vertex A:\n");
    dfs(0);

    return 0;
}

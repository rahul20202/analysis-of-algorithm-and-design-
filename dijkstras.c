#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int N;

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < N; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t\t\t INF\n", i); // Use INF for unreachable nodes
        } else {
            printf("%d \t\t\t\t %d\n", i, dist[i]);
        }
    }
}

void dijkstra(int graph[N][N], int src) {
    int dist[N];              // Distance array
    bool visited[N];          // Visited array

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0; // Distance from source to itself is always 0

    // Find shortest path for all vertices
    for (int i = 0; i < N - 1; i++) {
        int u = minDistance(dist, visited); // Select the vertex with the minimum distance
        visited[u] = true; // Mark the selected vertex as visited

        // Update distance values of the adjacent vertices of the selected vertex
        for (int j = 0; j < N; j++) {
            // If there's an edge from u to j, and if u's distance + edge weight is less than j's current distance
            if (!visited[j] && graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // Print the results
    printSolution(dist);
}

int main() {
    // Input graph size
    printf("Enter the number of vertices: ");
    scanf("%d", &N);

    int graph[N][N], src;

    // Input adjacency matrix
    printf("Enter the adjacency matrix for the graph (%d x %d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Mat[%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    // Input source vertex
    printf("Enter the source node (0 to %d): ", N - 1);
    scanf("%d", &src);

    // Run Dijkstra's algorithm
    dijkstra(graph, src);

    return 0;
}

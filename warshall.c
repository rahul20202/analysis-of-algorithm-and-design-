#include<stdio.h>
#include<stdlib.h>

void warshell(int n, int **a) {
    // Warshall's algorithm to find the transitive closure
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If there's a path from i to k and from k to j, then there's a path from i to j
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the adjacency matrix
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    // Input the adjacency matrix
    printf("Enter adjacency matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Print the initial adjacency matrix
    printf("Initial adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Apply Warshall's algorithm
    warshell(n, a);

    // Print the updated adjacency matrix after applying the algorithm
    printf("Updated adjacency matrix after applying Warshall's algorithm:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}

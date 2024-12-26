
#include <stdio.h>
#define MAX_VERTICES 10

int a, b, u, v, n, i, j, ne = 1, visited[MAX_VERTICES] = {0}, min, mincost = 0, cost[MAX_VERTICES][MAX_VERTICES];

void prim(int cost[MAX_VERTICES][MAX_VERTICES]) {
    while (ne < n) {
        for (i = 0, min = 999; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if ((visited[u] == 0) || (visited[v] == 0)) {
            printf("\n Edge %d:(%d - %d) cost:%d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\n\n Minimum cost = %d", mincost);
}

int main() {
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix\n");
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Mat[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    
    visited[0] = 1;
    prim(cost);
    
    return 0;
}

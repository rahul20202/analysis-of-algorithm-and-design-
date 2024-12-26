// Floyd algorithm
#include<stdio.h>

int n, dist[20][20];

void floyd() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

void printmat() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("dist[%d][%d]:", i, j);
            scanf("%d", &dist[i][j]);
        }
    }
    
    printf("\n\nCost matrix:\n");
    printmat();
    
    floyd();
    
    printf("\n\nShortest distance matrix:\n");
    printmat();
    
    return 0;
}


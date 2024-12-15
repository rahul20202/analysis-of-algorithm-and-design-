#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
void knapSack(int w, int wt[], int val[], int n) {
    int k[n+1][w+1]; // DP table
    
    // Fill the DP table
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                k[i][j] = 0; // Base case: no items or no capacity
            else if (wt[i-1] <= j)
                // Item can be included or excluded
                k[i][j] = max(val[i-1] + k[i-1][j-wt[i-1]], k[i-1][j]);
            else
                // Item cannot be included
                k[i][j] = k[i-1][j];
        }
    }

    // Print the DP table (Knapsack matrix)
    printf("\nKnapsack Matrix:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            printf("%d\t", k[i][j]);
        }
        printf("\n");
    }

    // The maximum profit is stored at the bottom-right corner of the matrix
    printf("\nMaximum Profit: %d\n", k[n][w]);
}

int main() {
    int w, n;
    
    // Input the knapsack capacity
    printf("Enter the maximum size of the sack (capacity): ");
    scanf("%d", &w);
    
    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    int val[n], wt[n];
    
    // Input the weights of the items
    printf("\nEnter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Weight of Item %d: ", i + 1);
        scanf("%d", &wt[i]);
    }
    
    // Input the values of the items
    printf("\nEnter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Value of Item %d: ", i + 1);
        scanf("%d", &val[i]);
    }
    
    // Call the knapsack function to compute the result
    knapSack(w, wt, val, n);
    
    return 0;
}

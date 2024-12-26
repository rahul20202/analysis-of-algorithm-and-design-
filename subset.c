#include <stdio.h>
int solutionExists;
// Function to print a subset
void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Recursive function to find subsets with sum d
void findSubsets(int S[], int n, int subset[], int subsetSize, int index, int currentSum, int target) {
    // If the current sum equals the target, print the subset
    if (currentSum == target) {
        solutionExists=1;
        printSubset(subset, subsetSize);
        return;
    }

    // If the index reaches the end of the array or the current sum exceeds the target, return
    if (index == n || currentSum > target) {
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = S[index];
    findSubsets(S, n, subset, subsetSize + 1, index + 1, currentSum + S[index], target);

    // Exclude the current element and move to the next
    findSubsets(S, n, subset, subsetSize, index + 1, currentSum, target);
}

int main() {
    int S[] = {1, 2}; // Input set
    int d =4;                 // Target sum
    int n = sizeof(S) / sizeof(S[0]);
    int subset[n];             // Array to store subsets
       // Flag to track if a solution exists

    printf("Subsets with sum %d:\n", d);
    findSubsets(S, n, subset, 0, 0, 0, d);

    // Check if no subsets were found
    if (!solutionExists) {
        printf("No subset with the given sum exists.\n");
    }

    return 0;
}

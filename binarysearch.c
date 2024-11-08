#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX], low = 0, high, mid, x, n, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    high = n - 1;  // Initialize high after reading n

    printf("Enter the elements in sorted order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be searched in the list: ");
    scanf("%d", &x);

    // Beginning of binary search
    while (low <= high) {
        mid = low + (high - low) / 2;  // Finding the middle element

        if (a[mid] == x) {  // Element found at mid
            printf("Element found at index: %d\n", mid);
            return 0;
        }

        if (a[mid] < x)  // If x is greater, ignore the left half
            low = mid + 1;
        else             // If x is smaller, ignore the right half
            high = mid - 1;
    }

    // If element is not found
    printf("Element not found\n");
    return 0;
}


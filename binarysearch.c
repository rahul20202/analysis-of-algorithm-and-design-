#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
int main() {
    int a[MAX], low = 0, high, mid, x, i;
    clock_t t1,t2;
    t1=clock();
    high = MAX - 1;  // Initialize high after reading n
    for (i = 0; i < MAX; i++) {
        a[i]=rand();
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
    t2=clock();
    float t=(t2-t1)/CLOCKS_PER_SEC;
    printf("time taken is:%f",t);
    return 0;
}

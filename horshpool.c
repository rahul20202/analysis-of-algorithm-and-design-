#include<stdio.h>
#include<string.h>
#define MAX 256

void shiftTable(char pattern[], int table[]) {
    int m = strlen(pattern);
    for (int i = 0; i < MAX; i++) {
        table[i] = m;  // Initialize the table with the length of the pattern
    }
    for (int i = 0; i < m - 1; i++) {
        table[(unsigned char)pattern[i]] = m - i - 1;  // Update table based on the pattern
    }
}

int horspoolSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int table[MAX];
    
    shiftTable(pattern, table);  // Fill the shift table
    int i = m - 1;

    while (i < n) {
        int j = 0;
        while (j < m && text[i - j] == pattern[m - 1 - j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;  // Pattern found, return the starting index
        }
        i += table[(unsigned char)text[i]];  // Move i based on the shift table
    }
    return -1;  // Pattern not found
}

int main() {
    char text[MAX];
    char pattern[50];

    printf("Enter the string (text): ");
    fgets(text, MAX, stdin);
    text[strcspn(text, "\n")] = 0;  // Remove the newline character if present
    
    printf("Enter the pattern: ");
    fgets(pattern, 50, stdin);
    pattern[strcspn(pattern, "\n")] = 0;  // Remove the newline character if present

    int result = horspoolSearch(text, pattern);

    if (result != -1) {
        printf("Pattern found at position %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}

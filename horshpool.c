// Horspool algorithm
#include<stdio.h>
#include<string.h> 
#define MAX 256

void shiftTable(char pattern[], int table[]) {
    int m = strlen(pattern);
    for(int i = 0; i < MAX; i++) 
        table[i] = m;
    for(int i = 0; i < m - 1; i++) 
        table[(unsigned char)pattern[i]] = m - i - 1;
}

int horspoolSearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int table[MAX];
    shiftTable(pattern, table);
    int i = m - 1;
    
    while(i < n) {
        int j = 0;
        while(j < m && text[i - j] == pattern[m - 1 - j]) 
            j++;
        if(j == m) 
            return i - m + 1;
        i += table[(unsigned char)text[i]];
    }
    
    return -1;
}

int main() {
    char text[MAX];
    char pattern[50];
    
    printf("Enter the string (text):");
    gets(text); 
    printf("Enter the pattern:");
    gets(pattern); 
    
    int result = horspoolSearch(text, pattern);
    
    if(result != -1) 
        printf("Pattern found at position %d\n", result);
    else 
        printf("Pattern not found\n");
    
    return 0;
}

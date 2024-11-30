#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define MAX 1000 

// Function to add two large numbers represented as strings
void addLargeNumbers(char n1[], char n2[], char res[]) {
	int l1,l2;
    l1 = strlen(n1);// store length of each number array in l1 and l2
    l2 = strlen(n2);
    
    int c = 0;//carry initialize to zero first
    int i, j, k;
    
    // Indices for n1, n2 and res
    i = l1 - 1;
    j = l2 - 1;
    k = 0;

    // Add the digits of the two numbers
    while (i >= 0 || j >= 0 || c) {
    	int digi1,digi2,sum;
    	
         digi1 = (i >= 0) ? n1[i] - '0' : 0;  // Get digit from n1 (0 if out of bounds)
         digi2 = (j >= 0) ? n2[j] - '0' : 0;  // Get digit from n2 (0 if out of bounds)
        
        sum = digi1 + digi2 + c;  // Add corresponding digits and carry
        
        res[k++] = (sum % 10) + '0';  // Store the result digit (as character)
        c = sum / 10;  // Update carry for next iteration
        
        i--;
        j--;
    }
    
    res[k] = '\0';  // Null terminate the result string
    char temp;
    int start,end;
    // Reverse the result string
    for (start = 0, end = k - 1; start < end; start++, end--) {
         temp = res[start];
        res[start] = res[end];
        res[end] = temp;
    }
}

int main() {
    char num1[MAX_LENGTH], num2[MAX_LENGTH], result[MAX_LENGTH + 1];  // +1 for possible carry at the end

    // Input two long integers as strings
    printf("Enter the first long integer: ");
    scanf("%s", num1);
    printf("Enter the second long integer: ");
    scanf("%s", num2);

    // Add the two numbers
    addLargeNumbers(num1, num2, result);

    // Output the result
    printf("The sum of the two long integers is: %s\n", result);

    return 0;
}


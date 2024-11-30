#include <stdio.h>
#include <string.h>
#include<time.h>
#define MAX 1000

// Function to add two large numbers represented as strings
void addLargeNumbers(char n1[], char n2[], char res[]) {
    int l1,l2;
    int c=0;
    l1 = strlen(n1);
    l2 = strlen(n2);
    int i = l1 - 1;
	int j = l2 - 1;
    int k = 0;
    
    // Add the digits of the two numbers
    while (i >= 0 || j >= 0 || c) {
        int digit1 = (i >= 0) ? n1[i] - '0' : 0;
        int digit2 = (j >= 0) ? n2[j] - '0' : 0;
        int sum = digit1 + digit2 + c;
        
        res[k++] = (sum % 10) + '0'; // Store the result digit
        c = sum / 10;  // Update carry
        
        i--; j--;  // Move to the next digits
    }

    res[k] = '\0';  // Null terminate the result string
    int start,end;
    // Reverse the result string
    for (start = 0, end = k - 1; start < end; start++, end--) {
        char temp = res[start];
        res[start] = res[end];
        res[end] = temp;
    }
}

int main() {
    char num1[MAX], num2[MAX], result[MAX + 1];  // +1 for possible carry at the end
      clock_t t1,t2;
	t1=clock();
    // Input two long integers as strings
    printf("Enter the first long integer: ");
    scanf("%s", num1);
    printf("Enter the second long integer: ");
    scanf("%s", num2);

    // Add the two numbers
    addLargeNumbers(num1, num2, result);
t2=clock();
    // Output the result
    printf("The sum of the two long integers is: %s\n", result);
   float t=(t2-t1)/CLOCKS_PER_SEC;
	printf("time taken is:%f",t);
    return 0;
}

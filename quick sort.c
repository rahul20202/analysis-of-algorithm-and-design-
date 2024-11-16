#include<stdio.h> 
#include <stdlib.h>
#include <time.h>
#define MAX 100000000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int a[], int low, int high) {
	int p,i,j;

                             // Initialize pivot to be the first element
    p = a[low];
    i = low;
    j = high;

    while (i < j) {

                                                  // Find the first element greater than from starting
                                                 
        while (a[i]<=p && i<= high-1) {
            i++;
        }

                                                        // Find the first element smaller than from starting
                                                           
        while (a[j]>p && j>=low+1) {
            j--;
        }
        if (i<j) {
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[low], &a[j]);
    return j;
}

void quickSort(int a[], int low, int high) {
	int p;
    if (low < high) {

                                                  // call partition function to find Partition Index
         p = part(a, low, high);

                                                    // Recursively call quickSort() for left and right
                                                     // half based on Partition Index
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
       }
   }
int main(){
	int x[MAX];
    float sec;
    clock_t t1,t2;
    
    for(int i=0;i<MAX;i++)
     x[i]=rand();
    
    t1=clock();               //calculate time before sorting

     quickSort(x,0,MAX-1); 
     t2=clock();             //calculate time after sorting

     
      sec=(float) (t2-t1)/CLK_TCK;   //actul time difference 
   printf("time taken =%f\n",sec);
   
   return 0;
}
  

#include<stdio.h> 
#include <stdlib.h>
#include <time.h>
#define MAX 10000

int main()
{
	int a[MAX],b[MAX],c[MAX],i,n1,n2,tn;
	int p,q;
	float sec;
	clock_t t1,t2;
	
	printf("Enter the size of first array : ");//1st array initialize
    scanf("%d", &n1);
   
	for(i=0;i<n1;i++)
	{
     a[i]=rand();
  }    
    printf("Enter the size of second array : ");//2nd array initialize
    scanf("%d", &n2);
	
	for(i=0;i<n2;i++){
     b[i]=rand();
      }
      
    tn=n1+n2; //add total size of the array and assign to tn
    
    
    t1=clock();//calculate time before sorting
   
      for(i=0;i<tn;i++)  //begining of the sorting algorithm
      {
		  if(p>=n1 || q>=n2)
        {
            break;
        }


        if(a[p]<b[q])
        {
            c[i] = a[p];
            p++;
        }
        else
        {
            c[i] = b[q];
            q++;
        }
	}
	while(p<n1)
	{
		c[i] = a[p];
        i++;
        p++;
    }
    while(q<n2)
	{
		c[i] = b[q];
        i++;
        q++;
    }
    t2=clock();//calculate time after sorting

   sec=(float) (t2-t1)/CLK_TCK;   //actul time difference 
   printf("time taken =%f\n",sec);

   
    return 0;
}
		

		                

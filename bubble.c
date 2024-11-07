#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 300000

int main()
{
int a[MAX],i,j,temp;
float sec;
clock_t t1,t2;
 
for(i=0;i<MAX;i++)
    a[i]=rand();

t1=clock();//calculate time before sorting

for(i=0;i<MAX;i++)//beginning of bubble sort
{ 
	for(j=0;j<MAX;j++)
		if(a[j+1]<a[j])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
   
}
t2=clock();//calculate time after sorting

sec=(float) (t2-t1)/CLK_TCK;//actul time difference 
printf("time taken =%f\n",sec);
return 0;
}

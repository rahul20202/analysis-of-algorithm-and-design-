#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50000

int main()
{
int a[MAX],i,j,temp,minpos;
float sec;
clock_t t1,t2;
 
for(i=0;i<MAX;i++)
    a[i]=rand();

t1=clock();//calculate time before sorting

for(i=0;i<MAX-2;i++)//beginning of selection sort
{ 
    minpos=i;
	for(j=i+1;j<MAX-1;j++)
	{
		if(a[j]<a[minpos])
		{
			minpos=j;
		}
		//swaping ith position to min position
	    temp=a[i];
		a[minpos]=temp;
		a[i]=a[minpos];
	}
   
}
t2=clock();//calculate time after sorting

sec=(float) (t2-t1)/CLK_TCK;//actul time difference 
printf("time taken =%f\n",sec);
return 0;
}

//output:
  //for 1000:0 sec , for 2000:0sec ,for 5000:0.041000sec , for 10000:0.124000 sec, for 20000:0.5sec, for 50000:3.115000sec

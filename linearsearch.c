#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200

int main(){
	int a[MAX],i,x,temp;
	clock_t t1,t2;
	t1=clock();
	for(i=0;i<MAX;i++){
		a[i]=rand();
	}
	printf("enter the element to be searched:");
	scanf("%d",&x);
	//beginning of the linear search
	for(i=0;i<MAX;i++)
	{
		if(a[i]==x){
			temp=i;//stores the value 
		 printf("found:%d",temp);
		}
	}
	t2=clock();
	float t=(t2-t1)/CLOCKS_PER_SEC;
	printf("time taken is:%f",t);
	return 0;
}

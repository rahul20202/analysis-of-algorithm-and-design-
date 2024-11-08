#include<stdio.h>
#define MAX 100

int main(){
	int a[MAX],i,x,n,temp;
	printf("enter the size of array\n");
	scanf("%d",&n);
	printf("enter the elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the element to be searched in the list");
	scanf("%d",&x);
	//beginning of the linear search
	for(i=0;i<n;i++)
	{
		if(a[i]==x){
			temp=i;//stores the value 
		return printf("found:%d",temp);
		}
	}
	
	return 0;
}

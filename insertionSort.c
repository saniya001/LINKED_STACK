#include<stdio.h>
#include<stdlib.h>
void InsertionSort(int *ptr,int n)  //  0 4 3 2 1  //0 4 3 2 1 //0 4 4 2 1//0 3 4 2 1//0 3 4 4 1//0 3 3 4 1//2 3 3 4 1
{
	int i,j,k,item;
	for(i=1;i<n;i++)
	{
		item=*(ptr+i);
		j=i-1;
		while(j>=0 && *(ptr+j)>item)
		{
			*(ptr+j+1)=*(ptr+j);
			j--;
		}
		*(ptr+j+1)=item;
	//	printf("done");
		
	}
		for(k=0;k<n;k++)
	{
		printf("%d",*(ptr+k));
	}
	
}
int main()
{
	int i,*ptr,n;
	printf("enter the array size \n");
	scanf("%d",&n);
	ptr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",(ptr+i));
	}
	InsertionSort(ptr,n);
	int k;

	return 0;
}

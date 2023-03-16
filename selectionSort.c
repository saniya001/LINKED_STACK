#include<stdio.h>
#include<stdlib.h>
void SelectionSort(int *ptr,int n)
{
	int i,j,k,tmp,smallest;
	for(i=0;i<n-1;i++)
	{
		
		smallest=i;
		for(j=i+1;j<n;j++)
		{
			if(*(ptr+j)<*(ptr+smallest))
			{
				smallest=j;
			}
		}
			if(smallest!=i)
			{
				tmp=*(ptr+smallest);
				*(ptr+smallest)=*(ptr+i);
			    *(ptr+i)=tmp;
			}
	}
	//int k;
	for(k=0;k<n;k++)
	{
		printf("%d",*(ptr+k));
	}
}

int main()
{
	int i,*ptr,n;
//	int arr[100];
	printf("enter the array size \n");
	scanf("%d",&n);
	
	ptr=(int *)malloc(n*sizeof(int));
	printf("enter the elements \n");
	for(i=0;i<n;i++)
	{
	 scanf("%d",ptr+i)	;
	}
	SelectionSort(ptr,n);
	return 0;
}

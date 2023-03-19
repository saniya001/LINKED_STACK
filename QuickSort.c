#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int partition(int *ptr,int low,int high)
{
	    int pivot,i,j;
	    pivot=*(ptr+low);
	    j=low;
	    for(i=low+1;i<=high;i++)
     	{
		 if(*(ptr+i)<pivot)
		    {
		    	j++;
		    	swap(&*(ptr+j),&*(ptr+i));
	    	}
	    } 
	    swap(&*(ptr+low),&*(ptr+j));
	    return j;
}
void QuickSort(int *ptr,int low,int high)
{
	int j;
	if(high>low)
	{
	 j=partition(ptr,low,high);
     QuickSort(ptr,low,j-1);
	 QuickSort(ptr,j+1,high);	
	}
	
}
int main()
{
	int n,*ptr,i;
	printf("enter the size of array \n");
	scanf("%d",&n);
	ptr=(int *)malloc(n*sizeof(int));
	printf("enter the contents of the array \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(ptr+i));
	}
	QuickSort(ptr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",*(ptr+i));
	}
	return 0;
	
}

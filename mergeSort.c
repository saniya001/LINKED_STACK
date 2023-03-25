#include<stdio.h>
#include<stdlib.h>
int arr[100];
void merge(int *ptr,int low,int mid,int high)
{
int *b;// secondary array 
b=(int*)malloc((high+1)*sizeof(int));//high+1 bcz size of array should be same as the OG array which is low=0 high=7 so high+1=8
	int h,j,i,k;
	h=low;//will travers first part
	j=mid+1;//travers scond half
	i=low;//for traversing through the new array
	while(h<=mid&&j<=high)//checking if array is exhausted
	{
		if(*(ptr+h)<=*(ptr+j))// checing which element is lesser to sort it in order
		{
			*(b+i)=*(ptr+h);
			h++;
		}else
		{
			*(b+i)=*(ptr+j);
			j++;
		}
		i++;
	}
	if(h>mid)//the first array is exhauted so now copy rest of the elements from second array
	{
		for(k=j;k<=high;k++)
		{
			*(b+i)=*(ptr+k);
			i++;
		}
	}else// second array exhauted copy from first array
	{
	for(k=h;k<=mid;k++)
		{
			*(b+i)=*(ptr+k);
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		*(ptr+k)=*(b+k);
	}
}
void mergeSort(int *ptr,int low,int high)
{
	int mid;
if(high>low) //if array elements is more than 1 then only it will enter here(1 element is always sorted)
{	
	mid=(low+high)/2;//splitted into two parts
	mergeSort(ptr,low,mid);//recursive call of 0-mid
	mergeSort(ptr,mid+1,high);//recusive call of mid+1 to end 
	merge(ptr,low,mid,high);// the merging operation
}
}
int main()
{
	int a,i,n;
	int *ptr;
	printf("enter array size\n");
	scanf("%d",&n);
	ptr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	mergeSort(ptr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",*(ptr+i));
	}
	return 0;
}

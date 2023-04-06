#include<stdio.h>
#include<stdlib.h>
int findLargestNo(int *ptr,int n)
{
	int largest=*(ptr+0),i;
	for(i=0;i<n;i++)
	{
		if(*(ptr+i)>largest)
		{
			largest=*(ptr+i);
		}
	}
	return largest;
}
int noOfDigit(int largest)
{
	int digit=0;
	while(largest!=0)
	{
		digit+=1;
		largest/=10;
	}
	return digit;
}
void radixSort(int *ptr,int n)
{
	int buck[10],bucket[10][10],row,i,j,pass;
	int divisor=1;
	int largest=findLargestNo(ptr,n);
	int digit=noOfDigit(largest);
	for(pass=1;pass<=digit;pass++)
	{
		for(i=0;i<10;i++)// buck size is always 10 ie. 0-9 cz we only have 10 uniquw numbers 
		{
			buck[i]=0;//bucket filling and refilling with 0 in every pass
		}
		for(j=0;j<n;j++)
		{
		row=(*(ptr+j)/divisor)%10; //getting row position from the lsb of the element
		bucket[row][buck[row]]=*(ptr+j);//putting elemnt into bucket(2d) using buck array
		buck[row]++; // incrementing buck postions value to make sure next time we choose the next column as buck helps us to select the column
	    }
	    int k=0;
	    for(i=0;i<10;i++) //putting back eelmnts to the array from 2D bucket after each pass//row value is fixed
	    {
	    	for(j=0;j<buck[i];j++) // clumn values varries saccorind to the buck so we are using buck array to access no of column per row
	    	{
	    		*(ptr+k)=bucket[i][j];
	    		k++;
			}
		}
		divisor=divisor*10; //so that in every pass our next lsb choosing process becomes easy
	}
	printf("the sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",*(ptr+i));
	}
}
int main()
{
	int n,*ptr,i;
	printf("enter the number of elements in the array \n");
	scanf("%d",&n);
	ptr=(int *)malloc(n*sizeof(int));
	printf("enter the array elemts \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",ptr+i);
	}
	radixSort(ptr,n);
	return 0;
}

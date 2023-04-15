//this is priority circular queue
//but its bit different as there doubly queue concept is used to overcome some limitations
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int pqueue[MAX];
int front=-1;
int rear=-1;
void Enqueue(int item)
{
	int i,j;
	if(front==(rear+1)%MAX)
  {
  	printf("Priority QUEUE is FULL \n");
  	return;
  }
  
  if(front==-1)
  { 
    front=0;
    rear=0;
    pqueue[rear]=item;
  }
  else if((rear+1)%MAX==0)
  {
  	front=(front+(MAX-1))%MAX;
  	pqueue[front]=item;
  }else
  {
  	rear=rear+1;
  	pqueue[rear]=item;
  }
  
 for(i=front;i<rear;i++)
  {
  	for(j=i+1;j<=rear;j++)
  	{
  		if(pqueue[j]<pqueue[i])
  		{
  		int temp;
  		temp=pqueue[i];
  		pqueue[i]=pqueue[j];
  		pqueue[j]=temp;
		}     
	}
  }
}

void Dequeue()
{
	if(front==-1)
	{
		printf("PRIORITY QUEUE IS EMPTY \n");
		return;
	}
	printf("%d is deleted",pqueue[front]);
	if(front==rear)
	{
		front=rear=-1;
		printf("PRIORITY QUEUE IS EMPTY \n");
	}else
	{
		front=(front+1)%MAX;
	}
}
void Display()
{
	int i,j;
	if(front<rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",pqueue[i]);
		}
	}else
	{
		for(i=front;i<=MAX-1;i++)
		{
			printf("%d ",pqueue[i]);
		}
		for(j=0;j<=rear;j++)
		{
			printf("%d ",pqueue[j]);
		}
	}
}
int main()
{
	int choice,item;
	while(1)
	{
		printf("\n *******................PRIORITY QUEUE..................*******\n");
		printf("1.Enqueue \n");
		printf("2.Dequeue \n");
		printf("3.Display \n");
		printf("4.Exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element \n");
				scanf("%d",&item);
				Enqueue(item);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("ENTER A VALID NUMBER \n");
		}
	}
}

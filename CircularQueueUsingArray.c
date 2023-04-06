#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int rear=-1;
int front=-1;
void Enqueue(int item)
{
	if(front==(rear+1)%MAX)
	{
		printf("QUEUE OVERFLOW");
		return ;
	}
	if(front==-1)
	{
		front=rear=1;
	}else
	{
		rear=(rear+1)%MAX;
	}
	queue[rear]=item;
	
} 
void Dequeue()
{
	int item;
	if(front==-1)
	{
		printf("QUEUE UNDERFLOW \n");
		return ;
	}
	item=queue[front];
	printf("%d is deleted",item);
	if(front==rear)
	{
		printf("QUEUE is EMPTY \n");
		front=rear=-1;
	}else
	{
	front=(front+1)%MAX;
    }
	
}
void Display()
{
	int i;
	if(front<rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}else
	{
		for(i=front;i<=MAX-1;i++)
		{
			printf("%d ",queue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}
int main()
{
	int n;
	while(1)
	{
		printf("*******................CIRCULAR QUEUE..................*******\n");
		printf("1.Enqueue \n");
		printf("2.Dequeue \n");
		printf("3.Display \n");
		printf("4.Exit \n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:printf("enter the item \n");
			       int item;
			       scanf("%d",&item);
			       Enqueue(item);
			       break;
		    case 2:Dequeue();
		           break;
		    case 3:Display();
		           break;
		    case 4:exit(0);
			
		}
	}
	
return 0;
	
}

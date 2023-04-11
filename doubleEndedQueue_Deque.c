//double ended Queue//
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Deque[MAX];
int front=-1;
int rear=-1;

void insert_using_rear(int item){
	if(front==(rear+1)%MAX)
	{
		printf("QUEUE OVERFLOW!!! \n");
		return;
	}
	if(front==-1)
	{
	    front=0;
		rear=0;	
	}else
	{
		rear=(rear+1)%MAX;
	}
	Deque[rear]=item;
}
void insert_using_front(item){
	if(front==(rear+1)%MAX)
	{
		printf("DEQUE OVERFLOW!!! \n");
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}else
	{
	    front=(front+(MAX-1))%MAX;
	}
	Deque[front]=item;
	
}
void delete_using_front(){
if(front==-1)
{
	printf("DEQUE UNDERFLOW \n");
	return;
}
printf("%d is deleted",Deque[front]);
if(front==rear){
	front=-1;
	rear=-1;
	printf("DEQUE is empty \n");
}else{
	front=(front+1)%(MAX);
}
}
void delete_using_rear()
{
	if(front==-1)
	{
		printf("DEQUE UNDERFLOW \n");
		return;
	}
	printf("%d is deleted",Deque[rear]);
	if(front==rear){
		front=-1;
	    rear=-1;
     	printf("DEQUE is empty \n");
	}else{
		rear=((rear+(MAX-1))%MAX);
	}
	
}
void Display(){
	int i;
	if(front==-1)
	{
		printf("Deque is empty \n");
		return;
	}if(front<rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",Deque[i]);
		}
	}else{
	    for(i=front;i<=MAX-1;i++)
	    {
	    	printf("%d ",Deque[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d ",Deque[i]);
		}
	}
}
int main()
{
	int choice,item;
	while(1)
	{
		printf("\n1.insert using rear \n");
		printf("2.insert using front \n");
		printf("3.delete using front \n");
		printf("4.delete using rear \n");
		printf("5.Display \n");
		printf("6.Exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				//int item;
				printf("Enter your element \n");
				scanf("%d",&item);
				insert_using_rear(item);
				break;
			case 2:
				printf("Enter your element \n");
				scanf("%d",&item);
				insert_using_front(item);
				break;
			case 3:
			    delete_using_front();
			    break;
			case 4:
				delete_using_rear();
			    break;
			case 5:
				Display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("enter valid number");
				break;
			
				
		}
	}
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node* link;
};
struct node *top=NULL;
struct node *ptr=NULL;
void push(char item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("INSUFICIENT MEOMORY \n");
		exit(0);
	}
	temp->data=item;
	temp->link=top;
	top=temp;
}
void pop()
{

	ptr=top;
	top=top->link;
	free(ptr);
	
}
void Display()
{
	if(top==NULL)
	{
		printf("there are no elements in the stack \n");
		//exit()
	}else
	{
	printf("top->");
	ptr=top;
	while(ptr!=NULL)
	{
		printf("%c ->",ptr->data);
		ptr=ptr->link;		
	}
	printf("NULL \n");
   }
}
int main()
{
	int ch;
	char item;
	while(1)
	{
		printf("PRESS 1. TO PUSH \n");
		printf("PRESS 2. TO POP \n");
		printf("PRESS 3. TO DISPLAY \n");
		printf("PRESS 4. TO EXIT \n");
		scanf("%d",&ch);
		fflush(stdin);
		switch(ch)
		{
			case 1:
				printf("ENTER THE ITEM YOU WANT TO INSERT  \n");
				scanf("%c",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				Display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("PLEASE ENTER A VALID NUMBER \n");
		}

	}
	return 0;
}

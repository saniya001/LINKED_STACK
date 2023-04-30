//all tree applications implemented using non-recursive way
//array of structure is used at line no 13.
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
struct node 
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
struct node *root=NULL;
struct node *stack[MAX];
int top=-1;
void push(struct node *ptr)
{
	if(top==MAX-1)
	{
		printf("SORRY the stack is full \n");
		return;
	}
	//top++;
	stack[++top]=ptr;
}
struct node *pop()
{
	if(top==-1)
	{
		printf("Sorry the stack is empty \n");
		return;
	}
	return stack[top--];
//	top--;
	
}

void create(int item)
{
	struct node *ptr,*temp,*par=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
	    par=ptr;
    	if(item<ptr->data)
	    {
	     ptr=ptr->lchild;	
	    }
	    else if(item>ptr->data)
	    {
	     ptr=ptr->rchild;	
	    }
	    else
	    {
		printf("the numbers are of same value \n");
		return;
	    }
	}
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(par==NULL)
	{
		root=temp;
	}else if(item < par->data)
	{
			par->lchild=temp;
	}
	else if(item > par->data)
	{
			par->rchild=temp;
	}
}
void inorder(struct node *ptr)
{
	while(1)	{
	while(ptr->lchild!=NULL)
	{
		push(ptr);
		ptr=ptr->lchild;
	}
	while(ptr->rchild==NULL)
	{
		printf("%d ",ptr->data);
		if(top==-1)
		return;
		ptr=pop();
	}
	printf("%d ",ptr->data);
	ptr=ptr->rchild;
}
	
}
void preorder(struct node *ptr)
{
	push(ptr);
	while(top!=-1)
	{
	ptr=pop();
	printf("%d ",ptr->data);
	if(ptr->rchild!=NULL)
	{
		push(ptr->rchild);
	}
	if(ptr->lchild!=NULL)
	{
	    push(ptr->lchild);
	}
    }
}
void postorder(struct node *ptr)
{
	struct node *q;
	q=ptr;
	while(1)
	{
		while(ptr->lchild!=NULL)
		{
			push(ptr);
			ptr=ptr->lchild;
		}
		while(ptr->rchild==NULL || ptr->rchild==q)
		{
			printf("%d ",ptr->data);
			q=ptr;//keeping track of previously visited node
			if(top==-1)
			{
				return;
			}
			ptr=pop();
		}
		push(ptr);
		ptr=ptr->rchild;
	}
}
void search(int key)
{
	struct node *ptr=root;
	while(ptr!=NULL)
	{
		
	    if(key<ptr->data)
	   	{
			ptr=ptr->lchild;
		}else if(key>ptr->data)
		{
			ptr=ptr->rchild;
		}else
		{
			printf("the key %d is found",key);
			break;
		}
      if(ptr==NULL)
       {
		    printf("SORRY the key %d has not been found",key);
	   }
   }
}
int main()
{
	int choice,item,key;
	while(1)
	{
		printf("\n TREE \n");
		printf("1.create \n");
		printf("2.Pre-order Trvaversal \n");
		printf("3.In-order traversal \n");
		printf("4.Post-order traversal \n");
		printf("5.Searching BST \n");
		printf("6.EXIT");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the item \n");
				scanf("%d",&item);
				create(item);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				printf("enter the key you want to find \n");
				scanf("%d",&key);
				search(key);
				break;
			case 6:
				break;
			default:
				printf("Enter a valid naumber \n");
		}
		
	}
	return 0;
}

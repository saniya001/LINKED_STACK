//tree creation using non-recursive approach and traversal using recursive approach;
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
struct node*root=NULL;
void create(int item)
{
	struct node *ptr,*temp,*par=NULL;
	ptr=root;
	while(ptr!=NULL)
	{
		par=ptr;
		if(item < ptr->data)
		{
			ptr=ptr->lchild;
		}else if(item >ptr->data)
		{
			ptr=ptr->rchild;
		}
	}
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->lchild=NULL;
	temp->rchild=NULL;
	if(par==NULL)
	{
	root=temp;
    }else if(item < par->data)
    {
    	par->lchild=temp;
	}else if(item > par->data)
	{
		par->rchild=temp;
	}
	
}
void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void postorder(struct node *ptr){
	if(ptr!=NULL){
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d\t",ptr->data);
		
	}
}
void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d ",ptr->data);
		inorder(ptr->rchild);
	}
}
int main()
{
	int choice,item;
	while(1)
	{
		printf("\n*****************Binary Tree********************\n");
		printf("1.Create \n");
		printf("2.Pre-order Traversal \n");
		printf("3.In-order Traversal \n");
		printf("4.Post-order Traversal \n");
		printf("5.Exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter The item");
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
				break;
			default:
				printf("Enter a valid Choice \n");
		}
	}
	return 0;
}

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int degree;
	int data;
	struct node *parent;
	struct node *child;
	struct node *sibling;
};
struct node *start1=NULL;//start 1 is used to maintain the exsisting heap 
struct node *start2=NULL;//start 2 is used to add the new value to the exsisting heap
struct node *insert(struct node *,struct node *,int);
void *display(struct node *) ;
struct node *union_heap(struct node *,struct node *);
int main()
{
	int value,option;
	do
	{
		printf("\n======================================================================================\n");
		printf("\n Press 1 to insert teh value in the Binomial Heap\n");
		printf("\n Press 2 to display the values in the Binomial Heap\n");
		printf("\n Enter the option you want to perform\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the value to be inseretd in the Binomial Heap\n");
				scanf("%d",&value);
				start1=insert(start1,start2,value);
				break;
			case 2:
				display(start1);
				break;
				
		}
	}
	while(option!=3);
	getch();
}
struct node *insert(struct node *start2,struct node *start1,int value)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start2;
	if(ptr==NULL)
	{
		printf("\n case 2\n");
		new_node->data=value;
		new_node->child=NULL;
		new_node->degree=0;
		new_node->parent=NULL;
		new_node->sibling=NULL;
		start2=new_node;
	}
	else
	{
		new_node->data=value;
		new_node->child=NULL;
		new_node->degree=0;
		new_node->parent=NULL;
		new_node->sibling=start2;
		start1=new_node;
		start2=union_heap(start1,start2);
	}
	return(start2);
}
void *display(struct node *start2)
{
	struct node *ptr;
	ptr=start2;
	if(ptr==NULL)
	{
		printf("\nThere are no elements in the binomial heap\n");
		
	}
	else
	{
		printf("\n The Degrees of all the nodes at the parent level are\n\n");
		while(ptr!=NULL)
		{
			printf("%d",ptr->degree);
			printf("\n");
	        ptr=ptr->sibling;
		}

	}
	
}
struct node *union_heap(struct node *start1,struct node *start2)
{
	struct node *ptr1,*ptr2,*buffer;
	ptr1=start1;
	ptr2=start2;
	while(ptr2!=NULL)
	{
		if(ptr1->degree==ptr2->degree)
		{
			if(ptr1->data>=ptr2->data)
			{
				buffer=ptr2->child;
				ptr2->child=ptr1;
				ptr1->parent=ptr2;
				ptr1->sibling=buffer;
				ptr2->degree=ptr2->degree+1;
				ptr1=ptr2;
				ptr2=ptr2->sibling;
				start2=ptr1;
			}
			else
			{
				buffer=ptr2->sibling;
				ptr1->child=ptr2;
				ptr2->parent=ptr1;
				ptr1->degree=ptr1->degree+1;
				ptr2=buffer;
				start2=ptr1;
				
			}
		}
		else
		{
			start2=ptr1;
			break;
		}
	}
	return(start2);
}

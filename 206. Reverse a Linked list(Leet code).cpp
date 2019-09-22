#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
struct node *insert(struct node *,int);
struct node *reverse_linkedlist(struct node *);
void *display(struct node *);
int main()
{
	int option,value;
	do
	{
		printf("\n================================================================================\n");
		printf("\n Press 1 to enter the value in the linked list\n");
		printf("\n Press 2 to display the value in the linked list\n");
		printf("\n Press 3 to Reverse the elements of the linked list\n");
		printf("\n Enter the option you want to perform\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				printf("\n Enter the value to be inserted in the linked list\n");
				scanf("%d",&value);
				start=insert(start,value);
				break;
			case 2:
				display(start);
				break;
			case 3:
				start=reverse_linkedlist(start);
				display(start);
				break;
		}
	}
	while(option!=4);
	getch();
}
struct node *insert(struct node *start, int value)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(ptr==NULL)
	{
		start=new_node;
		new_node->data=value;
		new_node->next=NULL;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->data=value;
		new_node->next=NULL;
	}
	return(start);
}
void *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the linked list\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\n");
			printf("%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
struct node *reverse_linkedlist(struct node *start)
{
	struct node *ptr,*preptr,*nextptr;///we need three pointers to traverse the list next pointer(nextptr),previous pointer(preptr),ptr(current ptr)
	ptr=start;
	preptr=start;
	if(start==NULL)///If there are no elements in the linkedlist
	{
		return(start);
	}
	else
	{
		nextptr=start->next;
		if(start!=NULL&&nextptr==NULL)///If there is only one element in the linkedlist
    	{
    		return(start);
    	}
    	else
    	{
    		preptr->next=NULL;///making the first element->next=NULL
	    	while(nextptr!=NULL)
	    	{
		    	ptr=nextptr;
	    		nextptr=nextptr->next;
	    		ptr->next=preptr;
		    	preptr=ptr;
		    }
		    start=ptr;
	    	return(start);
	    }
	}
	
}

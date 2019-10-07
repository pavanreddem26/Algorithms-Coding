#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *start=NULL;
struct node *insert_end(struct node *,int);
struct node *insert_beg(struct node *,int);
struct node *insert_after(struct node *,int,int);
struct node *insert_before(struct node *,int,int);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *,int);
struct node *delete_before(struct node *,int);
void *display(struct node *);
void *search(struct node *,int);
int main()
{
	int value,option,after,before,search_value;
	do
	{
		printf("\n============================================================================================\n");
		printf("\n Press 1 to Insert the values at the END of linked list\n");
		printf("\n Press 2 to Insert the values at the STARTING of linked list\n");
		printf("\n Press 3 to Insert the values AFTER the certain node in linked list\n");
		printf("\n Press 4 to Insert the values BEFORE the certain node in linked list\n");
		printf("\n Press 5 to Delete the value from the beginning of the linked list\n");
		printf("\n Press 6 to Delete the value from the end of list\n");
		printf("\n Press 7 to Delete the value AFTER the given node in the linked list\n");
		printf("\n Press 8 to Delete the value BEFORE teh given node in the linked list\n");
		printf("\n Press 9 to display the values in the linked list\n");
		printf("\n Press 10 to Search whether the element is present in linked list or not\n");
		printf("\n Enter the option you want to perform\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the value to be inserted in the linked list\n");
				scanf("%d",&value);
				start=insert_end(start,value);
				break;
			case 2:
				printf("\n Enter the value to be inserted in the linked list\n");
				scanf("%d",&value);
				start=insert_beg(start,value);
				break;
			case 3:
				printf("\n Enter the value to be inserted in the linked list\n ");
				scanf("%d",&value);
				printf("\n Enter AFTER which node this new value should be inserted\n");
				scanf("%d",&after);
				start=insert_after(start,value,after);
				break;
			case 4:
				printf("\n Enter the value to be inserted in the linked list\n ");
				scanf("%d",&value);
				printf("\n Enter BEFORE which node this new value should be inserted\n");
				scanf("%d",&before);
				start=insert_before(start,value,before);
				break;
			case 5:
				start=delete_beg(start);
				break;
			case 6:
				start=delete_end(start);
				break;
			case 7:
				printf("\n Enter AFTER which node you want to delete the value\n");
				scanf("%d",&after);
				start=delete_after(start,after);
				break;
			case 8:
				printf("\n Enter BEFORE which node you want to delete the value\n");
				scanf("%d",&before);
				start=delete_before(start,before);
				break;
			case 9:
				display(start);
				break;
			case 10:
				printf("\n Enter the value you want to search\n");
				scanf("%d",&search_value);
				search(start,search_value);
				break;
					
		}
	}
	while(option!=11);
	getch();
}
struct node *insert_end(struct node *start,int value)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(ptr==NULL)
	{
		start=new_node;
		new_node->next=NULL;
		new_node->prev=NULL;
		new_node->data=value;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
		new_node->prev=ptr;
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
		printf("\n There are no elements in the array\n");
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
struct node *insert_beg(struct node *start,int value)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(ptr==NULL)
	{
		new_node->next=NULL;
		new_node->prev=NULL;
		new_node->data=value;
		start=new_node;
	}
	else
	{
		new_node->prev=NULL;
		new_node->next=start;
		start->prev=new_node;
		new_node->data=value;
		start=new_node;
	}
	return(start);
}
struct node *insert_after(struct node *start,int value,int after)
{
	struct node *ptr,*preptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	preptr=start;
	if(ptr==NULL)
	{
		return(NULL);
	}
	else
	{
		while(preptr->data!=after)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=new_node;
		new_node->next=ptr;
		new_node->prev=preptr;
		ptr->prev=new_node;
		new_node->data=value;
	}
	return(start);
}
struct node *insert_before(struct node *start,int value,int before)
{
	struct node *ptr,*preptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	preptr=start;
	if(ptr==NULL)
	{
		return(NULL);
	}
	else
	{
		while(ptr->data!=before)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=new_node;
		new_node->next=ptr;
		new_node->prev=preptr;
		ptr->prev=new_node;
		new_node->data=value;
	}
	return(start);
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=start->next;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the list\n");
		return(NULL);
	}
	else
	{
		start=preptr;
		preptr->prev=NULL;
		free(ptr);	
	}
	return(start);
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\n There no elements in the linked list\n");
		return(NULL);
	}
	else
	{
		while(ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=NULL;
		free(ptr);
		return(start);
	}
}
struct node *delete_after(struct node *start,int after)
{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the linked list\n");
		return(NULL);
	}
	else
	{
		while(preptr->data!=after)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		ptr->next->prev=preptr;
		return(start);
	}
}
struct node *delete_before(struct node *start,int before)
{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the linked list\n");
		return(NULL);
	}
	else
	{
		while(ptr->data!=before)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		ptr->prev=preptr->prev->next;
		preptr->prev->next=ptr;
		return(start);
		
	}	
}
void *search(struct node *start,int search_value)
{
	struct node *ptr;
	int flag;
	flag=0;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the array to search\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==search_value)
			{
				printf("\n Value is present in the linked list\n");
				flag=1;
				break;
			}
			else
			{
				ptr=ptr->next;
			}
		}
	}
	if(flag==0)
	{
		printf("\n Entered value not found in the linked list\n");
	}
}

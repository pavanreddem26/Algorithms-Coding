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
struct node *insert_beg(struct node *,int);
struct node *insert_after(struct node *,int,int);
struct node *insert_before(struct node *,int,int);
struct node *insert_end(struct node *,int);
struct node *delete_beg(struct node *);
struct node *delete_after(struct node *,int);
struct node *delete_before(struct node *,int);
struct node *delete_end(struct node *);
void *search(struct node *,int);
void *display(struct node *);
int main()
{
	int option,value,after,before;
	do
	{
		printf("\n==================================================================\n");
		printf("\nPress 1 to Insert the value at the BEGINNING of linked list\n");
		printf("\nPress 2 to Insert the value AFTER the certain node in linked list\n");
		printf("\nPress 3 to Insert the value BEFORE the given node in linked list\n");
		printf("\nPress 4 to Insert the value END of the  linked list\n ");
		printf("\nPress 5 to Delete the value at the BEGINNING of the list\n");
		printf("\nPress 6 to Delete the value AFTER a certain node in the linked list\n");
		printf("\nPress 7 to Delete the value BEFORE a certain node in the linked list\n");
		printf("\nPress 8 to Delete the value at the END of the linked list\n");
		printf("\nPress 9 to Search for the value in the linked list\n");
		printf("\nPress 10 to display the values in the linked list\n");
		printf("\n Enter the option you want to perform\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the value to be inserted in the list\n");
				scanf("%d",&value);
				start=insert_beg(start,value);
				break;
			case 2:
		    	printf("\n Enter the value to be inserted in the list\n");
				scanf("%d",&value);
				printf("\n Enter AFTER which node you want to insert this value\n");
				scanf("%d",&after);
				start=insert_after(start,value,after);
				break;
			case 3:
				printf("\n Enter the value to be inserted in the list\n");
				scanf("%d",&value);
				printf("\n Enter BEFORE which node you want to insert this value\n");
				scanf("%d",&before);
				start=insert_before(start,value,before);
				break;
				break;
			case 4:
				printf("\n Enter the value to be inserted in the list\n");
				scanf("%d",&value);
				start=insert_end(start,value);
				break;
				break;
			case 5:
				start=delete_beg(start);
				break;
			case 6:
				printf("\n Enter the value AFTER which you want to delete the node\n");
				scanf("%d",&after);
				start=delete_after(start,after);
				break;
			case 7:
				printf("\n Enter the value BEFORE which you want to delete the node\n");
				scanf("%d",&before);
				start=delete_before(start,before);
				break;
			case 8:
				start=delete_end(start);
				break;
			case 9:
				printf("\n Enter the value you want to search in the linked list\n");
				scanf("%d",&value);
				search(start,value);
				break;
			case 10:
				display(start);
				break;		
			
		}
	}
	while(option!=11);
	getch();	
}
struct node *insert_beg(struct node *start,int value)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(ptr==NULL)
	{
		new_node->data=value;
		new_node->next=NULL;
		start=new_node;
	}
	else
	{
		new_node->next=start;
		new_node->data=value;
		start=new_node;
	}
	return(start);
}
struct node *insert_end(struct node *start,int value)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the linked list\n");
		return(NULL);
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
struct node *insert_after(struct node *start,int value,int after)
{
	struct node *ptr,*preptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	preptr=start;
	new_node=(struct node *)malloc(sizeof(struct node));
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
		preptr->next=new_node;
		new_node->next=ptr;
		new_node->data=value;
	}
	return(start);
}
struct node *insert_before(struct node *start,int value,int before)
{
	struct node *ptr,*preptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=start;
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
		preptr->next=new_node;
		new_node->next=ptr;
		new_node->data=value;
	}
	return(start);
}
struct node *delete_after(struct node *start,int after)
{
	struct node *ptr,*preptr;
	ptr=start;
	preptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the array\n");
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
		free(ptr);
	}
	return(start);
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
		while(ptr->next->data!=before)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	}
	return(start);
}
void *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the single linked list\n");
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
void *search(struct node *start,int value)
{
	struct node *ptr;
	int flag;
	flag=0;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the linked list\n");
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==value)
			{
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
		printf("\n The entered value is not present in the linked list\n");
	}
}
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		return(NULL);
	}
	else
	{
		start=ptr->next;
		free(ptr);
		return(start);
	}
}
struct node *delete_end(struct node *start)
{
	struct node *ptr,*preptr;
	ptr=start;
	if(ptr==NULL)
	{
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
		return(start);
	}
	
}


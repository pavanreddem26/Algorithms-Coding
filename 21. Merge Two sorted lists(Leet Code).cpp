//Merge two sorted lists
//Time complexity------Linear(n)
//space complexity-----Constant Space used

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start_merge=NULL;
struct node *insert(struct node *,int);
void *display(struct node *);
struct node *merge_lists(struct node *,struct node *);
int main()
{
	int data,option,value;
	do
	{
		printf("\n=========================================================\n");
		printf("\n Press 1 to insert value into the linked list 1\n");
		printf("\n Press 2 to insert value into the linked list 2\n");
		printf("\n Press 3 to display the values in the linked list 1\n");
		printf("\n Press 4 to display the values in the linkedlist 2\n");
		printf("\n Press 5 to merge two sorted lists\n");
		printf("\n Enter the option you want to perform\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the value to be inserted in the linkedlist 1\n");
				scanf("%d",&value);
				start1=insert(start1,value);
				break;
			case 2:
				printf("\n Enter the value to be inserted in the linkedlist 2\n");
				scanf("%d",&value);
				start2=insert(start2,value);
				break;
			case 3:
				display(start1);
				break;
			case 4:
				display(start2);
				break;
			case 5:
				start_merge=merge_lists(start1,start2);
				display(start_merge);
				break;
		}
	}
	while(option!=6);
	getch();
}
struct node *insert(struct node *start,int value)
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
		printf("\n There are no elements in the list\n");
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
struct node *merge_lists(struct node *start1,struct node *start2)
{
	struct node *ptr1,*ptr2,*preptr1,*preptr2,*dummy;
	ptr1=start1;
	ptr2=start2;
	if(ptr1==NULL && ptr2==NULL)
	{
		printf(" \nThere are no elements in the list to sort\n");
		return(NULL);
	}
	else if(ptr1==NULL && ptr2!=NULL)///list 1 os empty and list 2 is not empty
	{
		return(ptr2);
	}
	else if(ptr1!=NULL && ptr2==NULL)//list 1 is not empty and list 2 is empty
	{
		return(ptr1);
	}
	else///if both the lists are not empty
	{
		if(ptr1->data<=ptr2->data)///if ptr1 data is less than ptr 2
		{
			
			start_merge=ptr1;
			while(ptr1!=NULL && ptr2!=NULL)
			{
				if(ptr1->data<=ptr2->data)
				{
					preptr1=ptr1;
					ptr1=ptr1->next;
				}
				else
				{
					dummy=ptr2;
					ptr2=ptr2->next;
					preptr1->next=dummy;
					dummy->next=ptr1;
				}
    		}
		}
		else///if ptr1 data is greater than the ptr data
		{
			start_merge=ptr2;
			while(ptr1!=NULL && ptr2!=NULL)
			{
				if(ptr2->data<=ptr1->data)
				{
					preptr2=ptr2;
					ptr2=ptr2->next;
				}
				else
				{
					dummy=ptr1;
					ptr1=ptr1->next;
					preptr2->next=dummy;
					dummy->next=ptr2;
				}
			}

		}
		
	}
	if(ptr1==NULL&&ptr2!=NULL)///if one list is NULL and the other list is not all this indicates that elements in the list which are
	// not NULL are greater than the elements in the list that are NULL.
	{
		preptr1->next=ptr2;
	}
	else
	{
		preptr2->next=ptr1;
			
	}
	return(start_merge);
}

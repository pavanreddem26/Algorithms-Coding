#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;///for the time being I wil use the xtra menmory
struct node *start1=NULL;
struct node *start2=NULL;
struct node *insert(struct node *,int);
struct node *add(struct node *,struct node *);
void *display(struct node *);
int main()
{
	int option,value;
	do
	{
		printf("\n==========================================================\n");
		printf("\n Press 1 to Enter the values in linked list 1\n");
		printf("\n Press 2 to Enter the values in linked list 2\n");
		printf("\n Press 3 to add the elements in linked lists\n");
		printf("\n Press 4 to display the values in linked list 1\n");
		printf("\n Press 5 to display the values in linked list 2\n");
		printf("\n Press 6 to display the elements after addition\n");
		printf("\n Enter the option you want to perform\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the value to be inserted in the list 1\n");
				scanf("%d",&value);
				start1=insert(start1,value);
				break;
			case 2:
				printf("\n Enter the value to be inserted in the list 2\n");
				scanf("%d",&value);
				start2=insert(start2,value);
				break;
			case 3:
				start=add(start1,start2);
				break;
			case 4:
				display(start1);
				break;
			case 5:
				display(start2);
				break;
			case 6:
				display(start);
				break;
					
		}
		
	}
	while(option!=7);
	getch();
}
struct node *insert(struct node *s,int value)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	ptr=s;
	if(ptr==NULL)
	{
		s=new_node;
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
		new_node->next=NULL;
		new_node->data=value;
	}
	return (s);
}
void *display(struct node *s)
{
	struct node *ptr;
	ptr=s;
	while(ptr!=NULL)
	{
		printf("\n");
		printf("%d",ptr->data);
		ptr=ptr->next;
	}
}
struct node *add(struct node *s1,struct node *s2)
{
	struct node *ptr1,*preptr1,*preptr2,*ptr2,*new_node;
	int carry,sum,num,list1,list2;
	new_node=(struct node *)malloc(sizeof(struct node));
	carry=0;
	sum=0;
	num=0;
	ptr1=s1;
	ptr2=s2;
	list1=0;
	list2=0;
	while(ptr1!=NULL)///counting the number of elements in the list 1
	{
		list1=list1+1;
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)///counting the number of elements in list 2
	{
		list2=list2+1;
		ptr2=ptr2->next;
	}
	printf("\n The number of elements in the list 1 are\n");
	printf("%d",list1);
	printf("\n The number of elements in the list 2 are\n");
	printf("%d",list2);
	ptr1=s1;
	ptr2=s2;
	if(list1==list2)// When the number of elements in list 1 is equal to list 2
	{

		while(ptr1!=NULL)
    	{
    		preptr1=ptr1;
    		sum=ptr1->data+ptr2->data+carry;
    		carry=sum/10;
    		num=sum%10;
    		ptr1->data=num;
    		ptr1=ptr1->next;
    		ptr2=ptr2->next;
    	}
    	if(carry!=0)///when we need to add carry as a last number
    	{

    		new_node->next=NULL;
    		new_node->data=carry;
    		preptr1->next=new_node;
		}
		return (s1);
	}
	else if(list1>list2)// The number of elements in list 1 is greater than number of elements in list 2
	{

		while(ptr1!=NULL)
		{
			preptr1=ptr1;
			if(ptr2==NULL)
			{

			       sum=ptr1->data+carry;
    	                       carry=sum/10;
    	    	               num=sum%10;
    	    	               ptr1->data=num;
    	    	               ptr1=ptr1->next;
			}
			else
			{

			    sum=ptr1->data+ptr2->data+carry;
    	    	            carry=sum/10;
    	    	            num=sum%10;
    	    	            ptr1->data=num;
    	    	            ptr1=ptr1->next;
    	    	            ptr2=ptr2->next;
			}

		}
		if (carry!=0)
		{

			preptr1->next=new_node;
			new_node->data=carry;
			new_node->next=NULL;
		}
		return (s1);
		
	}
	else//number of elements in the list 2 is greater than list 1
	{

		while(ptr2!=NULL)
		{
			preptr2=ptr2;
			if(ptr1==NULL)
			{

			      sum=ptr2->data+carry;
    	    	              carry=sum/10;
    	    	              num=sum%10;
    	                      ptr2->data=num;
    	    	              ptr2=ptr2->next;
			}
			else
			{

			      sum=ptr1->data+ptr2->data+carry;
    	    	              carry=sum/10;
    	    	              num=sum%10;
    	    	              ptr2->data=num;
    	    	              ptr1=ptr1->next;
    	    	              ptr2=ptr2->next;
			}

		}
		if(carry!=0)
		{

			preptr2->next=new_node;
			new_node->data=carry;
			new_node->next=NULL;
		}
		return(s2);
		
	}
}

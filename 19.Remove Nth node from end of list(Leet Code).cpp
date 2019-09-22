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
struct node *n_node_from_last(struct node*,int);
void *display(struct node *);
int main()
{
	int option,value,last;
	do
	{
		printf("\n=================================================\n");
		printf("\n Press 1 to enter the value in the linked list\n");
		printf("\n press 2 to remove the Nth node from last\n");
		printf("\n Press 3 to display the values in the linkedlist\n");
		printf("\n Enter the option you want to perform\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Enter the value to be inserted in the list\n");
				scanf("%d",&value);
				start=insert(start,value);
				break;
			case 2:
				printf("\n Enter the value from the last you want to delete\n");
				scanf("%d",&last);
				start=n_node_from_last(start,last);
				break;
			case 3:
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
		new_node->next=NULL;
		new_node->data=value;
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
	return(start);
}
void *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		printf("\n There are no elements in the linkedlist\n");
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
struct node *n_node_from_last(struct node *start,int last)
{
	struct node *ptr,*preptr;
	int count,m,n,loo;
	count=0;
	preptr=start;
	ptr=start;
	loo=1;
	if(start==NULL)
	{
		printf("\n there are no elements in the linked list\n");
		return(start);
	}
	else
	{
		while(ptr!=NULL)
    	        {
	         	count=count+1;
	         	ptr=ptr->next;
         	}
    	        printf("\n The total number of elements in th list are\n");
              	printf("%d",count);
    	        printf("\n");
        	ptr=start;
        	if(count>=last)///Considering last as the valid number
         	{
        	    	m=count-last+1;
        	}
	        else
        	{
	        	m=count-last;
         	}
	        printf("\n The value of m is \n");
         	printf("%d",m);
        	printf("\n");
        	if(count==1)////This is one of the most important case
        	{
	        	if(m<0)
	        	{
	    	        	printf("\n Entered value is greater than total number of elements in the list");
         	        	printf("\n No element is removed from the list\n");
        	        	return(start);
     	         	}
	           	else/// There is only one element and we are removing that element
	         	{
		         	start=NULL;
		        	return(NULL);
		         }
	         }
	         else
	         {
	         	if(m<0)
        	        {
        	        	printf("\n Entered value is greater than total number of elements in the list");
        	        	printf("\n No element is removed from the list\n");
        	        	return(start);
        	        }
        	       else
                 	{
        	        	while(loo!=m)
    	                	{
        	         		printf("\n test case 1\n");
     	    	                	preptr=ptr;
        		        	ptr=ptr->next;
    	    	                 	loo++;
    	                	}
    	                 	if(preptr==start)
    	                	{
     		                	start=preptr->next;
     	         	         	return(start);
    	          	        }
	        	        else
                        	{
    	                 		preptr->next=ptr->next;
    	                	    	free(ptr);
    	                		return(start);
    	                	}

		
                         }   
    	       }
    }
	

}

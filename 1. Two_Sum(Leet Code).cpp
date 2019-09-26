Analysis:
Runtime--O(n)
Hashmap search--O(1+α)
α-Number of collisons goes to each block of mapping

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int val;
	int ind;
	struct node *next;
};
struct node *insert(struct node *,int,int);
struct node *search(struct node *,int);
void *display(struct node *);
int main()
{
	int i,j,k,a[5],key,target,m;
	struct node *ptr,*start[3];
	for(i=0;i<3;i++)
	{
		start[i]=NULL;
	}
	for(i=0;i<5;i++)
	{
		printf("\n Enter the value to be inserted in the array\n");
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{

		printf("%d",a[i]);
		printf("\n");
	}
	printf("\n Enter the target value to find\n");
	scanf("%d",&target);
	for(i=0;i<5;i++)
	{
	
		key=a[i]%3;
		start[key]=insert(start[key],a[i],i);
	}
	for(i=0;i<5;i++)
	{
	
		m=target-a[i];
		key=m%3;
		printf("\n");
		printf("%d",key);
		ptr=search(start[key],m);
		if(ptr==NULL)
		{
		
			printf("\n There are no two elements that sum up to the target\n");
		}
		else
		{
		
			printf("\n There are two elements that sum up to the target\n");
			printf("\n Index 1\n");
			printf("%d",i);
			printf("\n Index 2\n");
			printf("%d",ptr->ind);
			
		}
	}
}
struct node *insert(struct node *start,int value,int index)
{
	struct node *ptr,*new_node;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->ind=index;
	new_node->val=value;
	ptr=start;
	if(ptr==NULL)
	{
	
		start=new_node;
		new_node->next=NULL;
	}
	else
	{
	
		new_node->next=start;
		start=new_node;
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
	
			printf("%d",ptr->val);
			printf("\n");
			printf("%d",ptr->ind);
			printf("\n");
			ptr=ptr->next;
		}
	}
}
struct node *search (struct node *start,int target)
{
	struct node *ptr;
	ptr=start;
	if(ptr==NULL)
	{
		return(NULL);
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->val==target)
			{
				return(ptr);
			}
			else
			{
				ptr=ptr->next;
			}
		}
	}
}

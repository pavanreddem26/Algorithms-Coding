#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	char c;
	struct node *left;
	struct node *right;
};
struct node *tree=NULL;
struct node *smallest=NULL;
struct node *biggest=NULL;
struct node *succ=NULL;
struct node *pred=NULL;
struct node *insert(struct node *,int);
struct node *fix_rb(struct node *,struct node *);
struct node *ll_rotate(struct node *,struct node *);
struct node *lr_rotate(struct node *,struct node *,struct node *);
struct node *rr_rotate(struct node *,struct node *);
struct node *rl_rotate(struct node *,struct node *,struct node *);
void inorder_traversal(struct node *);
struct node *minimum(struct node *);
struct node *maximum(struct node *);
struct node *predecessor(struct node *,int);
struct node *successor(struct node *,int);
void inorder_traversal(struct node *);
int height(struct node *);
int main()
{
	int option,value,ht;
	do
	{
		printf("========================================================");
		printf("\npress 1 to insert the value in to the tree\n");
		printf("\npress 2 to inorder traversal of the tree\n");
		printf("\npress 3 to find the minimum element in the tree\n");
		printf("\npress 4 to find the maximum element in the tree\n");
		printf("\npress 5 to find the predecessor of the particular value\n");
		printf("\npress 6 to find the successor of the particular value\n");
		printf("=============================================================");
		printf("\nEnter the option \n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the value to be inserted in the list\n");
				scanf("%d",&value);
				tree=insert(tree,value);
				printf("\n the height of the tree is\n");
				ht=height(tree);
				printf("%d",ht);
				printf("\n");
				break;
			case 2:
				inorder_traversal(tree);
				break;
			case 3:
				printf("\n");
				smallest=minimum(tree);
				printf("The smallest element in the tree is\n");
				printf("%d",smallest->data);
				printf("\n");
				break;
			case 4:
				biggest=maximum(tree);
				printf("The biggest element in the tree is\n");
				printf("%d",biggest->data);
				printf("\n");
				break;
			case 5:
				printf("\nEnter the value for which you need to find the predecessor\n");
				scanf("%d",&value);
				pred=predecessor(tree,value);
				printf("\nThe immediate predecessor to the above entered value");
				printf("%d",pred->data);
				printf("\n");
				break;
			case 6:
				printf("\nEnter the value for which you need to find the successor\n");
				scanf("%d",&value);
				succ=successor(tree,value);
				printf("\nThe immediate successor to the above entered value");
				printf("%d",succ->data);
				printf("\n");
			    break;
				
		}
	}
	while(option!=8);
}
struct node *insert(struct node *tree,int value)
{
{
	struct node *ptr,*nodeptr,*parentptr,*null_ptr,*new_node;
	char b,r;
	null_ptr=NULL;
	nodeptr=NULL;
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=value;
	new_node->c='r';
	new_node->left=null_ptr;
	new_node->right=null_ptr;
	if(tree==NULL)
	{
		new_node->c='b';
		tree=new_node;
		return(tree);

		
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=null_ptr)
		{
			parentptr=nodeptr;
			if(value>nodeptr->data)
			{
				nodeptr=nodeptr->right;
			}
			else
			{
				nodeptr=nodeptr->left;
			}
		}
		if(value>parentptr->data)
		{
			parentptr->right=new_node;
			
			
		}
		else
		{
			parentptr->left=new_node;
			
			
		}
		tree=fix_rb(tree,new_node);
		
	}

	return (tree);
}
}

struct node *fix_rb(struct node *tree,struct node *new_node)
{
    struct node *grandparentptr,*parentptr,*child,*uncle,*nodeptr,*null_ptr;
	grandparentptr=NULL;
	parentptr=NULL;
	null_ptr=NULL;
	child=new_node;
	if(child==tree)///if inserted node is the root node
	{
		child->c='b';
		return(tree);
		
	}
	else///find the parent and grandparentptr
	{
		nodeptr=tree;
		while(nodeptr->data!=child->data)
		{
			parentptr=nodeptr;
			if(child->data>nodeptr->data)
			{
				nodeptr=nodeptr->right;
			}
			else
			{
				nodeptr=nodeptr->left;
			}
		
		}
		
		printf("\nTh parent is\n");
		printf("%d",parentptr->data);
		printf("\n");
		printf("%c",parentptr->c);
		if(parentptr==tree)///parent==tree then there is no grandfather
		{
			if(parentptr->c=='b')
			{

			}	
			else
			{
				parentptr->c=='b';
			}
			return(tree);		
		}
		else
		{
			nodeptr=tree;
			while(nodeptr->data!=parentptr->data)
			{
				grandparentptr=nodeptr;
				if(parentptr->data>nodeptr->data)
				{
				
					nodeptr=nodeptr->right;
				}
				else
				{
				
					nodeptr=nodeptr->left;
				}
			}
			printf("\nThe grand father is\n");
			printf("%d",grandparentptr->data);
			printf("\n");
			printf("%c",grandparentptr->c);

			if((grandparentptr->right==null_ptr&&grandparentptr->left->c=='r')||(grandparentptr->right->c=='b'&&grandparentptr->left->c=='r')||(grandparentptr->left==null_ptr&&grandparentptr->right->c=='r')||(grandparentptr->left->c=='b'&&grandparentptr->right->c=='r'))
			{
				if(grandparentptr->left==parentptr&&parentptr->left==child)//ll
				{
					
					tree=ll_rotate(grandparentptr,parentptr);
					return(tree);
				}
				else if(grandparentptr->left==parentptr&&parentptr->right==child)//lr
				{
				
					tree=lr_rotate(grandparentptr,parentptr,child);
					return(tree);
				}
				else if(grandparentptr->right==parentptr&&parentptr->right==child)//rr
				{
				
					tree=rr_rotate(grandparentptr,parentptr);
					return(tree);
				}
				else//rl
				{
				
					tree=rl_rotate(grandparentptr,parentptr,child);
					return(tree);
				}
			}
		    else if (grandparentptr->left->c=='r'&&grandparentptr->right->c=='r')
			{
			
				grandparentptr->left->c='b';
				grandparentptr->right->c='b';
				grandparentptr->c='r';
				tree=fix_rb(tree,grandparentptr);
			}
		}
		
	}
	return(tree);
}

struct node *ll_rotate(struct node *grandparentptr,struct node *parentptr)///left-left rotate
{
	struct node *inptr,*greatgrandparentptr,*nodeptr;
	char b,r;
	inptr=NULL;
	nodeptr=NULL;
	greatgrandparentptr=NULL;
	if(grandparentptr==tree)
	{

    	inptr=parentptr->right;
    	parentptr->right=grandparentptr;
    	grandparentptr->left=inptr;
    	grandparentptr->c='r';
    	parentptr->c='b';
    	tree=parentptr;
    	printf("These are the values after sorting the data\n");
    	printf("\nThe colour of the grand father is\n");
    	printf("%c",grandparentptr->c);
    	printf("\nThe colour of the parent is\n");
    	printf("%c",parentptr->c);
    	printf("\n");
    	printf("%d",tree->data);
    	return(tree);
	}
	else
	{
		
		nodeptr=tree;
		while(nodeptr->data!=grandparentptr->data)
		{
			greatgrandparentptr=nodeptr;
			if(grandparentptr->data>nodeptr->data)
			{
			
				nodeptr=nodeptr->right;
			}
			else
			{
			
				nodeptr=nodeptr->left;
			}
    	}
		printf("\n the great grandfather is\n");
		printf("%d",greatgrandparentptr->data);
		inptr=parentptr->right;
    	parentptr->right=grandparentptr;
    	greatgrandparentptr->left=parentptr;
    	grandparentptr->left=inptr;
    	grandparentptr->c='r';
    	parentptr->c='b';    
    	printf("These are the values after sorting the data\n");
    	printf("\nThe colour of the grand father is\n");
    	printf("%c",grandparentptr->c);
    	printf("\nThe colour of the parent is\n");
    	printf("%c",parentptr->c);
    	return(tree);
	}

}
struct node *lr_rotate(struct node *grandparentptr,struct node *parentptr,struct node *child)//left-right rotate
{
	struct node *inptr;
	inptr=NULL;
	inptr=child->left;
	grandparentptr->left=child;
	child->left=parentptr;
	parentptr->right=inptr;
	tree=ll_rotate(grandparentptr,child);
	return(tree);
}
struct node *rr_rotate(struct node *grandparentptr,struct node *parentptr)//right-right rotate
{
	struct node *inptr,*greatgrandparentptr,*nodeptr;
	inptr=NULL;
	greatgrandparentptr==NULL;
	if(grandparentptr==tree)
	{
    	inptr=parentptr->left;
    	parentptr->left=grandparentptr;
    	grandparentptr->right=inptr;
    	grandparentptr->c='r';
    	parentptr->c='b';
    	tree=parentptr;
    	printf("%d",tree->data);
    	return(tree);
	}
	else
	{
		nodeptr=tree;
		while(nodeptr->data!=grandparentptr->data)
		{
			greatgrandparentptr=nodeptr;
			if(grandparentptr->data>nodeptr->data)
			{
				nodeptr=nodeptr->right;
			}
			else
			{
				nodeptr=nodeptr->left;
			}
			printf("\n the great grandfather is\n");
			printf("%d",greatgrandparentptr->data);
			
        	inptr=parentptr->left;
        	parentptr->left=grandparentptr;
        	greatgrandparentptr->right=parentptr;
        	grandparentptr->right=inptr;
        	grandparentptr->c='r';
        	parentptr->c='b';
        	return(tree);
		}
	}

}
struct node *rl_rotate(struct node *grandparentptr,struct node *parentptr,struct node *child)//right-left
{
	struct node *inptr;
	inptr=NULL;
	inptr=child->right;
	grandparentptr->right=child;
	child->right=parentptr;
	parentptr->left=inptr;
	tree=rr_rotate(grandparentptr,child);
	return(tree);
}
void inorder_traversal(struct node *tree)
{
	if(tree!=NULL)
	{

		inorder_traversal(tree->left);
		printf("%d",tree->data);
		printf("\n");
		printf("%c",tree->c);
		printf("\n");
		inorder_traversal(tree->right);
	}
}
struct node *minimum(struct node *tree)
{
	struct node *parentptr,*nodeptr;
	if(tree==NULL)
	{
		printf("There are no elements to return\n");
		return (tree);
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			nodeptr=nodeptr->left;
		}
		return (parentptr);
	}
	
}
struct node *maximum(struct node *tree)
{
	struct node *nodeptr,*parentptr;
	if(tree==NULL)
	{
		printf("There are no elements to return\n");
		return (tree);
	}
	else
	{
		parentptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parentptr=nodeptr;
			nodeptr=nodeptr->right;
		}
		return (parentptr);
	}
}
struct node *predecessor(struct node *tree,int value)
{
	struct node *nodeptr,*parentptr;
	nodeptr=tree;
	while(nodeptr->data!=value)
	{
		parentptr=nodeptr;
		if(nodeptr->data<value)
		{
			nodeptr=nodeptr->right;
		}
		else
		{
			nodeptr=nodeptr->left;
		}		
	}
	if(nodeptr->left==NULL)
	{
		return(parentptr);
	}
	else
	{
		nodeptr=nodeptr->left;
		while(nodeptr->right!=NULL)
		{
			nodeptr=nodeptr->right;
		}
		return(nodeptr);
	}
}
struct node *successor(struct node *tree,int value)
{
	struct node *nodeptr,*nptr;
	nodeptr=tree;
	while(nodeptr->data!=value)
	{
		if(nodeptr->data<value)
		{
			nodeptr=nodeptr->right;
		}
		else
		{
			nodeptr=nodeptr->left;
			
		}
	}
	nptr=nodeptr->right;
	if(nptr==NULL)
	{
		printf("\nThere is no successor and it is the leaf node\n");
		return(NULL);
	}
	else
	{
		if(nptr->left==NULL)
		{
			return(nptr);
		}
		else
		{
			while(nptr->left!=NULL)
			{
				nptr=nptr->left;
			}
			return(nptr);
		}
	}
}
int height(struct node *tree)
{
	int left_ht,right_ht;
	if(tree==NULL)
        return 0;
    else
    {
    	left_ht=height(tree->left);
    	right_ht=height(tree->right);
        if(left_ht > right_ht)
            return (left_ht + 1);
        else
            return (right_ht + 1);
    }
}

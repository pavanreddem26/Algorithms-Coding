//TWO SUM(When the array is sorted)
TIME COMPLEXITY= O(N)
SPACE COMPLEXITY=O(CONSTANT)

#include<stdio.h>///Fin
#include<conio.h>
int main()
{
	int n,a[n],i,j,k,target,sum,flag;
	printf("\n Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("\n Enter the target value that you want to find\n");
	scanf("%d",&target);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the values in the array\n");
		scanf("%d",&a[i]);
	}
	i=0;
	j=n-1;
	flag=0;
	for(k=0;k<n;k++)
	{
		sum=a[i]+a[j];
		if(j-i>0)
		{
		        if(sum==target)
	        	{
	     	        	flag=1;
	     	        	printf("\n The index values where the numbers exsists in the array are\n");
    		        	printf("\n Index 1 w.r.t to array\n");///Remember that array  
    		        	printf("%d",i);
    		        	printf("\n Index 2\n");
    		        	printf("%d",j);
    		        	break;
    	        	}
         		else if(sum<target)
         		{
    	         		i=i+1;
	         	}
    	        	else
    	         	{
    	         		j=j-1;
     	        	}
			
		}
		else
		{
			break;
		}

	}
	if(flag==0)
	{
		printf("\n There are no two elements in the array that sum up to the given target\n");
	}
}

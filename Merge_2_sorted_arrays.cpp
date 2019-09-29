#include<stdio.h>
#include<conio.h>
int main()
{
	int n,a[n],b[n],i,j,k;
	i=0;
	j=n/2;
	printf("\n Enter the number of elements in the array\n");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		printf("\n Enter the number of elements in the array\n");
		scanf("%d",&a[k]);
	}
	for(k=0;k<n;k++)
	{
		if(i!=n/2&&j==n)
		{
			b[k]=a[i];
			i++;
			
		}
		else if(i==n/2&&j!=n)
		{
			b[k]=a[j];
			j++;
			
		}
		else
		{
			if(a[i]>=a[j])
			{
				b[k]=a[j];
				j++;
			}
			else
			{
				b[k]=a[i];
				i++;
			}
			
		}
		
	}
	printf("\n The elements after sorting are\n");
	for(k=0;k<n;k++)
	{
		printf("%d",b[k]);
		printf("\n");
	}
}

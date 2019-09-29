#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j,k,a[n],s;
	printf("\n Enter the number of elements in the array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the elements of the array\n");
		scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(a[j-1]<=a[j])
			{
				//If they are correct order then do nothing
			}
			else
			{
				//If they are in reverse order just swap them
				s=a[j-1];
				a[j-1]=a[j];
				a[j]=s;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("%d",a[i]);
	}
}

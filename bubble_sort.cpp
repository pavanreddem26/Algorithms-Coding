//Time complexity----n^2(linear)
//space complexity---constant memory usage
#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,n,a[n],flag;
	flag=0;
	printf("\n Enter the number of elements in teh array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the elements in the array\n");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
				flag=1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("%d",a[i]);		
	}
}

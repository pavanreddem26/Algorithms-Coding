//Merge 3 sorted array into a single array
// Time complexity---n(linear)
//Space Complexity--n

#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,l,n,a[n],b[n],m;
	l=0;
	j=n/3;
	k=2*n/3;
	printf("\n Enter the number of values in the array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the values to be inseretd in the array\n");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if (l!=n/3&&j==2*n/3&&k==n)
		{
			b[i]=a[l];
			l++;
			
		}
		else if(l==n/3&&j!=2*n/3&&k==n)
		{
			b[i]=a[j];
			j++;
		}
		else if(l==n/3&&j==2*n/3&&k!=n)
		{
			b[i]=a[k];
			k++;
		}
		else if(l!=n/3&&j!=2*n/3&&k==n)
		{
			if(a[l]>=a[j])
			{
				b[i]=a[j];
				j++;
			}
			else
			{
				b[i]=a[l];
				l++;
			}
			
		}
		else if(l==n/3&&j!=2*n/3&&k!=n)
		{
			if(a[j]>=a[k])
			{
				b[i]=a[k];
				k++;
			}
			else
			{
				b[i]=a[j];
				j++;
			}
		}
		else if(l!=n/3&&j==2*n/3&&k!=n)
		{
			if(a[l]>=a[k])
			{
				b[i]=a[k];
				k++;
			}
			else
			{
				b[i]=a[l];
				l++;
			}
			
		}
		else
		{
			if(a[l]>=a[j])
			{
				if(a[j]>=a[k])
				{
					b[i]=a[k];
					k++;
				}
				else
				{
					b[i]=a[j];
					j++;
				}
				
			}
			else
			{
				if(a[l]>=a[k])
				{
					b[i]=a[k];
					k++;
				}
				else
				{
					b[i]=a[l];
					l++;
				}
				
			}
			
		}
	}
	printf("\n The elements in the array are\n");
	for(i=0;i<n;i++)
	{
		printf("%d",b[i]);
		printf("\n");
	}
}

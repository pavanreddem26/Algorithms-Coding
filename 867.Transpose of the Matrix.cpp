#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,a[i][j],b[i][j],m,n,c;
	printf("\n Enter the values of i\n");
	scanf("%d",&i);
	printf("\n Enter the values of j\n");
	scanf("%d",&j);
	for(m=0;m<i;m++)///Taking the valus as input
	{
		for(n=0;n<j;n++)
		{
			printf("\n Enter the values in the matrix\n");
			scanf("%d",&a[m][n]);
		}
	}
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			printf("\n");
			printf("%d",a[m][n]);
		}
	}
	for(m=0;m<i;m++)//Transpose of the matrix
	{
		for(n=0;n<j;n++)
		{
			b[n][m]=a[m][n];
		}
	}
	printf("\n");
	printf("\n The transpose of the matrix is\n");
	for(m=0;m<i;m++)
	{
		for(n=0;n<j;n++)
		{
			printf("\n");
			printf("%d",b[m][n]);
		}
	}
}

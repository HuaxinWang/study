#include<stdio.h>

int main()
{
	int i,j,k;
	int ch = 'A';
	for(i=1;i<=4;i++)
	{	
		for(j=1;j<=i;j++)
		{
			printf("%c",64+j);
		}
		for(k=i;k>0;k--)
		{
		printf("%d",k);
		}
		printf("\n");
	}



	return 0;
}

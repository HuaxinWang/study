#include<stdio.h>

int main()
{	
	int i = 1;
	int j = 1;
	int num = 0;
	printf("请输入要打印的菱形的行数:");
	scanf("%d",&num);
	getchar();
	for(i = 1;i <= num/2+1;i++)
	{
		for(j=num/2;j >= i;j--)
		{
			printf(" ");
		}
		for(j = 1;j <= 2*i - 1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i = num/2;i >= 1;i--)
	{
		for(j = i;j <= num/2 ;j++)
		{
		printf(" ");
		}
		for(j = 1;j <=2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}


	return 0;
}

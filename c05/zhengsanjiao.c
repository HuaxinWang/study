#include<stdio.h>

int main()
{	
	int i = 1;
	int j = 1;
	int num = 0;
	printf("请输入要打印的正三角形行数:");
	scanf("%d",&num);
	for(i = 1;i <= num;i++)
	{
		for(j = num - 1;j >= i;j--)
		{
			printf(" ");
		}
		for(j = 1;j <= 2*i-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}



	return 0;
}

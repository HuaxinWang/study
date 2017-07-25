#include<stdio.h>

int main()
{
	int num,num1;
	printf("请输入一个数字:");
	scanf("%d",&num);
	getchar();
	
	while(num != 0)
	{
		num1 = num % 10;
		num = num /10;
		printf("%d",num1);
	
	
	}

	return 0;
}

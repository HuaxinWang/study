#include<stdio.h>

int main()
{
	int num = 0;
	printf("请输入一个整数:");
	scanf("%d",&num);
	getchar();
	//判断条件
	if(num % 3 == 0||num % 5 ==0)
	{
		printf("这个数能被3或者5整除\n");
	}
	else if(num % 3 == 0)
	{
		printf("这个数能被3整除\n");
	}
	else if(num % 5 == 0)
	{
		printf("这个数能被5整除\n");
	}
	else
	{
		printf("这个数不能被3或者5整除\n");
	}



	return 0;
}

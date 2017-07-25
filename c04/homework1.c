#include<stdio.h>

int main()
{
	printf("任意输入10个数(用空格隔开):");
	int i = 0;
	int num = 0;
	int sum1 = 0;
	int sum2 = 0;
	for(i = 0;i < 10;i ++)
	{
		scanf("%d",&num);
		getchar();
		if(num >= 0)
		{
			sum1 = sum1 + num;
		}
		else
		{
			sum2 = sum2 + num;
		}
	}
	printf("所有正数之和为:%d\n所有负数之和为%d\n",sum1,sum2);
	return 0;
}

#include<stdio.h>

int main()
{	
	int year = 2000;
	printf("请输入一个年份:");
	scanf("%d",&year);
	getchar();
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		printf("%d年是闰年\n",year);
	}
	else
	{
		printf("%d年是平年\n",year);
	}




	return 0;
}

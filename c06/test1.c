#include<stdio.h>

int main()
{
	int num[5];
	int i = 0;
	for(i = 0;i < 5;i++)
	{
		scanf("%d",&num[i]);
		getchar();
	}
	int max = num[0];
	for(i = 1;i < 5;i++)
	{
		if(num[i] > max)
		{
			max = num[i];
		}
	}
	printf("最大值为%d\n",max);


	return 0;
}

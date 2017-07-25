#include<stdio.h>

int main()
{
	int arr[5] = {0};
	int *p = &arr[0];
	printf("请输入五个数:");
	int i = 0;
	for(i = 0;i < 5;i++)
	{
		scanf("%d",&arr[i]);
		while(getchar() != '\n');
	}
	float sum = 0;
	for(i = 0;i < 5;i++)
	{
		sum += *(p + i);
	}
	printf("平均值为:%.2f\n",sum/5);






	return 0;
}

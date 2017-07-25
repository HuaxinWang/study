#include<stdio.h>

int main()
{
	int arr[5] = {0};
	int i = 0;
	printf("请输入五个数字:");
	for(i = 0;i < 5;i++)
	{
		scanf("%d",&arr[i]);
		while(getchar() != '\n');
	}
	int max = arr[0],min = arr[0];
	int ma = 0,mi = 0;

	for(i = 0;i < 5;i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
			ma = i;
		}
		if(min > arr[i])
		{
			min = arr[i];
			mi = i;
		}
	}
	int tmp = arr[ma];
	arr[ma] = arr[mi];
	arr[mi] = tmp;

	for(i = 0;i < 5;i++)
	{
		printf("%d\n",arr[i]);
	}



	return 0;
}

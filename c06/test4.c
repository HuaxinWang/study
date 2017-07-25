#include<stdio.h>

int main()
{	
	int arr[5] = {0};
	int i = 0;
	printf("请输入五个数:");
	for(i = 0;i < 5;i++)
	{
		scanf("%d",&arr[i]);
		while(getchar() != '\n');
	}

	 
	int j = 0;
	int max = arr[0];
	int ma = 0;
	for(i = 0;i < 5;i++)
	{
		max = arr[i];
		ma =j;
		for(j = i;j < 5;j++)
		{
			if(arr[j] > max)
			{
				max =arr[j];
				ma = j;
			}
		}
		int temp = arr[ma];
		arr[ma] = arr[i];
		arr[i] = temp;
	}
	for(i = 0;i < 5;i++)
	{
		printf("%d\n",arr[i]);
	}

	return 0;
}

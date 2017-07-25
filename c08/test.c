#include<stdio.h>
#include<stdlib.h>

void scanfIntArray(int *arr,int size);
int main()
{
	int arr[5];
	printf("请输入五个数字:");
	scanfIntArray(arr,5);
	int i = 0;
	for(i = 0;i <= 5/2;i++)
	{
		if(arr[i] != arr[4 - i])
		{
			printf("不是回文\n");
			exit(1);
		}
	}
	printf("是回文\n");



	return 0;
}
void scanfIntArray(int *arr,int size)
{
	int i = 0;
	for(i = 0;i < size;i++)
	{
		scanf("%d",&arr[i]);
		getchar();
	}
}

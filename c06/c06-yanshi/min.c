#include <stdio.h>
 
int main()
{
	int arr[5] = {0};
	printf("请输入5个数字:");
	int i = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		scanf("%d",&arr[i]);
		while(getchar() != '\n');
	}
	int min = arr[0];

	for(i = 1 ; i < 5 ; i++)
	{
		if(min > arr[i])
		{
			min = arr[i];
		}
	}

	printf("%d\n",min);

	// 6 87 45 23 90
	// arr[0] = 90
	// 90 87 45 23 6
	//
	// int t = a;
	// a = b;
	// b = t;





	return 0;
}

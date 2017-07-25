#include<stdio.h>

int main()
{
	int num[5] = {21,45,65,78,34};
	int i = 0;
	int min = num[0];
	for(i = 1;i < 5;i++)
	{
		if(num[i] < min)
		{
			min = num[i];
		}
	}
	printf("最小值为:%d\n",min);


	return 0;
}

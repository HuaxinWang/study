#include <stdio.h>

int main()
{
	//int score1,score2,score3...score5;
	int score[5];
	//score[1/2/3/4];
	//score[0];
	//
	int i = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		scanf("%d",&score[i]);
		while(getchar() != '\n');
	}
	int sum = 0;
	for(i = 0 ; i < 5; i++)
	{
		sum += score[i];
	}
	//声明一个5个元素的数组，输入数据，找到数组中的最大值并输出

	printf("%d\n",sum/5);



	return 0;
}

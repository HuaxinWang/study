#include<stdio.h>

int main()
{
	//定义变量
	float score = 0;
	//提示输入成绩
	printf("please input your score:");
	//输入成绩
	scanf("%.2f",&score);
	getchar();
	//判断是否及格
	if(score >= 60)
	{
		printf("恭喜你及格了!\n");
	}
	else
	{
		printf("对不起你没有及格!\n");
	}


	return 0;
}

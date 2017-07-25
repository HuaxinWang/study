#include<stdio.h>

int main()
{	
	//定义并初始化变量
	float chinese = 0,math = 0,english = 0;
	float sum = 0,avg = 0;
	//输入成绩
	printf("please input your chinese grade:");
	scanf("%f",&chinese);
	printf("please input your math grade:");
	scanf("%f",&math);
	printf("please input your english grade:");
	scanf("%f",&english);
	//计算总分和平均分
	sum = chinese + math + english;
	avg = sum / 3;
	//输出总分和平均分
	printf("你的总分:%.2f\n你的平均分:%.2f\n",sum,avg);
	//控制printf输出的宽度
	return 0;
}


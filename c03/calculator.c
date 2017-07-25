#include<stdio.h>

int main()
{	
	//定义三个数值型变量以及一个字符型变量
	float num1,num2,result;
	char ch = '\0';
	printf("请输入你想要计算的算式:");
	scanf("%f%c%f",&num1,&ch,&num2);
	getchar();
	//判断算式的计算规则
	if(ch == '+')
	{
		result = num1 + num2;
		printf("结果为:%.f%C%f=%f\n",num1,ch,num2,result);
	}
	else if(ch == '-')
	{
		result = num1 - num2;
		printf("结果为:%.2f%C%.2f=%f\n",num1,ch,num2,result);
	}
	else if(ch == '*')
	{
		result = num1 * num2;
		printf("结果为:%.2f%C%.2f=%.2f\n",num1,ch,num2,result);
	}
	else if(ch == '/')
	{
		result = num1 / num2;
		printf("结果为:%.2f%C%.2f=%.2f\n",num1,ch,num2,result);
	}
	else
	{
		printf("你的输入有误!\n");
	}



	return 0;
}

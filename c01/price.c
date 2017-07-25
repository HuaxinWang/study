#include <stdio.h>

int main()
{
	//定义四个变量
	float price1,price2,price3,sum;
	price1 = 19.9;
	price2 = 15.5;
	price3 = 23.34;
	//假设总价使用变量sum表示，计算结果
	sum = price1 + price2 + price3;
	printf("总价为:%.2f\n",sum);
	return 0;
}

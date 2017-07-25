#include<stdio.h>

int main()
{
	int a = 3;
	int b = 5;
	int c = 0;
	//++ --
	//自增1 自减1
	//a++;
	//b--;
	//b--;
	//c = a + b;
	//a b c
	//4 3 7

	//a++;
	//++a;
	//a = 3 b = 5 c = 0
	c = b + a++;
	// 后++,先完成本次表达式操作，然后在自己给自己加一
	//c = b + a
	// a = a + 1
	// 前++,先给自己加一，然后完成本次操作
	//a = 4 b = 5 c = 8
	c = ++a + b;
	//a = 5 b = 5 c = 10
	c = (a++)+b;	
	// 5 + 5
	// 6
	// 5
	printf("a:%d\tb:%d\tc:%d\n",a,b,c);
	//a = 6
	//b = 5
	//c = 10
	




	return 0;
}

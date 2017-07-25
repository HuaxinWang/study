#include<stdio.h>
int main()
{
	int a = 3;
	int b = 5;
	int c = 0;
	//++ --
	//自增１　自减１
	//a++;
	//b--;
	//b--;
	//c = a + b;
	//a b c
	//4 3 7

	//a++;
	//++a;
	c = b + a++;
	//后++,先完成本次表达式操作，然后在自己给自己加一
	//c = b + a
	//a = a + 1
	//前++,先给自己加一，再完成本次表达式
	//c = 8
	//a = 4
	printf("a:%d\tb:%d\t%d\n",a,b,c);
	//稳定性
	//可读性
	//可维护性
	//性能


	return 0;
}

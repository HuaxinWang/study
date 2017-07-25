#include<stdio.h>

int main()
{
	int a = 3;
	int b = 4;

	a++;
	// a = 4
	a = a + 1;
	// a = 5
	a = a + 2;
	//a = 7
	a+=2;
	//a = 9
	a-=5;
	//a = 4
	a = a - 5;
	a += 10;
	// a = -1
	// > < >= <= == !=
	int c = a > b; //判断表达式
	//对	真	非0
	//错	假  0
	//t
	//f
	//char t f
	printf("c:%d\n",c);







}



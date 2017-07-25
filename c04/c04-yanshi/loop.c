#include <stdio.h>

int main()
{

	int year = 2000;
	//循环 for while do_while
	//
	// for(初始化;判断表达式;每次循环条件怎么变)
	//{
	//	要循环执行的代码；
	//}
	/*
	int i = 0;
	for(i = 0; i < 3 ; i++)
	{
		printf("请输入一个年份:");
		scanf("%d",&year);
		getchar();
		year%4 == 0 && year%100!=0 || year%400 == 0?printf("闰年\n"):printf("平年\n");
	}
	*/
	//练习：
	//　计算１　－－　１００所有数字的和
	/*
	int sum = 0;
	int i = 0;
	for(i = 1 ; i < 101 ; i++)
	{
		sum += i;
	}
	printf("结果为:%d\n",sum);
	*/
	//for while do_while
	//　i = 0 ; i < 3 ; i++
	// 
	// 明确知道循环多少次
	//　不知道循环多少次
	//　一直循环
	// 

	//bool
	//c99
	/*
	int i = 0;
	for(;;){
		printf("%d\n",i);
	}
	*/
	/*
	   for(初始化条件;判断条件;增量条件)
		{
			如果判读条件成立，则执行这里的代码
		}
		三个条件可以任意省略，但是两个;;不能省
		for：适用循环次数确定的场景
	*/
	//循环次数不确定的场景

//	while(判断条件)
//	{
//		判断条件为真，则执行代码
//	}

	int i = 1;
	int sum = 0;
	while(1)
	{
		sum += i;
	}
	printf("%d\n",sum);














	return 0;
}






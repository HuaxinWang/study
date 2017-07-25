/*************************************************************************
    > File Name: switch.c
    > Author: kaka2436
    > Mail: kaka2436@163.com 
    > Created Time: Thu 13 Jul 2017 10:29:34 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main()
{
	//a e i o u
//	char ch = '\0';
//	printf("请输入一个小写字母:");
//	scanf("%c",&ch);
	//判断单个变量的取值
/*
	switch(要判断取值的变量){
		case 可能的值１:
			如果取值是值１的话，执行这里的代码
			break;
		case 可能的值２：
			如果取值是值2的话，执行这里的代码
			break;
			.
			.
			.
			.
		default:
			如果取值不是上面任意一种，执行这里的代码
	
}



*/



#if 0
	switch(ch){
		case 'a':
			printf("是元音字母\n");
			break;
		case 'e':
			printf("是元音字母\n");
			break;
		case 'i':
			printf("是元音字母\n");
			break;
		case 'o':
			printf("是元音字母\n");
			break;
		case 'u':
			printf("是元音字母\n");
			break;
		default:
			printf("不是元音字母\n");
			break;
	}

#endif


	int num1 , num2;
	char expr;
	printf("请输入一个表达式(3+4):");
	scanf("%d%c%d",&num1,&expr,&num2);
	getchar();
	int result = 0;
	switch(expr){
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if(num2 == 0){
				printf("除数不能为0\n");
				exit(-1);
			}else{
				result = num1 / num2;
			}
			break;
		default:
			printf("程序不接受这种表达式\n");
			exit(-1);
	}

	printf("结果为:%d\n",result);







}










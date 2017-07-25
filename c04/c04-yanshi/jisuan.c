/*************************************************************************
    > File Name: jisuan.c
    > Author: kaka2436
    > Mail: kaka2436@163.com 
    > Created Time: Thu 13 Jul 2017 09:22:34 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>


int main()
{
	//标记位
	int flag = 1;
	int num1 = 0 , num2 = 9;
	char expr = '\0';
	printf("请输入一个表达式(a+b):");
	scanf("%d%c%d",&num1,&expr,&num2);
	int result = 0;

	if('+' == expr){
		result = num1 + num2;
	}else if('-' == expr){
		result = num1 - num2;
	}else if('*' == expr){
		result = num1 * num2;
	}else if('/' == expr){
		if(0 != num2){
			result = num1 / num2;
		}else{
			printf("表达式不合法\n");
			flag = 0;
			//return 0;
			//exit(-1);
		}
	}else{
		printf("表达式不合法\n");
		flag = 0;
		//return 0;
		//exit(-1);
	}

	if(flag){
		printf("结果为:%d\n",result);
	}

	return 0;
}





//函数
//处理事情的标准流程的代码，单独划分出来
//











/*************************************************************************
    > File Name: if01.c
    > Author: kaka2436
    > Mail: kaka2436@163.com 
    > Created Time: Wed 12 Jul 2017 04:33:24 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
	/*
	float score = 60;
	printf("请输入一个成绩:");
	scanf("%f",&score);
	if(score >= 60)
	{
		printf("及格\n");
	}
	*/
	// 元音字母
	// a e i o u
	// 要求用户输入一个字母
	// 判断是不是元音
	printf("请输入一个字母:");
	char ch = '\0';
	scanf("%c",&ch);
	if('a' == ch)
	{
		printf("元音\n");
	}else if('e' == ch){
		printf("元音\n");
	}else if('i' == ch){
		printf("元音\n");
	}else if('o' == ch){
		printf("元音\n");
	}else if('u' == ch){
		printf("元音\n");
	}else{
		printf("不是元音\n");
	}

//	如果 能被3整除则输出能被3整除
//	否则 如果能被5整除则输出能被5整除
//	否则 输出不能被整除













	return 0;
}











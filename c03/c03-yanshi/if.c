/*************************************************************************
    > File Name: if.c
    > Author: kaka2436
    > Mail: kaka2436@163.com 
    > Created Time: Wed 12 Jul 2017 04:18:28 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
	char ch = '\0';
	scanf("%c",&ch);
	getchar();

	if('a' == ch)  
	{
		//条件为真时执行这一段
		printf("优等生\n");
	}else{
		//条件为假时执行这一段
		printf("中等生\n");
	}
	//if 判断条件
	//{
	//
	//	}else{
	//
	// }




	return 0;
}










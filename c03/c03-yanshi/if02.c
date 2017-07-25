/*************************************************************************
    > File Name: if02.c
    > Author: kaka2436
    > Mail: kaka2436@163.com 
    > Created Time: Wed 12 Jul 2017 05:00:56 PM CST
 ************************************************************************/

#include<stdio.h>

int main()
{
	int num = 0;
	printf("请输入一个数字:");
	scanf("%d",&num);
	getchar();

	if(num%3 == 0){
		printf("可以被3整除\n");
	}else if(num%5 == 0){
		printf("可以被5整除\n");
	}else{
		printf("不能被整除\n");
	}


}
















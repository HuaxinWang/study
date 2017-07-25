/*************************************************************************
    > File Name: rand.c
    > Author: kaka2436
    > Mail: kaka2436@163.com 
    > Created Time: Thu 13 Jul 2017 11:20:46 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//将时间设置为随机数种子
	//整个程序中只要有一次就好
	srand((unsigned)time(NULL));
	
	int index = 0;
	printf("1-->黄山菜饭\n");
	printf("2-->沙县\n");
	printf("3-->盖浇饭\n");
	printf("4-->东北水饺\n");
	printf("5-->不吃饭\n");

	index = rand()%5  + 1;

	//编写一个程序，猜拳游戏
	// １－－剪刀　２－－石头　３－－布
	// 1 剪刀
	// ２ 石头


	//
	//
	//  计算规则
	//	伪随机数
	//  3 + 4 / 5 % 6 * 7 * x
	//

	switch(index){
		case 1:
			printf("1-->黄山菜饭\n");
			break;
		case 2:
			printf("2-->沙县\n");
			break;
		case 3:
			printf("3-->盖浇饭\n");
			break;
		case 4:
			printf("4-->东北水饺\n");
			break;
		case 5:
			printf("5-->不吃饭\n");
			break;
	}




}











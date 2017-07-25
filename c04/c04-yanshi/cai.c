#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//1 2 3
	char ch = '\0';
	printf("1-->剪刀\n");
	printf("2-->石头\n");
	printf("3-->布\n");
	printf("请输入你的选择:");
	scanf("%c",&ch);
	getchar();
	int com = 0;
	srand((unsigned)time(NULL));
	com = rand()%3 + 1;
	//if switch
	//分支语句
	//互为替代
	//逻辑
	if('1' == ch)
	{
		if(1 == com){
			printf("平局\n");
		}else if(2 == com){
			printf("电脑胜利\n");
		}else if(3 == com){
			printf("玩家胜利\n");
		}
	}else if('2' == ch){
		if(1 == com){
			printf("玩家胜利\n");
		}else if(2 == com){
			printf("平局\n");
		}else if(3 == com){
			printf("电脑胜利\n");
		}
	}else if('3' == ch){
		if(1 == com){
			printf("电脑胜利\n");
		}else if(2 == com){
			printf("玩家胜利\n");
		}else if(3 == com){
			printf("平局\n");
		}
	}else{
		printf("只能出剪刀、石头、布\n");
	}

	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NAME_LEN 200
#define LIVE 1
#define DEATH 0 
int goHome()
{
	int index = rand()%4;
	return index;  //返回值为0，表示撤退失败
}

int judge(int * arr,int flag)
{
	int i = 0;
	int sum = 0;
	for(i = 0 ; i < 15 ; i++)
	{
		if(arr[i] == 1)
			sum++;
	}
	if(flag == 0)
		printf("用户牺牲了:%d个士兵\n",sum);
	else
		printf("电脑牺牲了:%d个士兵\n",sum);
	if(sum == 15 && flag == 0)
	{
		printf("电脑取得了胜利\n");
		return DEATH;
	}else if(sum == 15 && flag == 1){
		printf("恭喜您，取得了战役的胜利\n");
		return DEATH;
	}
	return LIVE;
}


void attack(int * arr)
{
	int i = 0;
	for(i = 0 ; i < 3 ; i++)
	{
		int index = rand()%15;
		arr[index] = 1;
	}
}

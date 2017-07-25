#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"loginRegiste.h"
#include"gameRules.h"
#include"function.h"
#define NAME_LEN 200
#define LIVE 1
#define DEATH 0 

void gameMenu()
{
	int user[15] = {0};
	int com[15] = {0};
	int flag = 1;
	while(flag)
	{
		system("clear");
		printf("1-->进攻\n"
				"2-->撤退\n"
				"请输入你的选择:");
		char ch = '\n';
		scanf("%c",&ch);
		while(getchar() != '\n');
		switch(ch)
		{
			case '1':
				attack(com);
				flag = judge(com,1);			
				if(flag)
				{
					attack(user);
					flag = judge(user,0);
				}
				break;
			case '2':
				if(!goHome()){
					printf("撤退失败~电脑追击\n");
					attack(user);
					flag = judge(user,0);
				}else{
					printf("撤退成功\n");
					flag = 0;
				}
				break;
			default:
				printf("没有这个操作\n");
		}

		printf("按回车继续");
		while(getchar() != '\n');
	}
}

void menu()
{
	char name[NAME_LEN] = {'\0'};
	char passwd[NAME_LEN] = {'\0'};
	while(1)
	{
		system("clear");
		printf("1-->注册\n"
				"2-->登录\n"
				"q-->退出\n"
				"请输入你的选择:");
		char ch = '\0';
		scanf("%c",&ch);
		while(getchar() != '\n');
		switch(ch)
		{
			case '1':
				registe(name,passwd);
				break;
			case '2':
				login(name,passwd);
				break;
			case 'q':
				exit(1);
			default:
				printf("输入错误，请重新输入\n");
	
		}
	}
}

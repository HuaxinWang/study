#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "welcome_menu.h"
#include "login.h"


//欢迎菜单及功能
void welcome_menu()
{
    while(1)
    {
	system("clear");
	char choice = '\0';
        printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("\t\t\t\t|  欢迎进入s q学生管理系统  |\n");
    	printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    	printf("\t\t\t\t|    1-->管理员登录         |\n");
    	printf("\t\t\t\t|    2-->教师登录           |\n");
    	printf("\t\t\t\t|    3-->学生登录           |\n");
    	printf("\t\t\t\t|    q-->退出系统           |\n");
    	printf("\t\t\t\t|                           |\n");
    	printf("\t\t\t\t|                           |\n");
    	printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n");
        printf("\t\t\t\t请输入你的选择:");
        scanf("%c",&choice);
        while(getchar() != '\n');
        switch(choice)
        {
	    case '1':

		//管理员登录函数
		admin_login();
		break;	    
	    case '2':

		//教师登录函数
		teacher_login();
		break;
	    case '3':

		//学生登录函数
		student_login();
		break;
	    case 'q':
	    {
		system("clear");
		printf("\t\t\t\t感谢使用!!!\n");
		sleep(2);
		exit(1);
	    }
	    default:
	    {
		printf("\t\t\t\t输入错误，按回车键重新输入!!!\n");
		while(getchar() != '\n');
	    }
	}
    } 
}   

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "login.h"
#include "welcome_menu.h"
#include "fun.h"

//管理员登录函数
void admin_login()
{
    while(1)
    {
	char id[MAX_ID] = {'\0'};
	char passwd[MAX_PASSWD] = {'\0'};
	char *p = passwd;
	char admin_id[MAX_ID] = "admin";
	char admin_passwd[MAX_ID] = "admin";
	system("clear");
	printf("\t\t\t\t***************************\n");
	printf("\t\t\t\t*       管理员登录        *\n");
	printf("\t\t\t\t***************************\n");
	printf("\t\t\t\t*   账  号:               *\n");
	printf("\t\t\t\t*   密  码:               *\n");
	printf("\t\t\t\t*                         *\n");
	printf("\t\t\t\t***************************\n");
	system("tput cup 3 43");
	scanf("%s",id);
	while(getchar() != '\n');
	system("tput cup 4 43");
	p = getpass("");
	
	//验证码,验证成功返回1，失败返回0`
	if(verify() == 0)
	{
	    printf("\t\t\t\t验证码错误!按回车键重新登录!!!\n");
	    while(getchar() != '\n');

	    break;
	}
	if(strcmp(id,admin_id) == 0&&strcmp(p,admin_passwd) == 0)
	{
	    system("clear");
	    printf("\t\t\t\t恭喜您登陆成功!!!\n");
	    printf("\t\t\t\t即将跳转到管理员操作界面!!!\n");
	    sleep(1);
	    
	    //管理员菜单
	    admin_menu();
	}
	else
	{
	    printf("\t\t\t\t账号或密码错误，按回车键重新登录!!!\n");
	    while(getchar() != '\n');

	    break;
	}
    }
    return;
}

//生成随机验证码
int verify()
{
    int n,choice;
    char code[4] = {'\0'};
    char input[4] = {'\0'};
    srand((unsigned) time(NULL));        
    for(int i=0;i<4;i++)        
    {			            
	choice=rand()%2;
	if(choice==0)
	{
	    n=rand()%(9)+48;
	}
	else
	{
	    n=rand()%26+65;
	}
	code[i]=n;						        
    }
    code[4] = '\0';
    printf("\n\n\n\n");
    printf("\t\t\t\t\t%s\n",code);
    printf("\n");
    printf("\t\t\t\t请输入验证码(字母大写):");
    scanf("%s",input);
    while(getchar() != '\n');
    if(strcmp(input,code)!=0)
	return 0;    
    else
	return 1;
}


//管理员菜单
void admin_menu()
{
    char ch = '\0';
    char id[MAX_ID] = "\0";
    tea *head = readfile();
    tea *temp = head;
    while(temp->next != NULL)
    {
    	if(temp->next->tdata.flag == 1)
	{
	    system("clear");
	    printf("\t\t\t\t注意!!!有以下老师申请辞职，请马上处理!!!\n\n");
	    printf("\t\t\t\tid\t姓名\t密码\t科目\n");
	    printf("\t\t\t\t%s\t%s\t%s\t%s\n",temp->next->tdata.id,temp->next->tdata.name,temp->next->tdata.passwd,temp->next->tdata.major);
	    printf("\t\t\t\t辞职理由:%s\n",temp->next->tdata.message);
	    printf("\t\t\t\t是否同意辞职,y确认删除:");
	    scanf("%c",&ch);
	    while(getchar() != '\n');
	    if(ch == 'y')
	    {
		printf("\t\t\t\t请输入此老师的id确认删除:");
		scanf("%s",id);
		while(getchar() != '\n');
		if(strcmp(temp->next->tdata.id,id) == 0)
    		{
		    temp->next = temp->next->next;
		    writefile(head);
    		    printf("\t\t\t\t删除成功!!!按回车键继续\n");
    		    while(getchar() != '\n');
    		    break;
    		}
    		else
		{
		    printf("\t\t\t\t输入id错误，删除失败!!!按回车键继续\n");
		    while(getchar() != '\n');
		    break;
		}	
	    }
	    else
	    {
		printf("\t\t\t\t已取消操作!!!按回车键继续\n");
		while(getchar() != '\n');
	    }
	}
    	temp = temp->next;
    }	
    while(1)
    {
	system("clear");
	char choice = '\0';
	printf("\t\t\t\t*****************************\n");
	printf("\t\t\t\t*         管理员菜单        *\n");
	printf("\t\t\t\t*****************************\n");
	printf("\t\t\t\t*   1-->添加教师信息        *\n");
	printf("\t\t\t\t*   2-->删除教师信息        *\n");
	printf("\t\t\t\t*   3-->更新教师信息        *\n");
	printf("\t\t\t\t*   4-->查看教师信息        *\n");
	printf("\t\t\t\t*   q-->返回登录界面        *\n");
	printf("\t\t\t\t*****************************\n");
	printf("\n");
	printf("\t\t\t\t请输入你的选择:");
	scanf("%c",&choice);
	while(getchar() != '\n');
	switch(choice)
	{
	    case '1':

		//添加教师信息
		add_teacher();
		break;	    
	    case '2':

		//删除教师信息
		del_teacher();
		break;
	    case '3':

		//更新教师信息
		update_teacher();
		break;
	    case '4':

		//查看教师信息
		show_teacher();
		break;
	    case 'q':

		//返回登录界面
		welcome_menu();
		break;
	    default:
		printf("\t\t\t\t输入错误，按回车键重新输入!!!\n");
	}
	while(getchar() != '\n');
    } 
}

//读取教师文件信息
tea *readfile()
{
    FILE *fp=fopen("teacher.txt","r");
    tea *temp=(tea *)malloc(sizeof(tea));
    tea *head=(tea *)malloc(sizeof(tea));
    head->next=NULL;
    while(fread(temp,sizeof(tea),1,fp)>0)
    {
	temp->next=head->next;
	head->next=temp;
	temp=NULL;
	temp=(tea *)malloc(sizeof(tea));
    }
    free(temp);
    temp=NULL;
    fclose(fp);
    return head;		
}

//添加教师信息
void add_teacher()
{
    tea *head=readfile();
    tea *temp=(tea *)malloc(sizeof(tea));
    if(temp==NULL)
    {
	printf("fail\n");
	return ;
    }
    temp->next=NULL;
    printf("\t\t\t\t请输入教师id:");
    //scanf("%s",temp->tdata.id);
    //while(getchar() != '\n');
    mygets(temp->tdata.id,MAX_ID);

    //教师查重
    while(teacher_id_repeat(temp->tdata.id))
    {
    	return;
    }

    printf("\t\t\t\t请输入教师姓名:");
    scanf("%s",temp->tdata.name);
    while(getchar() != '\n');
    printf("\t\t\t\t请设置该教师密码:");
    scanf("%s",temp->tdata.passwd);
    while(getchar() != '\n');
    printf("\t\t\t\t请输入该教师任课科目:");
    scanf("%s",temp->tdata.major);
    while(getchar() != '\n');	
    if(head->next!=NULL)
    {
	temp->next=head->next;
	head->next=temp;
    }
    else
    {
	head->next=temp;
    }
    temp->tdata.flag = 0;
    writefile(head);
    printf("\t\t\t\t该教师信息录入成功!!!按回车键继续\n");
    return ;
}


//将结构体链表写进文件
void writefile(tea *head)
{
    if(NULL==head)
    {
	printf("\t\t\t\t没有信息需要存储\n");
	return ;
    }	
    FILE *fp;
    fp=fopen("teacher.txt","w");
    while(head->next!=NULL)
    {
	fwrite(head->next,sizeof(tea),1,fp);
	head=head->next;
    }
    fclose(fp);	
    return;	
}


//打印教师信息
void show_teacher()
{
    tea *head=readfile();
    if(head->next==NULL)
    {
	printf("\t\t\t\t没有找到任何信息,按回车键继续\n");
	return ;
    }
    printf("\n");
    printf("\t\t\t\tid\t姓名\t密码\t科目\n");
    while(head->next!=NULL)
    {
	printf("\t\t\t\t%s\t%s\t%s\t%s\n",head->next->tdata.id,head->next->tdata.name,head->next->tdata.passwd,head->next->tdata.major);
	head=head->next;
    }
    printf("\n");
    printf("\t\t\t\t按回车继续\n");
    return ;
}

//删除教师信息
void del_teacher()
{	
    char id[MAX_ID];
    tea *head=readfile();
    tea *temp = NULL;
    temp = head;
    tea *l = NULL;
    printf("\t\t\t\t输入想要删除的教师id:");
    scanf("%s",id);
    while(getchar() != '\n');

    //教师信息判空
    while(tea_nul(id))
    {
    	return;
    }

    while(strcmp(head->tdata.id,id) != 0)
    {
	l = head;
	head = head->next;
    }
    l->next = head->next;
    writefile(temp);
    printf("\t\t\t\t删除成功!!!按回车键继续\n");
    return;
}

//修改教师信息
void update_teacher()
{
    char id[MAX_ID];
    tea *head = readfile();
    tea *temp = NULL;
    temp = head;
    printf("\t\t\t\t请输入要修改的教师id:");
    scanf("%s",id);
    while(getchar() != '\n');

    //教师信息判空
    while(tea_nul(id))
    {
    	return;
    }

    while(strcmp(head->tdata.id,id) != 0)
    {
	head  = head->next;
    }
    printf("\t\t\t\t新的id设置为:");
    scanf("%s",head->tdata.id);
    while(getchar() != '\n');

    //教师信息查重
    while(teacher_id_repeat(head->tdata.id))
    {
    	return;
    }

    printf("\t\t\t\t新的名字设置为:");
    scanf("%s",head->tdata.name);
    while(getchar() != '\n');
    printf("\t\t\t\t新的密码设置为:");
    scanf("%s",head->tdata.passwd);
    while(getchar() != '\n');
    printf("\t\t\t\t新的任课科目设置为:");
    scanf("%s",head->tdata.major);
    while(getchar() != '\n');

    //教师申请辞职标记为置位0
    head->tdata.flag = 0;

    writefile(temp);
    printf("\t\t\t\t更新成功!!!按回车继续\n");
    return;
}

//教师登录函数
void teacher_login()
{
    tea *head=readfile();
    while(1)
    {
	char id[MAX_ID] = {'\0'};
	char passwd[MAX_PASSWD] = {'\0'};
	char *p = passwd;
	system("clear");
	printf("\t\t\t\t***************************\n");
	printf("\t\t\t\t*        教师登录         *\n");
	printf("\t\t\t\t***************************\n");
	printf("\t\t\t\t*   账  号:               *\n");
	printf("\t\t\t\t*   密  码:               *\n");
	printf("\t\t\t\t*                         *\n");
	printf("\t\t\t\t***************************\n");
	system("tput cup 3 43");
	scanf("%s",id);
	while(getchar() != '\n');
	system("tput cup 4 43");
	p = getpass("");
	
	//验证码,验证成功返回1，失败返回0`
	if(verify() == 0)
	{
	    system("clear");
	    printf("\t\t\t\t验证码错误!按回车键重新登录!!!\n");
	    while(getchar() != '\n');
	    break;
	}
	while(head->next != NULL)
	{	
	    if(strcmp(head->next->tdata.id,id)==0)
	    {
		if(strcmp(head->next->tdata.passwd,p)==0)
		{
		    system("clear");
	    	    printf("\t\t\t\t恭喜您登陆成功!!!\n");
	    	    printf("\t\t\t\t即将跳转到教师操作界面!!!\n");
	    	    sleep(1);

	    	    //教师菜单
	    	    teacher_menu(id);
		}
	    }
	    head = head->next;
	}
	printf("\t\t\t\t账号或密码错误，按回车键重新登录!!!\n");
	while(getchar() != '\n');
    }
}	

//教师菜单
void teacher_menu(char *id)
{
    while(1)
    {
	system("clear");
	char choice = '\0';
	printf("\t\t\t\t*****************************\n");
	printf("\t\t\t\t*         教师菜单          *\n");
	printf("\t\t\t\t*****************************\n");
        printf("\t\t\t\t*     1-->添加学生信息      *\n");
        printf("\t\t\t\t*     2-->删除学生信息      *\n");
        printf("\t\t\t\t*     3-->更新学生信息      *\n");
        printf("\t\t\t\t*     4-->查看学生信息      *\n");
        printf("\t\t\t\t*     5-->更改密码          *\n");
        printf("\t\t\t\t*     6-->查看学生排名      *\n");
        printf("\t\t\t\t*     7-->查看学生留言      *\n");
        printf("\t\t\t\t*     8-->申请辞职          *\n");
        printf("\t\t\t\t*     q-->返回登录界面      *\n");
	printf("\t\t\t\t*****************************\n");
	printf("\n");
        printf("\t\t\t\t请输入你的选择:");
        scanf("%c",&choice);
        while(getchar() != '\n');
        switch(choice)
        {
	    case '1':

		//添加学生信息
		add_student();
		break;	    
	    case '2':

		//删除学生信息
		del_student();
		break;
	    case '3':

		//更新学生信息
		update_student();
		break;
	    case '4':

		//查看学生信息
		show_student();
		break;
	    case '5':

		//更改密码
		change_tea_passwd(id);
		break;
	    case '6':

		//查看学生排名
		ranking(id);
		break;
	    case '7':

		//查看学生留言
		show_message();
		break;
	    case '8':

		//申请辞职
		resign(id);
		break;
	    case 'q':

		//返回主菜单
		welcome_menu();
		break;
	    default:
		printf("\t\t\t\t输入错误!!!\n");
	}
	printf("\t\t\t\t按回车键继续\n");
	while(getchar() != '\n');
    } 
}   

//读取学生文件信息
stu *readfile_stu()
{
	FILE *fp=fopen("student.txt","r");
	stu *temp=(stu *)malloc(sizeof(stu));
	stu *head=(stu *)malloc(sizeof(stu));
	head->next=NULL;
	while(fread(temp,sizeof(stu),1,fp)>0)
	{
		temp->next=head->next;
		head->next=temp;
		temp=NULL;
		temp=(stu *)malloc(sizeof(stu));
	}
	free(temp);
	temp=NULL;
	fclose(fp);
	return head;		
}

//将结构体链表写进学生文件
void writefile_stu(stu *head)
{
	if(NULL==head)
	{
		printf("\t\t\t\t没有信息需要存储\n");
		return ;
	}	
	FILE *fp;
	fp=fopen("student.txt","w");
	while(head->next!=NULL)
	{
	    fwrite(head->next,sizeof(stu),1,fp);
		head=head->next;
	}
	fclose(fp);	
	return ;	
}

//添加学生信息
void add_student()
{
    stu *head=readfile_stu();
    stu *temp=(stu *)malloc(sizeof(stu));
    if(temp==NULL)
    {
    	printf("fail\n");
    	return ;
    }
    temp->next=NULL;
    printf("\t\t\t\t请输入学生id:");
    scanf("%d",&temp->sdata.id);
    while(getchar() != '\n');

    //学生信息查重
    while(student_id_repeat(temp->sdata.id))
    {
	return;
    }

    printf("\t\t\t\t请输入学生姓名:");
    scanf("%s",temp->sdata.name);
    while(getchar() != '\n');

    printf("\t\t\t\t请设置该学生密码:");
    scanf("%s",temp->sdata.passwd);
    while(getchar() != '\n');

    printf("\t\t\t\t请输入该学生语文成绩:");
    scanf("%f",&temp->sdata.chinese);
    while(getchar() != '\n');

    printf("\t\t\t\t请输入该学生数学成绩:");
    scanf("%f",&temp->sdata.math);
    while(getchar() != '\n');

    //学生留言标记位
    temp->sdata.flag = 0;
	
    if(head->next!=NULL)
    {
	temp->next=head->next;
	head->next=temp;
    }
    else
    {
	head->next=temp;
    }
    writefile_stu(head);

    printf("\t\t\t\t该学生信息录入成功!!!\n");
    return;
}

//打印学生信息
void show_student()
{
    stu *head=readfile_stu();
    if(head->next==NULL)
    {
	printf("\t\t\t\t没有找到任何信息\n");
	return ;
    }
    printf("\n");
    printf("\t\t\t\tid\t姓名\t密码\t语文\t数学\n");
    while(head->next!=NULL)
    {
	printf("\t\t\t\t%d\t%s\t%s\t%.2f\t%.2f\n",head->next->sdata.id,head->next->sdata.name,head->next->sdata.passwd,head->next->sdata.chinese,head->next->sdata.math);
	head=head->next;
    }
    printf("\n");
    return ;
}

//删除学生信息
void del_student()
{	
    int id;
    stu *head=readfile_stu();
    stu *temp = NULL;
    temp = head;
    stu *l = NULL;
    printf("\t\t\t\t输入想要删除的学生id:");
    scanf("%d",&id);
    while(getchar() != '\n');

    //学生信息判空
    while(stu_nul(id))
    {
    	return;
    }

    while(head->sdata.id != id)
    {
	l = head;
	head = head->next;
    }
    l->next = head->next;
    writefile_stu(temp);
    printf("\t\t\t\t删除成功!!!\n");
    return;
}

//修改学生信息
void update_student()
{
	int id;
	stu *head = readfile_stu();
	stu *temp = NULL;
	temp = head;
	printf("\t\t\t\t请输入要修改的学生id:");
	scanf("%d",&id);
	while(getchar() != '\n');

	//学生信息判空
	while(stu_nul(id))
	{
	    return;
	}

	while(head->sdata.id != id)
	{
	    head  = head->next;
	}
	printf("\t\t\t\t新的id设置为:");
	scanf("%d",&head->sdata.id);
	while(getchar() != '\n');

	//学生信息查重
	while(student_id_repeat(head->sdata.id))
	{
	    return;
	}

	printf("\t\t\t\t新的名字设置为:");
	scanf("%s",head->sdata.name);
	while(getchar() != '\n');
	printf("\t\t\t\t新的密码设置为:");
	scanf("%s",head->sdata.passwd);
	while(getchar() != '\n');
	printf("\t\t\t\t新的语文成绩设置为:");
	scanf("%f",&head->sdata.chinese);
	while(getchar() != '\n');
	printf("\t\t\t\t新的数学成绩设置为:");
	scanf("%f",&head->sdata.math);
	while(getchar() != '\n');

	//学生留言标记为置位0;
	head->sdata.flag = 0;

	writefile_stu(temp);
	printf("\t\t\t\t更新成功!!!\n");
}

//学生登录函数
void student_login()
{
	
    stu *head=readfile_stu();
    while(1)
    {
	int id;
	char passwd[MAX_PASSWD] = {'\0'};
	char *p = passwd;
	system("clear");
	printf("\t\t\t\t***************************\n");
	printf("\t\t\t\t*        学生登录         *\n");
	printf("\t\t\t\t***************************\n");
	printf("\t\t\t\t*   账  号:               *\n");
	printf("\t\t\t\t*   密  码:               *\n");
	printf("\t\t\t\t*                         *\n");
	printf("\t\t\t\t***************************\n");
	system("tput cup 3 43");
	scanf("%d",&id);
	while(getchar() != '\n');
	system("tput cup 4 43");
	p = getpass("");
	
	//验证码,验证成功返回1，失败返回0`
	if(verify() == 0)
	{
	    printf("\t\t\t\t验证码错误!按回车键重新登录!!!\n");
	    while(getchar() != '\n');
	    break;
	}
	while(head->next != NULL)
	{	
	    if(head->next->sdata.id == id)
	    {
	    if(strcmp(head->next->sdata.passwd,p)==0)
		{
		    system("clear");
	    	    printf("\t\t\t\t恭喜您登陆成功!!!\n");
	    	    printf("\t\t\t\t即将跳转到学生操作界面!!!\n");
	    	    sleep(1);

	    	    //教师菜单
	    	    student_menu(id);
		}
	    }
	    head = head->next;
	}
	printf("\t\t\t\t账号或密码错误，按回车键重新登录\n");
	while(getchar() != '\n');
	return;
    }
}	


//学生菜单
void student_menu(int id)
{
    while(1)
    {
	system("clear");
	char choice = '\0';
	printf("\t\t\t\t*****************************\n");
	printf("\t\t\t\t*         学生菜单          *\n");
	printf("\t\t\t\t*****************************\n");
        printf("\t\t\t\t*     1-->查看自己信息      *\n");
        printf("\t\t\t\t*     2-->更改密码          *\n");
        printf("\t\t\t\t*     3-->给老师留言        *\n");
        printf("\t\t\t\t*     q-->返回登录界面      *\n");
	printf("\t\t\t\t*****************************\n");
	printf("\n");
        printf("\t\t\t\t请输入你的选择:");
        scanf("%c",&choice);
        while(getchar() != '\n');
        switch(choice)
        {
	    case '1':

		//查看信息(按总分排名)
		sort_by_score();
		break;	    
	    case '2':

		//更改密码
		change_stu_passwd(id);
		break;
	    case '3':

		//给老师留言
		leave_message(id);
		break;
	    case 'q':

		//返回主菜单
		welcome_menu();
		break;
	    default:
		printf("\t\t\t\t输入错误!!!\n");
	}
	printf("\t\t\t\t按回车继续\n");
	while(getchar() != '\n');
    } 
}


//学生更改自己的密码
void change_stu_passwd(int id)
{
    stu *head = readfile_stu();
    stu *temp = head;
    while(temp->next != NULL)
    {	
	if(temp->next->sdata.id = id)
	{
	    char passwds[MAX_PASSWD];
	    char passwd_new[MAX_PASSWD];
	    char passwd_new2[MAX_PASSWD];
	    printf("\t\t\t\t请输入原密码:\n");
	    scanf("%s",passwds);
	    while(getchar() != '\n');
	    if(strcmp(temp->next->sdata.passwd,passwds) == 0)
	    {
		printf("\t\t\t\t请输入新密码:");
		scanf("%s",passwd_new);
		while(getchar() != '\n');
		printf("\t\t\t\t确认新密码:");
		scanf("%s",passwd_new2);
		while(getchar() != '\n');
		if(strcmp(passwd_new,passwd_new2) == 0)
		{
		    strcpy(temp->next->sdata.passwd,passwd_new);
		    writefile_stu(head);
		    system("clear");
		    printf("\t\t\t\t密码更改成功，请使用新密码登录!!!\n");
		    sleep(1);
		    welcome_menu();
		}
	    }
	}
	temp = temp->next;	
    }
}


//老师更改自己的密码
void change_tea_passwd(char *id)
{
    tea *head = readfile();
    tea *temp = head;
    while(temp->next != NULL)
    {	
	if(strcmp(temp->next->tdata.id,id) == 0)
	{
	    char passwds[MAX_PASSWD];
	    char passwd_new[MAX_PASSWD];
	    char passwd_new2[MAX_PASSWD];
	    printf("\t\t\t\t请输入原密码:\n");
	    scanf("%s",passwds);
	    if(strcmp(temp->next->tdata.passwd,passwds) == 0)
	    {
		printf("\t\t\t\t请输入新密码:");
		scanf("%s",passwd_new);
		printf("\t\t\t\t确认新密码:");
		scanf("%s",passwd_new2);
		if(strcmp(passwd_new,passwd_new2) == 0)
		{
		    strcpy(temp->next->tdata.passwd,passwd_new);
		    writefile(head);
		    system("clear");
		    printf("\t\t\t\t密码更改成功，请使用新密码登录!!!\n");
		    sleep(1);
		    welcome_menu();
		}
	    }
	}
	temp = temp->next;	
    }
}

//给老师留言
void leave_message(int id)
{
    stu *head = readfile_stu();
    stu *temp = head;
    while(temp->next != NULL)
    {
	if(temp->next->sdata.id == id)
	{
	    char write_message[MAX_MESSAGE];
	    printf("\t\t\t\t输入留言(不超过五十字):");
	    scanf("%s",write_message);
	    while(getchar() != '\n');
	    strncpy(temp->next->sdata.message,write_message,sizeof(write_message));
	    temp->next->sdata.flag = 1;
	}
	temp = temp->next;
    }
    printf("\t\t\t\t留言成功!!!\n");
    writefile_stu(head);
}


//查看留言
void show_message()
{
    stu *head = readfile_stu();
    printf("\t\t\t\tid\t姓名\t留言\n");
    while(head->next != NULL)
    {
	if(head->next->sdata.flag == 1)
	{
	    printf("\t\t\t\t%d\t",head->next->sdata.id);
	    printf("%s\t",head->next->sdata.name);
	    printf("%s\n",head->next->sdata.message);
	}
	head = head->next;
    }
}

//申请辞职
void resign(char *id)
{
    tea *head = readfile();
    tea *temp = head;
    while(temp->next != NULL)
    {
	if(strcmp(temp->next->tdata.id,id) == 0)
	{
	    char write_message[MAX_MESSAGE];
	    printf("\t\t\t\t请填写辞职理由(不超过五十字):");
	    scanf("%s",write_message);
	    while(getchar() != '\n');
	    strncpy(temp->next->tdata.message,write_message,sizeof(write_message));
	    temp->next->tdata.flag = 1;
	}
	temp = temp->next;
    }
    printf("\t\t\t\t申请成功!!!\n");
    writefile(head);
}

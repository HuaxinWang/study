#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fun.h"
#include "login.h"


//自定义接收字符串函数
void mygets(char *str,int size)
{
    int i = 0;
    for(i = 0;i < size-1;i++)
    {
	str[i] = getchar();
	if(str[i] == '\n')
	{
	    break;
	}
    }
    str[i] = '\0';
    if(i == size-1)
    {
	while(getchar() != '\n');
    }
}

//教师查看学生信息排序
void ranking(char *id)
{
    while(1)
    {
	system("clear");
	char choice = '\0';
        printf("\t\t\t\t1-->按总分成绩排序\n");
        printf("\t\t\t\t2-->按学生id排序\n");
        printf("\t\t\t\tq-->返回上一层\n");
	printf("\n");
        printf("\t\t\t\t请输入你的选择:");
        scanf("%c",&choice);
        while(getchar() != '\n');
        switch(choice)
        {
	    case '1':

		//按总分高低排序
		sort_by_score();
		break;	    
	    case '2':

		//按id大小排序
		sort_by_id();
		break;
	    case 'q':
		teacher_menu(id);
		break;
	    default:
		printf("\t\t\t\t输入错误，按回车键重新输入!!!\n");
	}
	while(getchar() != '\n');
    }
}

//按总分排序输出
void sort_by_score()
{
    stu *head=readfile_stu();
    if(head->next==NULL)
    {
	printf("\t\t\t\t没有找到任何信息\n");
	return ;
    }
    stu *p1=head->next;
    stu *high;
    stu *p2;	
    stu *temp=(stu *)malloc(sizeof(stu));
    temp->next=NULL;	
    while(p1!=NULL)
    {
	high=p1;
	p2=p1->next;
	while(p2!=NULL)
	{
	    if((high->sdata.chinese + high->sdata.chinese) < (p2->sdata.chinese + p2->sdata.math))
	    {
		high=p2;
		p2=p2->next;
	    }
	    else
	    {
		p2=p2->next;
	    }
	}
	if(high!=p1)
	{
	    temp->sdata=high->sdata;
	    high->sdata=p1->sdata;
	    p1->sdata=temp->sdata;
	}	
	p1=p1->next;
    }
    printf("\t\t\t\tid\t姓名\t密码\t语文\t数学\n");
    while(head->next!=NULL)
    {
	printf("\t\t\t\t%d\t%s\t%s\t%.2f\t%.2f\n",head->next->sdata.id,head->next->sdata.name,head->next->sdata.passwd,head->next->sdata.chinese,head->next->sdata.math);
	head=head->next;
    }
}

//按id排序输出
void sort_by_id()
{
    stu *head=readfile_stu();
    if(head->next==NULL)
    {
	printf("\t\t\t\t没有任何信息\n");
	return ;
    }
    stu *p1=head->next;
    stu *low;
    stu *p2;
    stu *temp=(stu *)malloc(sizeof(stu));
    temp->next=NULL;	
    while(p1!=NULL)
    {
	low=p1;
	p2=p1->next;
	while(p2!=NULL)
	{
	    if(low->sdata.id > p2->sdata.id)
	    {
		low=p2;
		p2=p2->next;
	    }
	    else
	    {
		p2=p2->next;
	    }
	}
	if(low!=p1)
	{
	    temp->sdata=low->sdata;
	    low->sdata=p1->sdata;
	    p1->sdata=temp->sdata;
	}	
	p1=p1->next;
    }
    printf("\t\t\t\tid\t姓名\t密码\t语文\t数学\n");
    while(head->next!=NULL)
    {
	printf("\t\t\t\t%d\t%s\t%s\t%.2f\t%.2f\n",head->next->sdata.id,head->next->sdata.name,head->next->sdata.passwd,head->next->sdata.chinese,head->next->sdata.math);
	head=head->next;
    }
}

//教师查重
int teacher_id_repeat(char *id)
{
    tea *head=readfile();
    while(head->next != NULL)
    {
    	if(strcmp(head->next->tdata.id,id) ==0)
    	{
    	    printf("\t\t\t\t此id已经重复!!!\n");
    	    return 1;
    	}
    	head = head->next;
    }
    return 0;
}

//学生查重
int student_id_repeat(int id)
{
    stu *head=readfile_stu();
    while(head->next != NULL)
    {
    	if(head->next->sdata.id == id)    		
    	{
	    printf("\t\t\t\t此id已经重复!!!\n");
	    return 1;
    	}
    	head = head->next;
    }
    return 0;
}

//教师判空
int tea_nul(char *id)
{
    tea *head = readfile();
    while(head->next != NULL)
    {
	if(strcmp(head->next->tdata.id,id) == 0)
	{
	    return 0;
	}
	head = head->next;
    }
    printf("\t\t\t\t查无此id!!!\n");
    return 1;
}

//学生判空
int stu_nul(int id)
{
    stu *head = readfile_stu();
    while(head->next != NULL)
    {
	if(head->next->sdata.id == id)
	{
	    return 0;
	}
	head = head->next;
    }
    printf("\t\t\t\t查无此id!!!\n");
    return 1;
}


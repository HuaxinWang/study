#include <stdio.h>
#include <stdlib.h>
struct smessage
{
	int id;//学生学号
	char name[20];//名字
	char pwd[20];//密码
	float math;//数学成绩
	float chinese;//语文成绩
};
typedef struct student
{
	struct smessage sdata;
	struct student *next;
}stu;

//将结构体链表写进文件
void writefile(stu *head)
{
	if(NULL==head)
	{
		printf("no mesage to save\n");
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

//从文件将信息读到内存，即链表
stu *readfile()
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

//添加学生信息
void addstudent()
{
	stu *head=readfile();
	stu *temp=(stu*)malloc(sizeof(stu));
	if(temp==NULL)
	{
		printf("fail\n");
		return ;
	}
	temp->next=NULL;
	printf("input student id:");
	scanf("%d",&temp->sdata.id);
	
	printf("input student name:");
	scanf("%s",temp->sdata.name);
	
	printf("input student pwd:");
	scanf("%s",temp->sdata.pwd);
	
	printf("input student math score:");
	scanf("%f",&temp->sdata.math);
	
	printf("input student chinese score:");
	scanf("%f",&temp->sdata.chinese);
	
	if(head->next!=NULL)
	{
		temp->next=head->next;
	    head->next=temp;
	}
	else
	{
		head->next=temp;
	}
	writefile(head);
	return ;
}


//打印学生信息
void show()
{
	stu *head=readfile();
	if(head==NULL)
	{
		printf("no message\n");
		return ;
	}
	while(head->next!=NULL)
	{
		printf("%d,%s,%s,%.2f,%.2f\n",head->next->sdata.id,head->next->sdata.name,head->next->sdata.pwd,head->next->sdata.math,head->next->sdata.chinese);
		head=head->next;
	}
	printf("\n");
	return ;
}

//按照数学成绩从小到大排序
void sort()
{
	stu *head=readfile();
	if(head==NULL)
	{
		printf("no message\n");
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
			if(low->sdata.math>p2->sdata.math)
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
	
	while(head->next!=NULL)
	{
		printf("%d,%s,%s,%.2f,%.2f\n",head->next->sdata.id,head->next->sdata.name,head->next->sdata.pwd,head->next->sdata.math,head->next->sdata.chinese);
		head=head->next;
	}
	
}



int main(int argc,char *argv[])
{
	addstudent();
	show();
	sort();
	return 0;	
}

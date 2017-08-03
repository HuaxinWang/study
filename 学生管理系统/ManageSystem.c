#include"ManageSystem.h"


void search()
{

}
void print(student * head)
{
    student *p=head->next;
    while(p!=NULL&&p->data.id!=0)
    {
        printf("%d\n",p->data.id);
        p=p->next;
    }
}



/*创建头结点*/
student * creat()
{
    student *head=(student *)malloc(sizeof(student));
    head->next=NULL;
    return head;

}
void readinfo(student * head)
{
    student *q=head;
FILE *f;
  if((f=fopen("student.txt","r+"))==NULL)
    {
        printf("打开文件失败");
        return ;
    }
  rewind(f);
while(feof(f)==0){

student * p=(student *)malloc(sizeof(student));
fread(p,sizeof(student),1,f);
q->next=p;
q=p;
}
q->next=NULL;
}



/*
 * 函数名：添加学生
 *  参数：链表头节点
 *
 *   */
int  Add_student(student * head)
{
    int id;
printf("请输入学生的ID");
scanf("%d",&id);
if(Id_check(head,id)==0)
{
    return 1;
}
student *q=head;
student *p=(student *)malloc(sizeof(student));
while(q->next!=NULL)
{
q=q->next;
}
q->next=p;
p->next=NULL;

p->data.id=id;
printf("请输入学生的姓名\n");
scanf("%s",p->data.name);
getchar();
printf("请输入学生的密码\n");
scanf("%s",p->data.passwd);
getchar();

printf("请输入学生的年龄\n");
scanf("%d",&p->data.age);

getchar();
printf("请输入学生的班级\n");
scanf("%s",p->data.Class);

getchar();
printf("请输入学生的性别\n");
scanf("%s",p->data.sex);

getchar();
printf("请输入学生的语文成绩\n");
scanf("%d",&p->data.chinese);

getchar();
printf("请输入学生的数学成绩\n");
scanf("%d",&p->data.math);

getchar();
printf("请输入学生的C语言成绩\n");
scanf("%d",&p->data.c);
getchar();
p->data.all=p->data.c+p->data.math+p->data.chinese;
return 0;
}



int saveInfo(student * head)
{
    student *p=head->next;
    FILE *f;
    if((f=fopen("student.txt","w"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }
     fwrite(p,sizeof(student),1,f);
     fclose(f);
     f=NULL;
     p=p->next;

    if((f=fopen("student.txt","a"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }
    while(p!=NULL)
    {
        fwrite(p,sizeof(student),1,f);
        p=p->next;
    }
    fclose(f);
}



/*功能：检查ID是否重复
 *参数：(学生链表头节点，ID)
 *
 *
 *
 * */

int Id_check(student * head,int id)
{
    student *p=head->next;
    while(p!=NULL)
    {
        if(p->data.id==id)
        {
            return 0;
        }
       p=p->next;
    }
    return 1;
}


/*功能：按ID查找
 * 参数：（学生链表头节点，id）
 */
student * FindById(student * head,int id)
{
    student *p=head->next;
    while(p!=NULL)
    {
        if(p->data.id==id)
        {
            return p;
            p=p->next;
        }
    }
    return NULL;
}


int DeleteByID(student * head, int id)
{
    student *p=head->next;
    student *q=FindById(head,id);
    while(p!=NULL)
    {
        if(p->next==q)
        {
          p->next=q->next;
          free(q);
          return 0;
        }
    }
    return 1;
}



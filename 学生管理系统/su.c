#include"su.h"
#include"fire.h"

//打印所有教师的信息
//
 void printfallteacher(teacher * head)
{
    if(NULL == head || NULL == head->next)
    {
        printf("error");
    }
    teacher * p=head->next;
    printf("工号\t姓名\t职务\t科目\t班级\t在职情况\n");
    while(p!=NULL)
    {
        printf("%d\t%s\t%s\t%s\t%s\t",p->data.id,p->data.name,p->data.work,p->data.major,p->data.Class);
        if(p->data.fire==0)
        {
            printf("该老师在职\n");

        }
        else
        {
            printf("该老师已辞职\n");
        }
        p=p->next;
    }

}


//按ID从链表中查找对应的节点（返回指针）
teacher * searchteacher(teacher * head,int id)
{
    if(NULL == head || NULL == head->next)
    {
        printf("error");
    }
    teacher *p=head;
    while(p!=NULL)
    {
        if(p->data.id == id)
        {
            return p;
        }
        p=p->next;
    
    }
    return NULL;
}


//打印按ID找到的结果
void printfteacher(teacher *p)
{
    printf("工号\t姓名\t职务\t科目\t班级\t在职情况\n");
    printf("%d\t%s\t%s\t%s\t%s\t",p->data.id,p->data.name,p->data.work,p->data.major,p->data.Class);
    if(p->data.fire==0)
    {
        printf("该老师在职\n");

    }
    else
    {
        printf("该老师已辞职\n");
    }
    sleep(3);
}



//创建教师头节点
teacher * teacherhead()
{
teacher * head=(teacher *)malloc(sizeof(teacher));
if(NULL == head)
{
teacher * head=(teacher *)malloc(sizeof(teacher));
}
head->next=NULL;
return head;
}



//对教师工号进行查重
int teacherid_check(teacher * head,int id)
{

    teacher *p=head->next;
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


//添加教师
void addteacher(teacher * head)
{
    system("clear");
    long username;
    char passwd[20];
    char rpasswd[20];
    printf("请输入职工号(职工号以2开头的数字串):");
    scanf("%ld",&username);
    getchar();
    long check=username;
    while(check>=10)
    {
        check=check/10;
    }
    while(check!=2)
    {
        printf("职工号的第一位数字必须为2，请重新输入\n");
        scanf("%ld",&username);
        getchar();
        check=username;
        while(check>=10)
        {
            check=check/10;
        }
        sleep(1);
    }
    if(teacherid_check(head,username)==0)
    {
        system("clear");
        printf("该工号已注册，添加失败\n");
        sleep(2);
        return ;
    }
    


    if(NULL == head)
    {
        printf("error addteacher");
        return ;
    }
    teacher * p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
    printf("请输入密码:");
    scanf("%s",passwd);
    getchar();
    printf("请确认密码:");
    scanf("%s",rpasswd);
    getchar();
    while(strcmp(passwd,rpasswd)!=0)
    {
        printf("两次密码不一致,请重新确认密码:");
        scanf("%s",rpasswd);
        getchar();
    }  
    teacher *q = (teacher *)malloc(sizeof(teacher ));
    q->data.id=username;
    strcpy(q->data.passwd,passwd);
    printf("请输入教工姓名:\t");
    scanf("%s",q->data.name);
    getchar();
    printf("请输入教师职务\t");
    scanf("%s",q->data.work);
    getchar();
    printf("请输入教师科目\t");
    scanf("%s",q->data.major);
    getchar();
    printf("该教师是否为班主任(y/n)\t");
    char ld;
    scanf("%c",&ld);
    printf("该老师所属班级");
    scanf("%s",q->data.Class);
    if(ld=='y')
    {
        q->data.lt=1;
    }
    else 
    {
        q->data.lt=0;
    }
    q->data.fire=0;
    p->next=q;
    q->next=NULL;
    saveteacher(head);
    system("clear");
    printf("添加成功\n");
    sleep(2);
    return ;
}


//删除教师
void deleteteacher(teacher *head,int id)
{
    if(NULL==head ||NULL == head->next)
    {
        printf("error");
        return;
    }
teacher * p=searchteacher(head,id);
if(p==NULL)
{
    printf("该工号不存在");
    return;
}
teacher * q=head;
while(q->next!=NULL)
{
    if(q->next == p)
    {
        q->next=p->next;
        free(p);
        p=NULL;
        printf("删除成功");
        saveteacher(head);
        return;
    }
    q=q->next;
}
}
//从文件中读取教师信息到链表中
void readteacher(teacher * head)
{
    teacher *q=head;
    FILE *f;
    if((f=fopen("teacher.txt","r+"))==NULL)
    {
        printf("打开文件失败");
        return ;
    }
    while(feof(f)==0){

        teacher * p=(teacher *)malloc(sizeof(teacher));
        fread(p,sizeof(teacher),1,f);
        if(p->data.id==0)
        {
            free(p);
            continue;
        }
        q->next=p;
        q=p;
    }
    q->next=NULL;
}

//把链表中的信息存储到文件中
int saveteacher(teacher * head)
{
    if(NULL == head )
    {
        printf("error1");
        return 1;
    }
    teacher * p;
    if(head->next==NULL)
    {
        p=head;
    }
    else
        p=head->next;
    FILE *f;
    if((f=fopen("teacher.txt","w"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    fwrite(p,sizeof(teacher),1,f);
    fclose(f);
    f=NULL;
    p=p->next;
    if(p == NULL)
    {
        return 1;
    }
    if((f=fopen("teacher.txt","a"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    while(p!=NULL)
    {
        fwrite(p,sizeof(teacher),1,f);
        p=p->next;
    }
    fclose(f);
    p=NULL;
    return 0;

}

//对教师的信息进行修改
void editteacher(teacher *p)
{
    int a;
    while(1)
    {
        system("clear");
    printf("*****************************\n");
    printf("*    1.教工号               *\n");
    printf("*    2.姓名                 *\n");
    printf("*    3.职务                 *\n");
    printf("*    4.所教课程             *\n");
    printf("*    5.返回上层             *\n");
    printf("*   请选择要更改的信息:     *\n");
    printf("*****************************\n");
    scanf("%d",&a);
    getchar();


    switch (a)
    {
        case 1:
            {
                printf("请输入新的教工号:\n");
                scanf("%d",&p->data.id);
                getchar();
                printf("修改成功:\n");
                printf("按任意键返回");
                getchar();
                break;
            }
        case 2:
            {
                printf("请输入新的姓名\n");
                scanf("%s",p->data.name);
                getchar();
                printf("修改成功\n");
                printf("按任意键返回");
                getchar();
                break;
            }
        case 3:
            {
                printf("请输入新的职务\n");
                scanf("%s",p->data.work);
                getchar();
                printf("修改成功\n");
                printf("按任意键返回");
                getchar();
                break;
            }
        case 4:
            {
                printf("请输入所教科目\n");
                scanf("%s",p->data.major);
                getchar();
                printf("修改成功\n");
                printf("按任意键返回");
                getchar();
                break;
            }
        case 5:
            {
         return ;
            }

    }
    }
}

void teacherpw(int id)
{
    char passwd[20];
    char rpasswd[20];
   teacher *head = teacherhead();
   readteacher(head);
   teacher *p=head;
   while(p!=NULL)
   {
       if(p->data.id==id)
       {
           break;
       }
       p=p->next;
   }
   if(p->data.id==id)
   {
    printf("请输入密码:");
    scanf("%s",passwd);
    getchar();
    printf("请确认密码:");
    scanf("%s",rpasswd);
    getchar();
    while(strcmp(passwd,rpasswd)!=0)
    {
        printf("两次密码不一致,请重新确认密码:");
        scanf("%s",rpasswd);
        getchar();
    }
    strcpy(p->data.passwd,passwd);
    saveteacher(head);
    printf("修改成功\n");
    sleep(2);
    system("clear");
    return ;
   }
  printf("没有这个人\n");
  return ;
}

//提醒
void mind()
{
    printf("按回车返回上层\n");
    while(getchar()!='\n')
    {
    }

    return ;
}

//管理员功能入口
void Sulogin()
{
    fire * fhead=firehead();
    readfire(fhead);
    teacher *head=teacherhead();
    readteacher(head);
    viewadmit(fhead,head);
   int teach;
   while(1)
   {
       teach=0;
    system("clear");
    printf("*****************************\n");
    printf("*    1.添加教师信息         *\n");
    printf("*    2.修改教师信息         *\n");
    printf("*    3.查看教师信息         *\n");
    printf("*    4.删除教师信息         *\n");
    printf("*    5.查看所有教师         *\n");
    printf("*    6.修改教师密码         *\n");
    printf("*    7.返回主界面           *\n");
    printf("*    请选择:                *\n");
    printf("*****************************\n");
    scanf("%d",&teach);
    getchar();
    switch (teach)
    {
        int a;
        case 1:
            {
                addteacher(head);
                mind();
            break;
            }
        case 2:
            {
                printf("请输入要查找的老师工号\n");
                scanf("%d",&a);
                getchar();
                teacher * goal=searchteacher(head,a);
                if(goal!=NULL)
                {
                editteacher(goal);
                }
                else
                {
                    printf("该工号不存在");
                }
                saveteacher(head);
                break;
            }
        case 3:
            {
                printf("请输入要查找的老师工号:\n");
                scanf("%d",&a);
                getchar();
                teacher * goal=searchteacher(head,a);
              if(NULL != goal)
              {
                printfteacher(goal);
              }
              else
              {
                  printf("该工号不存在.\n");
              }
              sleep(2);
              system("clear");
              mind();
              break;
            }
        case 4:
            {
                
                printf("请输入要删除的教师工号:");
                scanf("%d",&a);
                getchar();
                deleteteacher(head,a);
                mind();
                break;

            }
        case 5:
            {
                printfallteacher(head);
                mind();
                break;
            }
        case 6:
        {
       printf("请输入想要更改密码的工号");
       int id;
       scanf("%d",&id);
       teacherpw(id);
       break;
        }
        case 7:
            {
                return ;
            }
        default:
            {
                printf("输入错误");
                break;
            }

    }
   }
}





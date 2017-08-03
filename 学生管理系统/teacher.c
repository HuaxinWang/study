#include "teacher.h"
#include "message.h"
#include "fire.h"
/*void printfall(user *head)
{
    system("clear");
    if(NULL == head || NULL == head->next)
    {
        printf("erorr");
        return;
    }
user *p=head->next;
printf("姓名\t学号\t年龄\t性别\t班级\t语文\t数学\tC语言\t总分\t排名\n");
while(p!=NULL)
{
    printf("%s\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",p->data.name,p->data.id,p->data.age,p->data.sex,p->data.Class,p->data.chinese,p->data.math,p->data.c,p->data.all,p->data.rank);
    p=p->next;
}
return ;
}*/




// 对排序过后的链表中结点名次进行赋值
//
//
void rank(user *head)
{
    int count=0;
    user *p=head->next;
    while(p!=NULL)
    {
        count++;
        p->data.rank=count;
        p=p->next;

    }
}




//打印所有学生的信息
void printfallstudent(user * head)
{
    int count=0;
    if(NULL == head || NULL == head->next)
    {
        printf("error");
    }
    user * p=head->next;
printf("排名\t姓名\t学号\t年龄\t性别\t班级\t语文\t数学\tC语言\t总分\n");
    while(p!=NULL)
    {
        if(p->data.id>=0 && p->data.c!=0 && p->data.chinese!=0 && p->data.math!=0)
        {
            count++;
     p->data.rank=count;
    printf("%d\t%s\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",count,p->data.name,p->data.id,p->data.age,p->data.sex,p->data.Class,p->data.chinese,p->data.math,p->data.c,p->data.all,p->data.rank);
        }    
    p=p->next;
    }
     p=NULL;
  printf("按任意键返回");
  saveStu(head);
     getchar();
  system("clear");

}


//打印符合名字和班级条件的学生
void printfname(user *head,char *Class)
{
    int count=0;
    if(NULL == head || NULL == head->next)
    {
        printf("没有这个人\n");
        return;
    }
user *p=head->next;
printf("姓名\t学号\t年龄\t性别\t班级\t语文\t数学\tC语言\t总分\t排名\n");
while(p!=NULL)
{
    if(strcmp(p->data.Class,Class)==0)
    {
    printf("%s\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",p->data.name,p->data.id,p->data.age,p->data.sex,p->data.Class,p->data.chinese,p->data.math,p->data.c,p->data.all,p->data.rank);
    count++;
    }

    if(count==0)
        printf("你的班级中没有这个人\n");
    p=p->next;
}
return ;
}


//按名字搜索学生 
user * searchname(user *head,char *name)
{
    user * h=creatStu();
    user * s=h;
    if(NULL == head || NULL == head->next)
    {
        printf("error");
    }
    while(s->next!=NULL)
    {
        s=s->next;
    }
    user *p=head;
    while(p!=NULL)
    {
        if(strcmp(p->data.name,name)==0)
        {
             user *q=(user *)malloc(sizeof(user));
             q->data=p->data;
             s->next=q;
             q->next=NULL;
             s=q;
        }
        p=p->next;
    }
    if(NULL == h || NULL == h->next )
    {
        printf("未找到此人\n");
         return NULL;
    }
    return h;

}

//按ID查找学生
user *  searchStu(user * head,int id)
{
    sortbyall(head);
    rank(head);
    if(NULL == head || NULL == head->next)
    {
        printf("error");
    }
    printf("姓名\t学号\t年龄\t性别\t班级\t语文\t数学\tC语言\t总分\t排名\n");
    user *p=head;
    while(p!=NULL)
    {
        if(p->data.id == id)
        {
            printf("%s\t%d\t%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n",p->data.name,p->data.id,p->data.age,p->data.sex,p->data.Class,p->data.chinese,p->data.math,p->data.c,p->data.all,p->data.rank);
            return p;
        }
        p=p->next;

    }
    printf("该学号不存在");
    return NULL;
}





//删除学生
void deleteStu(user * head,int id)
{ char choice;
    user * goal=searchStu(head,id);
if(goal==NULL)
{
    printf("没有这个人\n");
    return ;
}
printf("你确定要删除这个学生的信息吗？ y/n");
scanf("%c",&choice);
if(choice =='n')
{
    printf("取消成功");
    return ;
}

user * p=head;
    while(p->next!=NULL)
    {
        if(p->next==goal)
        {
            p->next= goal->next;
            free(goal);
           saveStu(head);
            printf("删除成功\n");
            sleep(1);
            return ;
        }
       p=p->next;
    }
    return ;

    }
    int judge(teacher * p)
    {
        if(strcmp("语文",p->data.major)==0)
        {
            return 1;
        }
        else  if(strcmp("数学",p->data.major)==0)
        {
            return 2;
        }
        if(strcmp("c语言",p->data.major)==0)
        {
            return 3;
        }
       return 0;
    }
    void printfmajor(user * head,int i)

{
    int count=0;
    sortbygrades(head,i);
    if(NULL == head || NULL == head->next)
    {
        printf("error\n");
    }
    user * p=head->next;
    
    if(i==1)
    {
        printf("排名\t学号\t姓名\t语文成绩\n");
       while(p!=NULL)
       {
           if(p->data.id <=0 || p->data.chinese==0)
           {
           p=p->next;
           continue;
           }
           count++;
           printf("%d\t%d\t%s\t%d\n",count,p->data.id,p->data.name,p->data.chinese);
           p=p->next;
       }
       return ;
    }
    else if(i==2)
    {
        printf("排名\t学号\t姓名\t数学成绩\n");
       while(p!=NULL)
       {
           if(p->data.id <=0 || p->data.math==0)
           {
           p=p->next;
           continue;
           }
           count++;
           printf("%d\t%d\t%s\t%d\n",count,p->data.id,p->data.name,p->data.math);
           p=p->next;
       }
       return ;
    }
    else if(i==3)
    {
        printf("排名\t学号\t姓名\tC语言成绩\n");
       while(p!=NULL)
       {
           if(p->data.id <=0 || p->data.c==0)
           {
           p=p->next;
           continue;
           }
           count++;
           printf("%d\t%d\t%s\t%d\n",count,p->data.id,p->data.name,p->data.c);
           p=p->next;
       }
       return ;
    }

}



//对单科成绩进行修改（针对任课教师）
void editmajor(user * head,int i)
{
    int a,grade;
    printf("请输入你要修改的学号\n");
    scanf("%d",&a);
   user * p=   searchStu(head,a);
   if(NULL == p)
   {
   return ;
   }
    if(i==1)
    {
        printf("请输入新的语文成绩\n");
        scanf("%d",&grade);
        getchar();
        printf("确定要更改吗?y/n");
        char c;
        scanf("%s",&c);
        getchar();
        if(c=='y')
        {
            p->data.chinese=grade;
           p->data.all=p->data.chinese+p->data.math+p->data.c;
           sortbygrades(head,i);
           printf("修改成功。\n");
           saveStu(head);
           sleep(1);
        }
        else
        {
            printf("取消修改成功。\n");
            sleep(1);
            return ;
        }
    }
    else if(i==2)
    {
        printf("请输入新的数学成绩\n");
        scanf("%d",&grade);
        getchar();
        printf("确定要更改吗?y/n");
        char c;
        scanf("%s",&c);
        getchar();
        if(c=='y')
        {
            p->data.math=grade;
           p->data.all=p->data.chinese+p->data.math+p->data.c;
           sortbygrades(head,i);
           printf("修改成功。\n");
           saveStu(head);
           sleep(1);
        }
        else
        {
            printf("取消修改成功。\n");
            sleep(1);
            return ;
        }
    }
else if(i==3)
    {
        printf("请输入新的C语言成绩\n");
        scanf("%d",&grade);
        getchar();
        printf("确定要更改吗?y/n");
        char c;
        scanf("%s",&c);
        getchar();
        if(c=='y')
        {
            p->data.c=grade;
           p->data.all=p->data.chinese+p->data.math+p->data.c;
           sortbygrades(head,i);
           printf("修改成功。\n");
           saveStu(head);
           sleep(1);
        }
        else
        {
            printf("取消修改成功。\n");
            sleep(1);
            return ;
        }
    }

}




//任课教师登录入口
void tLogin(int Tid)
{
    user * shead = creatStu();
    readStu(shead);
    message * mhead=messagehead();
    readmessage(mhead);
    teacher * head= teacherhead();
    readteacher(head);
    teacher * p=head;
    while(p->data.id!=Tid)
    {
        p=p->next;
    //            RankUI(head);
    }
    while(1){
    system("clear");
    int major=judge(p);
    int choice;
    char work[10];
    if(major==1)
    {
        strcpy(work,"语文");

    }

    else if(major==2)
    {
        strcpy(work,"数学");

    }
    else
    {
        strcpy(work,"C语言");
    }
    printf("%s教师,%s老师你好！\n",work,p->data.name);
    printf("*****************************\n");
    printf("*    1.修改学生成绩         *\n");
    printf("*    2.查看学生信息         *\n");
    printf("*    3.查看排名信息         *\n");
    printf("*    4.修改密码             *\n");
    printf("*    5.查看留言             *\n");
    printf("*    6.返回                 *\n");
    printf("*    请选择:                *\n");
    printf("*****************************\n");
    system("tput cup 9 12");
    scanf("%d",&choice);
    getchar();
    printf("\n");
    switch (choice)
    {
        case 1:
            {
           editmajor(shead,major);
            break;
            }
        case 2:
            {
                printfmajor(shead,major);
                printf("按任意键返回上层菜单");
                getchar();
                break;
            }
        case 3:
            {
                sortbygrades(shead,major);
                printfmajor(shead,major);
                printf("按任意键返回上层");
                getchar();
                break;
            }
        case 4:
            {
                
                Teacherchangepw(Tid);
                return ;
                break;
            }
        case 5:
            {
              viewmessage(p,mhead);  
              return;
            }
        case 6:
            {
                return ;
            }
        default:
            {
                printf("输入错误，请重新输入");
            }
    }
    }
}



//班主任登录入口  
void TLogin(int Tid)
{  
    int choice;
    user *head = creatStu();
    teacher * Thead =teacherhead();
    readteacher(Thead);
    teacher *p =Thead;
    message *mhead=messagehead();
    readmessage(mhead);
    fire * fhead=firehead();
    readfire(fhead);
    while(p->data.id!=Tid)
    {
  p=p->next;
    }
    checkfire(p,Thead,Tid);
 readStu(head);
   while(1)
   {

   
    system("clear");
    printf("*****************************\n");
    printf("*    1.添加学生信息         *\n");
    printf("*    2.修改学生信息         *\n");
    printf("*    3.查看学生信息         *\n");
    printf("*    4.删除学生             *\n");
    printf("*    5.查看排名             *\n");
    printf("*    6.修改密码             *\n");
    printf("*    7.查看留言             *\n");
    printf("*    8.申请辞职             *\n");
    printf("*    9.返回主界面           *\n");
    printf("*    请选择:                *\n");
    printf("*****************************\n");
    system("tput cup 10 12 ");
    scanf("%d",&choice);
    getchar();
    printf("\n");
    switch (choice)
    {
        case 1:
            {
                addStu(head);
                mind();
                system("clear");
               saveStu(head);
  
                break;
            }
        case 2:
            {
                int goal;
                printf("请输入要查找的学生id");
                scanf("%d",&goal);
                user *aim=searchStu(head,goal);
                if(aim== NULL)
                {
                    printf("没有这个学生！");
                    return ;
                }

                editStu(aim);

                sortbyall(head);
                rank(head);
                saveStu(head);
                break;
            }
        case 3:
            {
               searchUI(head,p->data.Class);
         //      sort(head);
               system("clear");

               break;
            }
        case 4:
            {
                int id;
                printf("请输入要删除的id");
                scanf("%d",&id);
                getchar();
                deleteStu(head,id);
                getchar();
                sortbyall(head);
                rank(head);     
           
                saveStu(head);
                break;
            }
        case 5:
            {
                rankUI(head);
                break;
            }
        case 6:
            {
                Teacherchangepw(Tid);
                return ;
                break;
            }
        case 7:
            {
              viewmessage(p,mhead);  
              break;
            }
        case 8:
            {
              admitfire(fhead,Tid);
            }

        case 9:
            {
                return ;
            }
    }
   }
}



//排名界面
void rankUI(user *head)
{
    system("clear");
int a;
    printf("*****************************\n");
    printf("*    1.按学号排名           *\n");
    printf("*    2.按总分排名           *\n");
    printf("*    3.返回上层             *\n");
    printf("*   请选择要查询的方式:     *\n");
    printf("*****************************\n");
    system("tput cup 4 23");
    scanf("%d",&a);
    getchar();
    printf("\n");
    switch (a)
    {
        case 1:
            {
                sort(head);

                printfallstudent(head);
                return ;
            }
        case 2:
            {
                 sortbyall(head);
                 printfallstudent(head);
            }
        case 3:
            {
                return ;
            }
        default:
            {
                printf("输入错误");
                return ;
            }
    }

}



//教师更改密码
void Teacherchangepw(int Tid)
{

    teacher * head =teacherhead();
    readteacher(head);
    teacher *p=head;
    while(p!=NULL)
    {
        if(p->data.id==Tid)
        {
            char passwd[20];
            char rpasswd[20];
           while(strcmp(passwd,p->data.passwd)!=0)
           {
            printf("请输入原密码");
            scanf("%s",passwd);
            getchar();
           }
            if(strcmp(passwd,p->data.passwd)==0)
            {

                printf("请输入新密码:");
                scanf("%s",passwd);
                getchar();
                printf("请确认新密码:");
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
                 printf("修改成功，将退出登录\n");
                 sleep(2);
                 return ;

            }
            return ;

        }

            p=p->next;
    }
    return ;
}


//按单科成绩进行排名
void sortbygrades(user *stuhead,int major)
{
	user *p=stuhead->next;
	user *q=p->next;
    struct userinfo temp;
    if(major==1)
    {
	while(p->next){
		while(q){
			if(q->data.chinese > p->data.chinese){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
		q=p->next;
	}

    }
    else if(major==2)
    {
	while(p->next){
		while(q){
			if(q->data.math > p->data.math){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
		q=p->next;
	}

    }
    else if(major==3)
    {
	while(p->next){
		while(q){
			if(q->data.c > p->data.c){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
		q=p->next;
	}

    }
    return ;
}


//按总分进行排序
void sortbyall(user *stuhead){
	user *p=stuhead->next;
	user *q=p->next;
    struct userinfo temp;
	while(p->next){
		while(q){
			if(q->data.all > p->data.all){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
		q=p->next;
	}
}


//按学号进行排序
void sort(user *stuhead){
	user *p=stuhead->next;
	user *q=p->next;
    struct userinfo temp;
	while(p->next){
		while(q){
			if(q->data.id<p->data.id){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
		p=p->next;
		q=p->next;
	}
}



///修改成绩界面
void editStu(user *p)
{
   
    int a;
    printf("*****************************\n");
    printf("*    1.姓名                 *\n");
    printf("*    2.性别                 *\n");
    printf("*    3.年龄                 *\n");
    printf("*    4.班级                 *\n");
    printf("*    5.c语言成绩            *\n");
    printf("*    6.语文成绩             *\n");
    printf("*    7.数学成绩             *\n");
    printf("*    8.返回上层             *\n");
    printf("*   请选择要更改的信息:     *\n");
    printf("*****************************\n");
    scanf("%d",&a);
    getchar();


    switch (a)
    {
        case 1:
            {
                printf("请输入姓名");
                scanf("%s",p->data.name);
                getchar();
                printf("修改成功");
                break;
            }
        case 2:
            {
                printf("请输入性别");
                scanf("%s",p->data.sex);
                getchar();
                printf("修改成功");
                break;
            }
        case 3:
            {
                printf("请输入年龄");
                scanf("%d",&p->data.age);
                getchar();
                printf("修改成功");
                break;
            }
        case 4:
            {
                printf("请输入班级");
                scanf("%s",p->data.Class);
                getchar();
                printf("修改成功");
                break;
            }
        case 5:
            {
                printf("请输入C语言成绩");
                scanf("%d",&p->data.c);
                getchar();
                printf("修改成功");
                break;
            }
        case 6:
            {
                printf("请输入语文成绩");
                scanf("%d",&p->data.chinese);
                getchar();
                printf("修改成功");
                break;
            }
        case 7:
            {
                printf("请输入数学成绩");
                scanf("%d",&p->data.math);
                getchar();
                printf("修改成功");
                break;
            }
        case 8:
            {
                return ;
            }

    }

}

//创建学生链表的头结点
user * creatStu()
{
    user * head=(user *)malloc(sizeof(user));
    if(NULL == head)
    {
        user * head=(user *)malloc(sizeof(user));

    }
    head->next=NULL;
    return head;
}

//添加学生用户
void addStu(user *head)

{
    system("clear");
    long username;
    char passwd[20];
    char rpasswd[20];
   long check;
printf("请输入学号(学号必须以3开头):");
    scanf("%ld",&username);
    getchar();
    check=username;
    while(check>=10)
    {
        check=check/10;
    }
while(check!=3)
{
    printf("请输入学号(学号必须以3开头):");
    scanf("%ld",&username);
    getchar();
    check=username;
    while(check>=10)
    {
        check=check/10;
    }
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
    if(Userid_check(head,username)==0)
    {
        system("clear");
        printf("该学号已注册，请重试\n");
        sleep(2);
        return ;
    }

    if(NULL == head)
    {
        printf("error add");
        return ;
    }


   user *p=head;
    while(p->next != NULL)
    {
        p=p->next;
    }
user *q = (user *)malloc(sizeof(user ));
   q->data.id=username;
   strcpy(q->data.passwd,passwd);
   printf("请输入学生姓名\n");
   scanf("%s",q->data.name);
   getchar();
   printf("请输入学生性别\n");
   scanf("%s",q->data.sex);
   getchar();
   printf("请输入学生年龄\n");
   scanf("%d",&q->data.age);
   getchar();
   printf("请输入学生班级\n");
   scanf("%s",q->data.Class);
   getchar();
   printf("请输入学生C语言成绩\n");
   scanf("%d",&q->data.c);
   getchar();
   printf("请输入学生语文成绩\n");
   scanf("%d",&q->data.chinese);
   getchar();
   printf("请输入学生数学成绩\n");
   scanf("%d",&q->data.math);
   getchar();
   q->data.all=q->data.math+q->data.chinese+q->data.c;
   p->next=q;
   q->next=NULL;
   saveStu(head);
    system("clear");
    printf("添加成功\n");
    sleep(2);
    sortbyall(head);
    system("clear");
    return ;	
}



//从文件读取学生的信息
void readStu(user * head)
{
    user *q=head;
    FILE *f;
    if((f=fopen("user.txt","r+"))==NULL)
    {
        printf("打开文件失败");
        return ;
    }
    while(feof(f)==0){

        user * p=(user *)malloc(sizeof(user));
        fread(p,sizeof(user),1,f);
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


//把学生信息保存到文件
int saveStu(user * head)

{
    
    //readStu(head);
       if(NULL == head)
    {
        printf("error");
        return 1;
    }
    user *p=head;
    FILE *f;
    if((f=fopen("user.txt","w"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }
    fwrite(p,sizeof(user),1,f);
    fclose(f);
    f=NULL;
    p=p->next;
    if(p == NULL)
    {
        return 1;
    }
    if((f=fopen("user.txt","a"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }
    while(p!=NULL)
    {
        fwrite(p,sizeof(user),1,f);
        p=p->next;
    }
    fclose(f);
    return 0;

/*

    if(NULL == head )
    {
        printf("error1");
        return 1;
    }
ser * p;
    if(head->next==NULL)
    {
        p=head;
    }
    else
        p=head->next;
    FILE *f;
    if((f=fopen("user.txt","w"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    fwrite(p,sizeof(user),1,f);
    fclose(f);
    f=NULL;
    p=p->next;
    if(p == NULL)
    {
        return 1;
    }
    if((f=fopen("user.txt","a"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    while(p!=NULL)
    {
        fwrite(p,sizeof(user),1,f);
        p=p->next;
    }
    fclose(f);
    p=NULL;
    return 0;*/

}

//搜索界面
void searchUI(user * head,char *Class)
{
    system("clear");
    int a;
    printf("*****************************\n");
    printf("*    1.按姓名               *\n");
    printf("*    2.按学号               *\n");
    printf("*    3.返回上层             *\n");
    printf("*   请选择要查询的方式:     *\n");
    printf("*****************************\n");
    system("tput cup 4 23");
    scanf("%d",&a);
    getchar();
    printf("\n");
    switch (a)
    {
        case 1:
            {
                char name[20];
            printf("请输入姓名");
            scanf("%s",name);
            getchar();
            user * goal=searchname(head,name);
            if(NULL == goal)
            {
                return ;
            }
            printfname(goal,Class);
            mind();
            return ;
            }
        case 2:
            {
                int id;
                printf("请输入学号");
                scanf("%d",&id);
                getchar();
                user * p=searchStu(head,id);
                char a[20];
                strcpy(a,p->data.Class);
                if(strcmp(a,Class))
                {
                    system("clear");
                    printf("该学生不在你的班级里\n");
                }
                mind();
                return ;
            }
        case 3:
            {
                return ;
            }
        default:
            {
                printf("输入错误");
                return ;
            }
    }

}

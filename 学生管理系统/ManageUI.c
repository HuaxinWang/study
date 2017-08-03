#include "ManageUI.h"
#include "teacher.h"
#include "student.h"
#include <time.h>
char  code[4];
 void   verify()
{
    int n,choice;
    srand((unsigned) time(NULL));
    
    for(int i=0;i<4;i++)
    
    {
        choice=rand()%2;
        if(choice==0){
        n=rand()%(9)+48;
        }
        else
        {
            n=rand()%26+65;
        }
        code[i]=n;
    
    
}
    printf("%s",code);
}




//开始界面
void welcome(user * head)
{

    system("clear");
    char choice='0';
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|  欢迎进入s q学生管理系统  |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|    1.登录                 |\n");
    printf("|    q.退出                 |\n");
    printf("|                           |\n");
    printf("|    请选择:                |\n");
    printf("|                           |\n");
    printf("|                           |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    system("tput cup 6 12");
    scanf("%c",&choice);
    getchar();
    switch(choice)
    {
        case '1':
        {
            login(head);
            break;
        }

        case 'q':
        {
            system("clear");
            printf("感谢使用!!!\n");
            sleep(2);
            exit(1);
        }
        default:
        {
            printf("输入错误，请按回车键重新选择\n\n\n\n");
            while(getchar() != '\n');
            break;
        }
    }
}


void login()
{
    int id,check;
    char passwd[20];
    char input[4];
    char pass[1];
    system("clear");
    printf("*********************\n");
    printf("*       登录        *\n");
    printf("*********************\n");
    printf("*   账  号:         *\n");
    printf("*   密  码:         *\n");
    printf("*   验证码:         *\n");
    printf("*          ");
    verify();
    printf("     *\n");
    printf("*********************\n");
    system("tput cup 3 11");
    scanf("%d",&id);
    getchar();
    system("tput cup 4 11");
    printf("\033[8m");
    check=id;
    scanf("%s",passwd);
    printf("\033[0m");
    getchar(); 
    system("tput cup 5 11");
    scanf("%s",input);
    getchar();
    while(strcmp(input,code)!=0)
    {
        system("tput cup 8 1");
        printf("验证码错误，请重新输入:");
    scanf("%s",input);
    getchar();
    }
if(id != 1 )
{
    while(check>=10)
        {
        check=check/10;
        }
    if(check==2)
    {
        teacher * head =teacherhead();
         readteacher(head);
         teacher *p =head->next;
         if(NULL == p)
         {
          printf("没有教师");
         }
        while(p!=NULL)
        {
            if(p->data.id == id && strcmp(p->data.passwd,passwd)==0)
            {
                if(p->data.lt==1)
                {
               
               TLogin(id);
                }
                else 
                {
                    tLogin(id);
                }
                return ;
            }
            p=p->next;
        }
        printf("登陆失败,请重新检查你的用户名和密码.\n");
        sleep(2);
        return ;
    }
    else if(check==3)
    {
        user * head =creatStu();
         readStu(head);
         user *q =head->next;
         if(NULL == q)
         {
          printf("没有学生");
         }
        while(q!=NULL)
        {
            if(q->data.id == id && strcmp(q->data.passwd,passwd)==0)
            {
            stulogin(id);
            return ;
            }
            q=q->next;
        }
        printf("用户名不存在\n");
        sleep(2);
        return ;
    }

    else
    {
        printf("错误的账户类型,请重新输入\n");
        sleep(2);
        return ;
    }


    system("clear");
    printf("密码错误，请重试\n");
    sleep(2);
    return ;
}
    if(strcmp(passwd,"1213")==0)
    {
        system("clear");
        printf("欢迎登录，管理员\n");
        sleep(1);
        Sulogin();
        return ;

    }
system("clear");
printf("用户不存在\n");
sleep(1);
return ;
}
int Userid_check(user * head,int id)
{

    user *p=head->next;
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


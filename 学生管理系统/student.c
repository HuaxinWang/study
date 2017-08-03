#include "student.h"
#include "ManageUI.h"
#include "teacher.h"
#include "message.h"
void stulogin(int Sid)
{
user * head=creatStu();
readStu(head);
message * mhead =messagehead();
readmessage(mhead);
while(1)
{
system("clear");
int choice;
    printf("*****************************\n");
    printf("*    1.查询成绩             *\n");
    printf("*    2.修改密码             *\n");
    printf("*    3.留言                 *\n");
    printf("*    4.返回主界面           *\n");
    printf("*    请选择:                *\n");
    printf("*                           *\n");
    printf("*****************************\n");
scanf("%d",&choice);
switch (choice)
{
    case 1:
        {
            sortbygrades(head);
            searchStu(head,Sid);
            sleep(3);
            break;
        }
    case 2:
        {
            Stuchangepw(Sid);
            return ;
        }
    case 3:
        {
            addmessage(mhead);
            break;
        }
    case 4:
        {
            return ;
        }
}
}
}



void Stuchangepw(int Tid)
{

    user * head =creatStu();
    readStu(head);
    user *p=head;
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
                saveStu(head);
                printf("修改成功,将退出登录.\n");
                sleep(2);
                return ;

            }
            return ;

        }

        p=p->next;
    }
    return ;

}

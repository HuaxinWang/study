#include "message.h"
message * messagehead()
{
    message *head=(message *)malloc(sizeof(message));
    head->next=NULL;
    return head;
}

void viewmessage(teacher *head,message * mhead)
{
    system("clear");
    int count=0;
    if(mhead ==NULL || NULL == mhead->next || head== NULL)
    {
        printf("error");
        return;
    }
message *p=mhead;
while(p!=NULL)
{
    if(strcmp(head->data.name,p->data.belongname)==0)
    {
        printf("%s\n",p->data.text);
        count++;
   }
    p=p->next;
}
if(count== 0)
{
    printf("没有您的留言");

}
getchar();
return ;
}
void printfmessage(message *head)

{
    if(NULL == head || NULL == head->next)
    {
        printf("error");
    }
    message *p=head->next;
   while(p!=NULL)
    {
        printf("%saaaaaa\n",p->data.belongname);
        printf("1");
     p=p->next;
        getchar();
   }
}

void  addmessage(message *head)
{
    if(NULL == head )
    {
        printf("error");
    }
    message * p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }

    message * q=(message *)malloc(sizeof(message));
    printf("请输入你要留言的老师姓名:\n");
    scanf("%s",q->data.belongname);
    getchar();
    printf("请输入留言:\n");
    getchar();
    scanf("%s",q->data.text);
    getchar();
    printf("请输入你的姓名\n");
    scanf("%s",q->data.ownername);
    getchar();
    printf("留言成功");
    q->data.flag=1;
    p->next=q;
    q->next=NULL;
    savemessage(head);
}

void readmessage(message * head)
{
    message *q=head;
    FILE *f;
    if((f=fopen("message.txt","r+"))==NULL)
    {
        printf("打开文件失败");
        return ;
    }
    while(feof(f)==0){

        message * p=(message *)malloc(sizeof(message));
        fread(p,sizeof(message),1,f);
        if(p->data.flag!=1)
        {
            free(p);
            continue;
        }
        q->next=p;
        q=p;
    }
    q->next=NULL;
}


int savemessage(message * head)

{
    if(NULL == head )
    {
        printf("error1");
        return 1;
    }
    message * p;
    if(head->next==NULL)
    {
        p=head;
    }
    else
        p=head->next;
    FILE *f;
    if((f=fopen("message.txt","w"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    fwrite(p,sizeof(message),1,f);
    fclose(f);
    f=NULL;
    p=p->next;
    if(p == NULL)
    {
        return 1;
    }
    if((f=fopen("message.txt","a"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    while(p!=NULL)
    {
        fwrite(p,sizeof(message),1,f);
        p=p->next;
    }
    fclose(f);
    p=NULL;
    return 0;
/*
    if(NULL == head)
    {
        printf("error");
        return 1;
    }
    message *p=head;
    FILE *f;
    if((f=fopen("message.txt","w"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }
    fwrite(p,sizeof(message),1,f);
    fclose(f);
    f=NULL;
    p=p->next;
    if(p == NULL)
    {
        return 1;
    }
    if((f=fopen("message.txt","a"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }
    while(p!=NULL)
    {
        fwrite(p,sizeof(message),1,f);
        p=p->next;
    }
    fclose(f);
    return 0;
*/
}

#include"fire.h"
#include "message.h"
#include"su.h"
fire * firehead()
{
    fire * head=(fire *)malloc(sizeof(fire));
    if(NULL == head)
    {
        fire * head=(fire *)malloc(sizeof(fire));
    }
    head->next=NULL;
    return head;
}



void readfire(fire * head)
{
    fire *q=head;
    FILE *f;
    if((f=fopen("fire.txt","r+"))==NULL)
    {
        printf("打开文件失败");
        return ;
    }
    while(feof(f)==0){

        fire * p=(fire *)malloc(sizeof(fire));
        fread(p,sizeof(fire),1,f);
        if(p->data.id<=0 || p->data.name == NULL)
        {
            free(p);
            continue;
        }
        q->next=p;
        q=p;
    }
    q->next=NULL;

}

void deletefire(fire *head,fire *goal)
{
    if(NULL==head ||NULL == head->next)
    {
        printf("error");
        return;
    }
    fire * p=goal;
    fire * q=head;
    while(q->next!=NULL)
    {
        if(q->next == p)
        {
            q->next=p->next;
            free(p);
            p=NULL;
            savefire(head);
            return;
        }
        q=q->next;
    }
}
void viewadmit(fire * head,teacher *thead)
{
    system("clear");
    int count=0;
    if(head ==NULL || NULL == head->next || head== NULL)
    {
        return;
    }
    fire *p=head;
    teacher *q=thead;
    while(p!=NULL)
    {
        q=thead;
        while(q!=NULL)
        {
        if(q->data.id==p->data.id && p->data.id!= 0)
        {
            printf("教工号:%d,%s提出辞职申请\n理由:\n ",q->data.id,q->data.name);
            printf("%s\n",p->data.text);
            printf("是否同意？y/n");
            char c;
            scanf("%c",&c);
            getchar();
             if(c=='y')
             {
                 q->data.flag=1;
                 deletefire(head,p);
             }
             else if(c=='n')
             {
                 q->data.flag=2;
                 deletefire(head,p);
             }
            count++;
            q=q->next;
            break;
        }
        q=q->next;
        
        }
        p=p->next;
    }
    if(count== 0)
    {
        printf("没有辞职申请\n");

    }
    saveteacher(thead);
    return ;
}
void checkfire(teacher *t,teacher *head,int id)
{
    if(t->data.flag==1)
    {
        printf("你的辞职申请已被同意，3秒后退出管理系统\n");
        deleteteacher(head,id);
        sleep(3);
        exit(1) ;
    }
    else if(t->data.flag==2)
    {
        printf("你的辞职申请已被驳回。");
        sleep(2);
        t->data.flag=0;
        return; 
    }
}

void  admitfire(fire *head,int tid)
{
    if(NULL == head )
    {
        printf("error");
    }
    fire * p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }

    fire * q=(fire *)malloc(sizeof(fire));
    printf("请输入你的姓名:\n");
    scanf("%s",q->data.name);
    getchar();
    q->data.id=tid;
    printf("请输入辞职原因\n");
    scanf("%s",q->data.text);
    getchar();
    system("clear");
    printf("申请成功,请等待回应\n");
    sleep(2);
    p->next=q;
    q->next=NULL;
    savefire(head);
}

int savefire(fire * head)

{
    if(NULL == head )
    {
        printf("error1");
        return 1;
    }
    fire * p;
    if(head->next==NULL)
    {
        p=head;
    }
    else
        p=head->next;
    FILE *f;
    if((f=fopen("fire.txt","w"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    fwrite(p,sizeof(fire),1,f);
    fclose(f);
    f=NULL;
    p=p->next;
    if(p == NULL)
    {
        return 1;
    }
    if((f=fopen("fire.txt","a"))==NULL)
    {
        printf("打开文件失败");
        return 1;
    }

    while(p!=NULL)
    {
        fwrite(p,sizeof(fire),1,f);
        p=p->next;
    }
    fclose(f);
    p=NULL;
    return 0;
}


#ifndef _SU_H
#define _SU_H
#include <stdio.h>
#include "ManageSystem.h"
#include "ManageUI.h"
struct teacherinfo 
{
    int id;
    char name[20];
    char work[20];
    char major[20];
    char passwd[20];
    int  fire;
    int flag;
    int lt;
    char Class[20];
};

typedef struct teacher
{
    struct teacher * next;
    struct teacherinfo data;
}teacher;


//函数声明
teacher * searchteacher();
void teacherpw();
void Sulogin();
teacher * teacherhead();
void addteacher();
int saveteacher();
void printfteacher();
void deleteteacher();
void printfallteacher();
void mind();
void readteacher();


#endif

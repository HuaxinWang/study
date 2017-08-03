#ifndef _ManageSystem_H_
#define _ManageSystem_H_


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include"ManageUI.h"
struct stuinfo
{
    int id;
    char name[20];
    char passwd[20];
    int age;
    char Class[20];
    int math;
    int chinese;
    int c;
    char sex[15];
    int all;
};
typedef struct student
{
    struct stuinfo data;
    struct student *next;

} student;
void search();
student * creat();
int DeleteByID();
int Id_check();
int saveInfo();
int  Add_student();
void readinfo();
void print();
student * FindById();



#endif

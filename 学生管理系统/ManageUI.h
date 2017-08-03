#ifndef _ManageUI_H
#define _ManageUI_H
#include<stdio.h>
#include<string.h>
#include"ManageSystem.h"
#include "su.h"
struct userinfo
{
    int id;
    char name[20];
    char passwd[20];
    int age;
    char Class[20];
    int math;
    int chinese;
    int c;
    int rank;
    char sex[15];
    int all;
    int pro;

};
typedef struct user
{
    struct userinfo data;
    struct user * next;
} user;
void welcome();
user * password();
user *  creatUser();
void addUser();
void readuser();
int saveuser();
int ResUI();
void login();
int Userid_check();
void  verify();

#endif

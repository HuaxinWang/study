#ifndef _FIRE_H_
#define _FIRE_H_
#include<stdio.h>
#include<unistd.h>
struct fires
{
    char name[10];
   int id;
char text[100];
};


typedef struct fire
{
    struct fires data;
    struct fire  * next;
}fire;

fire * firehead();
void readfire();
int savefire();
void viewadmit();
void checkfire();
void admitfire();

#endif

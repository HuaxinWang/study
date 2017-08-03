#ifndef _MESSAGE_H_
#define _MESSAGE_H_
#include<stdio.h>
#include <stdlib.h>
#include "su.h"
struct messages
{
    
    int flag;
    char text[100];
    char belongname[20];
    char belongid;
    char ownername[20];
};
typedef struct message 

{
    struct messages data;
    struct message *next;
} message;


message * messagehead();
void printfmessage();
void addmessage();
void readmessage();
int savemessage();
void viewmessage();
#endif

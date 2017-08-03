#ifndef _teacher_h
#define _teacher_h
#include<stdio.h>
#include"su.h"
#include"ManageUI.h"
#include"ManageSystem.h"
void printfallstudent();
void rankUI();
void sortbyall();
void sortbygrades();
void welcome();
int judge();
void editmajor();
void printfmajor();
void tLogin();
user * password();
void Teacherchangepw();
user *  creatStu();
void addStu();
void readStu();
int saveStu();
int Stuid_check();
user * searchStu();
user * searchname();
void printfname();
void searchUI();
void TLogin();
void editStu();
void deleteStu();
void sort();
void rank();
void printfall();
#endif

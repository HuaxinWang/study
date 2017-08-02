#ifndef _FUN_H_
#define _FUN_H_

//自定义接收字符串
void mygets(char *str,int size);

//学生信息排序输出选择菜单
void ranking();

//按总分排序输出
void sort_by_score();

//按id排序输出
void sort_by_id();

//学生信息查重
int student_id_repeat(int id);

//教师信息查重
int teacher_id_repeat(char *id);

//学生信息判空
int stu_nul(int id);

//教师信息判空
int tea_nul(char *id);

#endif

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#define MAX_NAME_LEN 50
#define MAX_STUDENT_LEN 100

//定义菜单数字宏
#define MENU_ITEM_ADD 1
#define MENU_ITEM_DEL 2
#define MENU_ITEM_UPDATE 3
#define MENU_ITEM_FIND 4
#define MENU_ITEM_PRINT 5
#define MENU_ITEM_EXIT 0

//学生信息结构体类型及其别名
typedef struct student
{
	int id;
	char name[MAX_NAME_LEN];
	int score;
}student_t;

//顺序表结构体类型及其别名
typedef struct list
{
	//数据部分:存放具体数据
	student_t data[MAX_STUDENT_LEN];
	//游标部分:用于表示有效数据个数
	int count;
}list_t;

//菜单打印函数
void print_menu(void);

//向指定顺序表添加指定的学生信息
//插入成功,返回0;插入失败,返回-1
int add_student_to_list(list_t *l,student_t stu);

//从指定顺序表删除指定id的学生信息
//删除成功,返回0;删除失败,返回-1
int del_student_from_list(list_t *l,student_t *p_stu);

// 更改指定顺序表中指定id的学生信息
// 更新成功,返回0;更新失败,返回-1;
int update_student_info(list_t *l);

// 查询指定顺序表中指定id的学生信息
// 查询成功，返回0，p_stu传递学生信息；
// 失败，返回-1
int find_student_info(list_t *l,student_t *p_stu);

// 获取指定id在顺序表中的下标
// 成功，返回下标；失败，返回-1
int search_index_by_id(list_t *l, int id);

// 打印全部学生信息
void print_students_info(list_t *l);

//输入学生信息
void input_student_info(student_t *p_stu);

//打印学生信息
void print_student_info(student_t stu);

//判断顺序表是否满
//满,返回1;不满,返回0
int list_full(list_t *l);

//判断顺序表是否空
//空,返回0;不空,返回1
int list_empty(list_t *l);

#endif

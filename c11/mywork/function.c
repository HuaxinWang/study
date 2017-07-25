#include "function.h"
#include <stdio.h>

// 菜单打印函数
void print_menu(void)
{
	printf("上嵌学生管理系统V1.0\n");
	printf("1.添加学生信息\n");
	printf("2.删除学生信息\n");
	printf("3.更新学生信息\n");
	printf("4.查找学生信息\n");
	printf("5.显示学生信息\n");
	printf("0.退出\n");
	printf("请选择功能:");
}

// 向指定顺序表添加指定的学生信息
// 插入成功,返回0;插入失败,返回-1
int add_student_to_list(list_t *l,student_t stu)
{
	if(list_full(l))
	{
		return -1;
	}
	l->data[l->count] = stu;
	l->count++;
	return 0;
}

// 从指定顺序表删除指定id的学生信息
// 删除成功,返回0;失败,-1
int del_student_from_list(list_t *l,student_t *p_stu)
{
	if(list_empty(l))
	{
		return -1;
	}
	int index = 0;
	int id = 0;
	int i = 0;
	printf("请输入你要删除的学生信息id:");
	scanf("%d", &id);
	index = search_index_by_id(l, id);
	if(index == -1)
	{
		return -1;
	}
	// 传出删除的数据信息
	if(p_stu != NULL)
	{
		*p_stu = l->data[index];
	}											
	for(i = index; i < l->count; i++)
	{
		l->data[i] = l->data[i+1];
	}
	l->count--;
	return 0;
}

// 更改指定顺序表中指定id的学生信息
// 更新成,返回0;失败,-1
int update_student_info(list_t *l)
{
	if(list_empty(l))
	{
		return -1;
	}
	int index = 0;
	int id = 0;
	printf("请输入你想要更改的学生信息id:");
	scanf("%d", &id);
	index = search_index_by_id(l, id);								
	if(index == -1)
	{
		return -1;
	}
	printf("原始学生信息为:\n");
	print_student_info(l->data[index]);
	printf("新的姓名:");
	scanf("%s", l->data[index].name);
	printf("新的成绩:");
	scanf("%d", &l->data[index].score);
	return 0;
}

// 查询指定顺序表中指定id的学生信息
// 查询成功，返回0，p_stu传递学生信息；
// 失败，返回-1
int find_student_info(list_t *l,student_t *p_stu)
{
	if(list_empty(l))
	{
		return -1;
	}
	int index = 0;
	int id = 0;
	printf("请输入你想要查询的学生信息id:");
	scanf("%d", &id);
	index = search_index_by_id(l, id);
	if(index == -1)
	{
		return -1;
	}
	if(p_stu != NULL)
	{
		*p_stu = l->data[index];
	}
	return 0;
}

// 获取指定id在顺序表中的下标
// 成功,返回下标;失败,返回-1
int search_index_by_id(list_t *l, int id)
{
	int i = 0;
	for(i = 0; i < l->count; i++)
	{
		if(l->data[i].id == id)
		{
			return i;
		}
		return -1;
	}
}

// 打印全部学生信息
void print_students_info(list_t *l)
{
	int i = 0;
	printf("id\t姓名\t分数\n");
	for(i = 0; i < l->count; i++)
	{
		print_student_info(l->data[i]);
	}
}

// 输入学生信息
void input_student_info(student_t *p_stu)
{
	if(p_stu == NULL)
	{
		return;
	}
	printf("id:");
	scanf("%d", &(p_stu->id));
	printf("姓名:");
	scanf("%s", p_stu->name);
	printf("分数:");
	scanf("%d", &(p_stu->score));
}

// 打印学生信息
void print_student_info(student_t stu)
{
	printf("%d\t%s\t%d\n", stu.id, stu.name, stu.score);
}

int list_full(list_t *l)
{
	return l->count == MAX_STUDENT_LEN;
}

int list_empty(list_t *l)
{
	return l->count == 0;
}

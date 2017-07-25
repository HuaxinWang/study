#include <stdio.h>
#include <string.h>

// 刘磊

// 1.结构体类型定义
struct student
{
	char name[20];
	int age;
	int score;
};

int main(int argc, char *argv[])
{
	// 2.定义结构体变量
	struct student stu = {
		"lisi",
		17,
		730
	};
	struct student test;

	// 3.结构体变量成员的操作
	// 注意:使用时必须使用.号运算符引用到基本类型成员
	strncpy(stu.name, "zhangsan", 20);
	stu.age = 18;
	stu.score = 700;

	// 当结构体变量类型相同时，可以直接进行赋值运算
	// 必须在定义时指定的类型是相同的
	// 仅仅只有成员相同不行
	test = stu;

	printf("stu.name : %s\n", stu.name);

	printf("hello world\n");

	return 0;
}









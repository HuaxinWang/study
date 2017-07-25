#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct student
{
	char name[MAX_NAME_LEN];
	int age;
	int score;
}student_t;

// 命令行参数
// 命令行参数用于想程序传递在执行阶段才确定的数据
// 提升软件的可移植行
int main(int argc, char *argv[])
{
	//argc	命令行参数的个数
	//argv[][]字符串数组，每一行保存一个命令行参数
	//argv[0]
	//argv[1]
	//...
	//argv[argc-1]
	int i = 0;
	
	//[0,argc)
	for(i = 0; i < argc; i++)
	{
		printf("argv[%d] : %s\n", i, argv[i]);
	}

	// 1.结构体数组
	// 数组成员为结构体变量类型的数组
	//struct student stu_array[3];
	// 1.1结构体数组的定义和全部初始化
	student_t stu_array[3] = {
		{"zhangsan", 17, 700},
		{"lisi", 18, 670},
		{"wangwu", 16, 720}
	};

	memset(stu_array, 0, sizeof(stu_array));

	// 1.2结构体数组的使用
	// 首先通过下标找到指定位置的数组元素
	// 然后通过.引用结构体成员进行其他数据运算操作
	stu_array[0].age = 18;
	stu_array[1].score = 600;
	strcpy(stu_array[2].name, "jerry");

	printf("sizeof(struct student) : %ld\n",
			sizeof(struct student));

	// 2.结构体指针
	// 指向结构体变量的指针
	student_t stu;
	student_t *p_stu = NULL;

	// 2.1对结构体指针进行赋值操作
	// 该地址所对应的空间必须合法
	p_stu = &stu;

	// 2.2使用结构体指针访问结构体成员
	// 使用->
	p_stu->age = 18;
	p_stu->score = 666;
	strcpy(p_stu->name, "lili");

	return 0;
}

// 思考题：如何定义一个函数，能够向传入的结构体变量输入数据
void input_stu_info(student_t *p_stu);









#include <string.h>
#include <stdio.h>

#define MAX_NAME_LEN 50

// 定义结构体类型并为其定义别名
typedef struct student
{	
	char name[MAX_NAME_LEN];
	int age;
	int linux_score;
	int c_score;
}student_t;

#if 0
struct student
{
	char name[MAX_NAME_LEN];
	int age;
	int score;
};
// 类型别名
typedef struct student student_t;
#endif

int main(int argc, char *argv[])
{
	//struct student stu;
	// 1.定义学生结构体变量
	student_t stu;

	memset(&stu, 0, sizeof(stu));

	// 2.从键盘读入学生信息
	printf("name : ");
	scanf("%s", stu.name);
	printf("age : ");
	scanf("%d", &stu.age);
	printf("linux_score : ");
	scanf("%d", &stu.linux_score);
	printf("c_score : ");
	scanf("%d", &stu.c_score);

	// 3.打印输出学生的平均成绩
	printf("average score of stu : %f\n", 
			(stu.linux_score+stu.c_score)/2.0);

	return 0;
}






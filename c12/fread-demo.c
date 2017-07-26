#include <stdio.h>
#include <string.h>

// 使用fread/fwrite进行结构体数组的读写
typedef struct student
{
	int id;
	char name[20];
	int score;
}student_t;;

int main(int argc, char *argv[])
{
	student_t stus[3] = {
		{1, "lucy", 100},
		{2, "lily", 120},
		{3, "tom", 110}
	};

	// 1.fopen
	FILE *fp = fopen("result.data", "a");

	printf("press any key to continue...\n");
	getchar();

	// 2.fread/fwrite
	//fwrite(stus, sizeof(student_t), 3, fp);
	fwrite(stus,
		sizeof(stus[0]),
		sizeof(stus)/sizeof(stus[0]),
		fp);

	// 3.fclose
	fclose(fp);

	return 0;
}









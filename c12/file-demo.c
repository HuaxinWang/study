#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *str = "wo ai beijing tian'an men";

	// 1.打开文件
	FILE *fp = fopen("hello.txt", "w");
	if(fp == NULL)
	{
		perror("fopen error");
		return 1;
	}

	// 2.读写文件
	// 向该文件中写入"wo ai beijing tian'an men"
	fputs(str, fp);
	fputs(str, fp);
	fputs(str, fp);

	// 3.关闭文件
	fclose(fp);

	return 0;
}

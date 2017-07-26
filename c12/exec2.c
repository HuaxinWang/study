// 使用fgetc/fputc完成文件的复制

#include <stdio.h>
#include <string.h>

#define DATA_SIZE 100

// ./exec src_file dst_file

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s src_file dst_file\n", argv[0]);
		return 1;
	}

	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;
	char data[DATA_SIZE] = {'\0'};
	char *src_file = argv[1];
	char *dst_file = argv[2];
	int ch = 0;

	// 1.打开文件
	src_fp = fopen(src_file, "r");
	if(src_fp == NULL)
	{
		perror("fopen src file");
		return 1;
	}
	if((dst_fp = fopen(dst_file, "w")) == NULL)
	{
		perror("fopen dst file");
		return 1;
	}

	// 2.操作数据
	while(1)
	{
		memset(data, 0, DATA_SIZE);

		// 读
		ch = fgetc(src_fp);

		// 判断
		if(ch == EOF)
			break;

		// 写
		fputc(ch, dst_fp);
	}

	// 3.关闭文件
	fclose(src_fp);
	fclose(dst_fp);

	return 0;
}







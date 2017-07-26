#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

// 使用文件操作，模拟实现cp命令
// ./a.out source_file dest_file
// argv[0] ----> ./a.out
// argv[1] ----> source_file
// argv[2] ----> dest_file

int main(int argc, char *argv[])
{
	// 判断命令行参数是否满足要求
	if(argc != 3)
	{
		printf("Usage : %s source_file dest_file\n",
				argv[0]);
		return 1;
	}

	char buf[BUFFER_SIZE] = {'\0'};
	FILE *src_fp = NULL;
	FILE *dst_fp = NULL;

	// 1.1以只读的方式打开source_file
	if((src_fp = fopen(argv[1], "r")) == NULL)
	{
		perror("fopen src file");
		return 1;
	}
	// 1.2以只写的方式打开dest_file
	if((dst_fp = fopen(argv[2], "w")) == NULL)
	{
		perror("fopen dst file");
		return 1;
	}

	// 2.1循环的从源文件中读取数据
	// 2.2将读到的数据写入到目的文件
	// 重复上两个操作直到读到源文件的尾部为止
	while(1)
	{
		memset(buf, 0, BUFFER_SIZE);

		// 从源文件中读数据
		fgets(buf, BUFFER_SIZE, src_fp);

		//　判断是否读到了数据 
		if(strlen(buf) == 0)
			break;

		// 将读到的数据写入到目的文件中
		fputs(buf, dst_fp);
	}

	// 3.关闭文件
	fclose(src_fp);
	fclose(dst_fp);

	return 0;
}

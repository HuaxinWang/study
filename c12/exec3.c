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
	int n = 0;

	// 1.fopen
	src_fp = fopen(src_file, "r");
	dst_fp = fopen(dst_file, "w");

	// 2.fread/fwrite
	while(1)
	{
		n = fread(data, sizeof(char), DATA_SIZE, src_fp);

		if(n == 0)
			break;
		
		fwrite(data, sizeof(char), n, dst_fp);
	}

	// 3.fclose
	fclose(src_fp);
	fclose(dst_fp);

	return 0;
}

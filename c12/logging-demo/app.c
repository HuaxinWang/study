#include <stdio.h>
#include <stdlib.h>
#include "logging.h"

int main(int argc, char *argv[])
{
	int no = 0;

	while(1)
	{
		printf("日志模拟系统 V1.0\n");
		printf("1.模拟正常操作\n");
		printf("2.模拟错误操作\n");
		printf("0.退出模拟系统\n");
		printf("输入模拟的操作编号: ");
		scanf("%d", &no);

		switch(no)
		{
			case 1:
				logging_for_level(LOG_LEVEL_NORMAL, "test normal message");
				break;
			case 2:
				logging_for_level(LOG_LEVEL_ERR, "test error message");
				break;
			case 0:
				exit(0);
				break;
			default:
				break;
		}
	}
}

#include "logging.h"
#include <stdio.h>
#include <time.h>

void logging_for_level(log_level_t level, char *log)
{
	switch(level)
	{
		case LOG_LEVEL_ERR:
			logging_error(log);
			break;
		case LOG_LEVEL_NORMAL:
			logging_normal(log);
			break;
		default:
			break;
	}
}

static void logging_error(char *log)
{
	char buf[512] = {'\0'};

	// 1.以追加的方式打开文件
	FILE *fp = fopen(ERR_LOG_PATH, "a");
	if(fp == NULL)
		return;

	// 2.构造字符串
	sprintf(buf, "[ERROR] %s sq: %s\n", ctime(NULL), log);

	// 3.将字符串写入文件
	fputs(buf, fp);

	// 4.关闭文件
	fclose(fp);
}

static void logging_normal(char *log)
{
	char buf[512] = {'\0'};

	// 1.以追加的方式打开文件
	FILE *fp = fopen(NORMAL_LOG_PATH, "a");
	if(fp == NULL)
		return ;

	// 2.构造字符串
	sprintf(buf, "[NORMAL] %s sq: %s\n", ctime(NULL), log);

	// 3.将字符串写入文件
	fputs(buf, fp);

	// 4.关闭文件
	fclose(fp);
}







#ifndef __LOGGING_H__
#define __LOGGING_H__

#define ERR_LOG_PATH "/var/log/my_test_logging.err"
#define NORMAL_LOG_PATH "/var/log/my_test_normal.log"

typedef enum log_level
{
	LOG_LEVEL_ERR = 100,
	LOG_LEVEL_NORMAL = 200
}log_level_t;

// 根据日志系统的级别完成日志的记录
void logging_for_level(log_level_t level, char *log);

static void logging_error(char *log);

static void logging_normal(char *log);

#endif

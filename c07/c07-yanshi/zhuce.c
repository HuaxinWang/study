#include <stdio.h>

int main()
{
	char name[20] = {'\0'};
	char passwd[20] = {'\0'};
	//字符串结束标志，'\0'
	printf("请输入用户名:");
	scanf("%s",name);
	while(getchar() != '\n');
	printf("请输入密码:");
	gets(passwd);
	//
	//	自己写字符串接收
	//  限制最大长度
	//	过短	
	//	过长
	//  
	//  加'\0'
	// name[20]
	// 19'\0'

	printf("name:%s\npasswd:%s\n",name,passwd);

	return 0;
}

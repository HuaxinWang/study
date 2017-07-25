#include<stdio.h>

int main()
{
	char ch = '\0';
	printf("请输入一个字母:");
	scanf("%c",&ch);
	getchar();

	if(ch >= 97 &&ch <= 122)
	{
		printf("这个字母对应的大写字母为:%c\n",ch - 32);
	}
	else if(ch >= 65 &&ch <= 90)
	{
		printf("这个字母对应的小写字母为:%c\n",ch + 32);
	}
	else
	{
		printf("无效输入!");
	}




	return 0;
}

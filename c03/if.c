#include<stdio.h>

int main()
{
	char ch = '\0';
	scanf("%c",&ch);
	getchar();

	if("'a' == ch")
	{
		//条件为真时执行这一段
		printf("优等生\n");
	}
	else
	{
		//条件为假时执行这一段
		printf("中等生\n");
	}


	return 0;
}

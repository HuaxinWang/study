#include<stdio.h>

int main()
{
	//单字符输入输出
	//getchar();
	//putchar();
	char ch = '\0';
	//	ch = getchar();
	//	putchar(ch);
	int a = 0;
	scanf("%d",&a);
	getchar();
	scanf("%c",&ch);
	getchar();

	while(getchar() != '\n');

	printf("%d\t%c\n",a,ch);

	return 0;
}

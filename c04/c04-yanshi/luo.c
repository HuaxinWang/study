#include <stdio.h>

int main()
{
	//逻辑运算符
	//　串联两个或两个以上的判断表达式，最终的结果，为几个表达式的整体结果
	// &&	与	并且 　所有的判断表达式都为真，整体才为真
	// ||	或	或者	所有的判断表达式，只要有一个为真，整体就是真
	// !	非	不是	如果表达式为真，则整体为假，若果表达式为假，则整体为真
/*	
	char ch = '\0';
	printf("1-->剪刀\n2-->石头\n3-->布\n请输入你的选择:");
	scanf("%c",&ch);
	getchar();
	srand((unsigned)time(NULL));
	int com = rand()%3 + 1;

	if(('1' == ch && 1 == com) || ('2' == ch && 2 == com) || (3 == com && '3' == ch)){
		printf("平局\n");
	}else if('1' == ch && 2 == com){
		printf("电脑胜利\n");
	}else if('1' == ch && 3 == com){
		printf("玩家胜利\n");
	}
*/
	//练习题：
	// 要求用户输入一个字母，如果这个字母是小写，输出对应的大写，如果是大写，输出对应的小写
	//   97 <= ch <= 122
/*	
	char ch = '\0';
	printf("请输入一个英文字符:");
	scanf("%c",&ch);
	getchar();

	// float
	// 69.666667

	if(ch > 96 && ch < 123){
		printf("%c\n",ch - 32);
	}else if(ch >= 65 && ch <= 90){
		printf("%c\n",ch + 32);
	}else{
		printf("输入不合法\n");
	}
*/
	// 96<ch<123
	// 判断闰年
	//　已知：如果一个年份能够被４整除，并且不能被１００整除，或者能够４００整除，这是闰年，否则就是平年

	int year = 2000;
	printf("请输入一个年份:");
	scanf("%d",&year);
	getchar();

	year%4 == 0 && year%100!=0 || year%400 == 0?printf("闰年\n"):printf("平年\n");

/*
	if((year%4 == 0 && year%100 != 0) || year%400 == 0){
		printf("闰年\n");
	}else{
		printf("平年\n");
	}
*/











}

#include<stdio.h>

int main()
{
//	int a = 20;
//	char ch = 'a';
	//010101
	//编码表 ASCII码表
	// "中"
	// utf-8
	// gbk
	// gb2313
	//
	// a -- 97
	// b -- 98
	// char int
	// 
	// 0---127
	//
	// A-Z	65 -- 90
	// a-z	97 -- 122
	// 0-9  48 - 57
	//'A' --> 65
	// 2 + 2     4
	// '2' + 2	 52 '4'
	// '2' + '2' 100 'd'

/*
	int a = 0;
	float age = 20;
	char ch = '\0';
	char sex = 'f';
	char ch = '\0';

	char ASCII
	
*/

//	char ch = 'a';

//	printf("%d,%c",ch,ch);

	//要求用户输入一个小写字母，
	//输出对应的大写字母

	char ch = '\0';
	printf("请输入一个小写字母:");
	scanf("%c",&ch);
	printf("对应的大写字母是:%c\n",ch - 32);

	//转义字符 转义序列
	//	* ? " ' %
	//	\n  回车 
	//	\t	tab键
	//	\r  换行
	//	\\	\
	//  \"	"
	//	\'	'
	//  ??
	//	%%
	
	
	// 类型转换，类型补遗
	



	return 0;
}


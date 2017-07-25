#include<stdio.h>
int main()
{	
	//定义两个字符变量
	char ch = '\0';
	char ch1 = '\0';
	printf("请输入一个小写字母:");
	//输入
	scanf("%c",&ch);
	//小写转大写
	ch1 = ch - 32;
	//输出
	printf("对应的大写字母为:%c\n",ch1);
	//转义字符　转义序列
	//　*　? " ' %
	//  \n 回车
	//　\t tab键
	//  \r 换行
	//  \\ \
	//  \" "
	//  \' '
	//  ?? ?
	//  %% %


	return 0;
}

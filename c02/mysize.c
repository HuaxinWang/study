#include <stdio.h>

int main()
{
	//定义变量
	int sizeInt = sizeof(int);
	int sizeFloat = sizeof(float);
	int sizeDouble = sizeof(double);
	int sizeChar = sizeof(char);
	//输出各种数据类型在内存中所占空间
	printf("各种数据类型在内存中所占空间为:\nint:%d\nfloat:%d\ndouble:%d\nchar:%d\n",sizeInt,sizeFloat,sizeDouble,sizeChar);
	return 0;
}

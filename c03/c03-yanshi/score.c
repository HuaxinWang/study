#include<stdio.h>

int main()
{
	float s1=80,s2=80,s3=80;
	float sum;
	printf("请输入三个成绩:");
	scanf("%f%f%f",&s1,&s2,&s3);
	sum = s1 + s2 + s3;
	float aver = sum / 3;
	printf("总分是:%10.2f,平均分是:%d",s1 + s2 + s3,aver);
	//int
	// float/int = 
	// float
	// '2' + 2 = 
	// int 
	// %10d
	//123
	//      123
	//控制printf输出的宽度
	//19.980000
	//%.2f 19.98  5
	//%10.2f
	//     19.98
	//
	//98.500000
	return 0;
}

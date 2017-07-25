#include <stdio.h>
 
int main()
{
	//指针
	// 指针类型
	// 指针 -> 指针类型的变量
	// 存储  地址
	
	// * p = 0x100000;
	// char 1byte 
	// int 4byte
	// 0x100 0x101 0x102 0x103
	// long 
	// 0x100
	// char * p = 0x1000
	// int a

	//
/*
	int a = 20;
	int * p = &a;	// 告诉系统，这是一个指针类型
	printf("%p\n",p);
	//
	// a = 20;  0x5ff7c7d345
	// p = 0x5ff7c7d345

	printf("%d\n",*p); //间接引用符
	*p = 30;
	printf("%d\n",a);
	int b = 50;
	p = &b;
	printf("%d\n",*p);
*/
/*
	int a = 20;
	int b = 30;
	int *p1 = &a;
	int *p2 = &b;

	*p1 = *p2;
	//a = 30 b = 30
	(*p1)++;
	//a = 31 b = 30
	p1 = p2;
	//a = 31 b = 30      p1 = &b   p2 = &b
	*p1 = *p1 + *p2;
	//a = 31 b = 60;
	p2 = &a;
	//p1 = &b  p2 = &a
	*p2 = *p1;
	//a = 60 b = 60

	printf("%d\t%d\n",a,b);
	// a = 
	
	int * p = NULL;
*/


	int a = 20;
	int * p = &a;
	printf("a的地址%p\np的内容:%p\np的地址:%p\n",&a,p,&p);
	int ** p1 = &p;
	//指针的指针
	//二级指针
	printf("p1的内容:%p\n",p1);
	printf("a的值:%d\n",**p1);
	printf("%d\n",*&a);


	













	









	
	

	return 0;
}

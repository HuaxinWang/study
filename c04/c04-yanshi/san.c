#include <stdio.h>

int main()
{
	//
	//a++;
	//a + b;
	//?:
	int a = 20;
	int b = 30;
	int c = 0;
	/*if(a > b)
	{
		printf("%d",a);
		c = a;
	}else{
		printf("%d",b);
		c = b;
	}
	*/
	//c = a > b ? a : b;
	// 判断表达式　? 判断表达式成立时　: 判断表达不成立
	//a > b ? printf("%d\n",a) : printf("%d\n",b);
	// a = 20 b = 30
	a > b? a++ : b++;
	c = (a++,b++);
	//a = 21
	//b = 32
	//c = 31
	// c = a++ , b++
	// c = b
	// b = b + 1;
	 // c = b
	// a = a + 1;
	// b = b + 1;
	//,运算符 取值是右边的值
	// 但是左右的表达式都会运行
	//,优先级最低
	// a = 21 b = 31 c = 30

	printf("a:%d b:%d c:%d\n",a,b,c);

	
	return 0;
}

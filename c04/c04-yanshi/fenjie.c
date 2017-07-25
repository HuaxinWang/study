#include <stdio.h>

int main()
{
	//要求用户输入一个五位数字；
	//倒序输出
	//12345
	//54321
	//12321   34543
	//
	//
	// 12321%10 = 1
	// 12321/10 = 1232
	
	// 1232%10 = 2
	// 1232/10 = 123

	// 123%10 = 3
	// 123/10 = 12
	
	//12%10 = 2
	//12/10 = 1
	
	//1%10 = 1
	//1/10 = 0
	printf("请输入一个5位数字:");
	int num;
	int yu;
	scanf("%d",&num);
	int i = 0;
	/*
	for(i = 0 ; i < 5 ; i++)
	{
		yu = num%10;
		num = num / 10;
		printf("%d",yu);
	}
	*/
	//while()
	/*
	while(1)
	{
		yu = num%10;
		num = num/10;
		printf("%d",yu);
		if(num == 0){
			break;
		}
	}
	*/
	while(num != 0)
	{
		yu = num % 10;
		num = num / 10;
		printf("%d",yu);
	}







	return 0;
}

#include<stdio.h>
#include<stdlib.h>

int main()
{
	float num1,num2,result;
	char ch = '\0';
	printf("请输入算式:");
	scanf("%f%c%f",&num1,&ch,&num2);
	getchar();
	switch(ch)
	{
		case '+':
			result = num1 + num2;
			break;
		case '-':
			result = num1 - num2;
			break;
		case '*':
			result = num1 * num2;
			break;
		case '/':
			if(num2 == 0)
			{
				printf("除数不能为0\n");
				exit(-1);
			}else{
				result = num1 /num2;
			}
			break;
		default:
			printf("程序不接受这种表达式\n");
			exit(-1);
			

	}
	printf("计算结果为:%f%c%f=%f\n",num1,ch,num2,result);


	return 0;
}

#include<stdio.h>

void change(int *num1,int *num2);
int main()
{
	int a,b;
	scanf("%d\t%d",&a,&b);
	while(getchar() != '\n');
	change(&a,&b);
	printf("%d\t%d\n",a,b);


	return 0;
}
void change(int *num1,int *num2)
{
	int temp = 0;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

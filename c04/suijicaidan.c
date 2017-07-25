#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{	
	//将时间设置为随机数种子
	//整个程序中只要有一次就好
	srand((unsigned)time(NULL));
	
	//打印菜单
	int index = 0;
	printf("1-->小馄饨\n");
	printf("2-->粉丝汤\n");
	printf("3-->饺子\n");
	printf("4-->自己做\n");
	printf("5-->不吃饭了\n");
	printf("\n\n\n产生结果:");

	//产生随机数
	index = rand()%5 + 1;//0--4
	
	switch(index)
	{
		case 1:
			printf("1-->小馄饨\n");
			break;
		case 2:
			printf("2-->粉丝汤\n");
			break;
		case 3:
			printf("3-->饺子\n");
			break;
		case 4:
			printf("4-->自己做\n");
			break;
		case 5:
			printf("5-->不吃了\n");
	
	
	}

	return 0;
}

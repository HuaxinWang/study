#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand((unsigned)time(NULL));

	int index1,index2;
	printf("1代表剪刀\n");
	printf("2代表石头\n");
	printf("3代表布\n");
	printf("-------------\n");
	printf("你想要出什么?(输入1,2,3表示):");
	scanf("%d",&index1);

	index2 = rand()%3 +1;
	
	switch(index1)
	{
		case 1:
			printf("你出的是剪刀!\n");
			if(index2 = 1)
			{
				 printf("机器出的是剪刀!\n----你们平手!\n");
			}
			else if(index2 = 2)
			{
				printf("机器出的是石头!\n----你输了!\n");
			}
			else if(index2 = 3)
			{
				printf("机器出的是布!\n----你赢了!\n");
			}
			break;
		case 2:
			printf("你出的是石头!\n");
			if(index2 = 1)
			{
				 printf("机器出的是剪刀!\n----你赢了!\n");
			}
			else if(index2 = 2)
			{
				printf("机器出的是石头!\n----你们平手!\n");
			}
			else if(index2 = 3)
			{
				printf("机器出的是布!\n----你输了!\n");
			}
			break;
		case 3:
			printf("你出的是布!\n");
			if(index2 = 1)
			{
				 printf("机器出的是剪刀!\n----你输了!\n");
			}
			else if(index2 = 2)
			{
				printf("机器出的是石头!\n----你赢了!\n");
			}
			else if(index2 = 3)
			{
				printf("机器出的是布!\n----你们平手!\n");
			}
	
	}
	





	return 0;
}

#include <stdio.h>

int main()
{
	int flag = 1;
	while(flag)
	{
		printf("1-->红烧猪蹄\n2-->肉末茄子\n3-->西红柿炒蛋\n4-->全要\nq-->结束点菜\n请输入你的选择:");
		char ch = '\0';
		scanf("%c",&ch);
		getchar();
		switch(ch){
			case '1':
				printf("点了一个菜\n");
				break;
			case '2':
				printf("点了一个菜\n");
				break;
			case '3':
				printf("点了一个菜\n");
				break;
			case 'q':
				flag = 0;
		}


/*		
		if(ch == 'q')
		{
			break;
		}
*/	
		/*
		if(ch == '1'){
			printf("点了一个菜\n");
		}else if(ch == '2'){
			printf("点了一个菜\n");
		}else if(ch == '3'){
			printf("点了一个菜\n");
		}else if(ch == '4'){
			printf("点了一个菜\n");
		}else if(ch == 'q'){
			break;
		}
		*/
	}
	return 0;
}

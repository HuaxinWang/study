#include <stdio.h>

int main()
{
	int num = 0;
	int j = 0;
	int flag = 1;
	for( num = 1 ; num < 101 ; num++)
	{
		flag = 1;
		for( j = 2; j < num ; j++)
		{
			if( num % j == 0)
			{
				flag = 0;
			}
		}
		if( 1==flag)
		{
			printf("%d\n",num);
		}
	}
	return 0;
}

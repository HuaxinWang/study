#include <stdio.h>
 
int main()
{
	int a[5] = {0};
	int * p = a;
	int i = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		scanf("%d",p + i);
	}
	int sum = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		sum += p[i];
	}
	printf("%d\n",sum/5);
	return 0;
}

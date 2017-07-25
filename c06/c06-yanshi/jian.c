#include <stdio.h>
 
int main()
{
	int arr[5] = {0};
	int i = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		scanf("%d",&arr[i]);
		while(getchar() != '\n');
	}
	int j = 0;
	int max = arr[0];
	int mi = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		max = arr[i];
		mi = i;
		for(j = i ; j < 5 ; j++)
		{
			if(max < arr[j])
			{
				max = arr[j];
				mi = j;
			}
		}
		int tmp = arr[mi];
		arr[mi] = arr[i];
		arr[i] = tmp;
	}

	for(i = 0 ; i < 5; i++)
	{
		printf("%d\t",arr[i]);
	}
	putchar('\n');

	return 0;
}

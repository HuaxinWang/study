#include <stdio.h>

int main()
{
	int arr[5];
	
	int i = 0;
	for(i = 0 ; i < 5 ; i++)
	{
		scanf("%d",&arr[i]);
		while(getchar() != '\n');
	}

	int max = arr[0];
	for(i = 0 ; i < 50 ; i++)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}
		arr[i] = 123;
	}
	printf("%d\n",max);




	return 0;
}

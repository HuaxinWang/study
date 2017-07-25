#include <stdio.h>

int main(int argc, char *argv[])
{
	int nums[10] = {11,22,33,44,55,66,77,88,99,0};
	int no = 0;
	int i = 0;

	printf("befor delete : \n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	printf("input index you want to del : ");
	scanf("%d", &no);

	for(i = no; i < 10-1; i++)
	{
		nums[i] = nums[i+1];
	}

	printf("after delete : \n");
	for(i = 0; i < 10; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	return 0;
}

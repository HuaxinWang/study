#include<stdio.h>

int mystrlen(char *arr,int size);
int main()
{
	char name[5] = {1,2,3,4};
	int sum = mystrlen(name,5);
	printf("有效位数为:%d\n",sum);





	return 0;
}
int mystrlen(char *arr,int size)
{
	int i = 0;
	int count = 0;
	for(i = 0;i < size;i++)
	{
		if(arr[i] != '\0')
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

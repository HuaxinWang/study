#include<stdio.h>

int main()
{
	char name[20];
	scanf("%s",name);
	printf("%s\n",name);
	int count = 0;
	int i = 0;
	while(1)
	{
		if(name[count] != '\0')
		{
			count++;
		}
		else
		{
			break;
		}
	}
	printf("%d\n",count);
	
	return 0;
}

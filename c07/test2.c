#include<stdio.h>

int main()
{
	char name[20] = {'\0'};

	int i = 0;
	for(i = 0;i < 19;i++)
	{
		name[i] = getchar();
		if(name[i]  == '\n')
		{
			break;
		}
	}
	name[i] = '\0';
	if(i == 19)
	{
		while(getchar() != '\n');
	}
	printf("%s\n",name);
	return 0;
}

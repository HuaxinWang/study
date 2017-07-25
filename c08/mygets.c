#include<stdio.h>

void mygets(char *str,int size);

int main()
{
	char str[10];
	mygets(str,10);
	printf("%s\n",str);

	return 0;
}
void mygets(char *str,int size)
{
	int i = 0;
	for(i = 0;i < size-1;i++)
	{
		str[i] = getchar();
		if(str[i] == '\n')
		{
			break;
		}
	}
	str[i] = '\0';
	if(i == size-1)
	{
		while(getchar() != '\n');
	}
}

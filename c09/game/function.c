#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void myGets(char *str,int size)
{
	int i = 0 ;
	for(i = 0 ; i < size -1 ; i++)
	{
		str[i] = getchar();
		if(str[i] == '\n')
		{
			break;
		}
	}
	str[i] = '\0';
	if(i == size -1)
	{
		while(getchar() != '\n');
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char passwd1[15];
	char passwd2[15];
	gets(passwd1);
	gets(passwd2);
	if(strlen(passwd1) == strlen(passwd2))
	{
		int i = 0;
		for(i = 0;i < 15;i++)
		{
			
			if(passwd1[i] != passwd2[i])
			{
				printf("不相等\n");
				exit(1);
			}
		
		}
		printf("相等\n");
		exit(1);
	}
	else
	{
		printf("不相等\n");
	}


	return 0;
}

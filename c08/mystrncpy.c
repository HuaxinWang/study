#include<stdio.h>
void mystrncpy(char *str1, char *str2,int size);
int main()
{
	str1
	mystrncpy(str1,str2,20);
	printf("%s\t%s\n",str1,str2);
	
	return 0;
}
void mystrncpy(char *str1,char *str2,int size)
{
	int i = 0;
	for(i = 0;i < size && str2[i] != '\0';i++)
	{
		str1[i] = str2[i];
	}
	str1[i] = '\0';
}

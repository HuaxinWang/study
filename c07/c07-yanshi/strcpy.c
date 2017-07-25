#include <stdio.h>
#include <string.h>

int main()
{
	/*
	char str1[10] = "hello";
	char str2[20] = "world";

	strcpy(str1,str2);
	printf("str1:%s\n",str1);
	printf("str2:%s\n",str2);
	*/
	//实现功能
	//解决越界问题

	//gets()
	//scanf()		
	//strlen()		
	// sizeof()
	// strcmp(s1,s2)  strncmp
	// strcat()		  strncat
	// strcpy()		  strncpy
	// sprintf();
	// name20

	char name[20] = "jack";
	int age = 40;
	char result[50];
	sprintf(result,"姓名:%s,年龄:%d",name,age);
	printf("%s\n",result);









	return 0;
}

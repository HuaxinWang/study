#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	//
	char passwd1[15];
	char passwd2[15];
	
	scanf("%s",passwd1);
	while(getchar() != '\n');
	scanf("%s",passwd2);
	while(getchar() != '\n');


	int i = 0;
	if(strlen(passwd1) != strlen(passwd2))
	{
		printf("不一致\n");
		exit(1);
	}
	for(i = 0 ; i < strlen(passwd1) ; i++)
	{
		if(passwd1[i] != passwd2[i])
		{
			printf("不一致\n");
			exit(1);
		}
	}
	printf("一致\n");





	
	
	//gets(passwd1)
	//scanf("%s",passwd2);

	//char name[20];
	// hello'\0'sdfjksaldjfk
	//gets(name)		没有边界检查
	//scanf("%s",name);	残留回车，字符串不能有空格，没有边界检查
	//mygets
	//hello\0
	//strlen(name)
	//




	return 0;
}





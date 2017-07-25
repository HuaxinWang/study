#include <stdio.h>
#include <string.h>
int main()
{
	char passwd1[20];
	char passwd2[20];
	scanf("%s",passwd1);
	while(getchar() != '\n');
	scanf("%s",passwd2);
	while(getchar() != '\n');
	
	if(strcmp(passwd1,passwd2) == 0)
		printf("一致\n");
	else
		printf("不一致\n");

	//gets()
	//scanf("%s",name)
	//strlen
	//strcmp
	//strcat
	//




	return 0;
}

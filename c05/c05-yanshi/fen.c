#include <stdio.h>

int main()
{
	char ch1 = '\0';
	char ch2 = '\0';
	char tmp = '\0';
	// \n
	scanf("%c",&ch1);
	while(getchar() != '\n');

/*	while(tmp != '\n')
	{
		tmp = getchar();
	}
*/
	scanf("%c",&ch2);
	printf("%c\t%c\n",ch1,ch2);
	
}

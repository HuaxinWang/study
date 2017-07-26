#include <stdio.h>

int main(int argc, char *argv[])
{
	char buffer1[10] = {'\0'};
	char buffer2[10] = {'\0'};
	char buffer3[10] = {'\0'};

	printf("input buffer2 : ");
	gets(buffer2);

	printf("buffer1 : %s\n", buffer1);
	printf("buffer2 : %s\n", buffer2);
	printf("buffer3 : %s\n", buffer3);

	return 0;
}

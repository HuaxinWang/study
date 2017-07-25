#include <stdio.h>
#include <string.h>
int main()
{	
	char dest[10] = "hello ";
	char src[15] = "world sddf!!!!!";
	strcat(dest,src);
	printf("%s\n",dest);
	printf("%s\n",src);
	// hello world!!!!
	// 
	// hello world sddf!!!!!!
	// !!!!!
	dest[6] = "hello";
	src[10] = "worldaassdd"


	//实现strcat的功能
	//实现strcat的功能,解决越界的问题
	



	return 0;
}

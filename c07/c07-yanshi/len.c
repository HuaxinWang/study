#include <stdio.h>
#include <string.h>
int main()
{
	char name[20];
	scanf("%s",name);
	printf("%s\n",name);
	
	// \0
	int count = 0;
	
	while(1)
	{
		if(name[count] != '\0')
		{
			count++;
		}else{
			break;
		}
	}
/*
	while(name[count] != '\0'){
		count++;
	}
*/
	//jack
	strlen(name); //4
	sizeof(name); //20

	int len = strlen(name);
	printf("%d\n",len);


	return 0;
}

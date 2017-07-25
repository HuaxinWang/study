#include <stdio.h>

int main()
{
	//字符串 实现基于字符数组
	// 区别
	// 字符串有有效字符
	// 字符串结束标志 '\0'
	// 20
	//	jack\0
	//	tom\0
	//  sadfsdf\0
	//bytearray
	//字符数组
	char str[20] = {'h','e','\0','l','l','o'};
	printf("%s\n",str);
	//声明字符串,就是声明一个字符数组
	char name[20];
	//jack
	int i = 0;
	/*
	for(i = 0 ; i < 4 ; i++)
	{
		scanf("%c",&name[i]);
	}
	*/
	while(1)
	{
		char ch = getchar();
		if(ch != '\n')
		{
			name[i] = ch;
		}else{
			break;
		}
		i++;
	}
	name[i] = '\0';

	//scanf
	//scanf("%s",name);
	//gets(name);
	printf("%s\n",name);



	return 0;
}

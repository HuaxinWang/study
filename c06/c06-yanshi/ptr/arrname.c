#include <stdio.h>
 
int main()
{
	int arr[5] = {5,4,3,2,1};
	int * p = &arr[0];
	printf("arr:%p\n,p:%p\n",arr,p);
	// arr == &arr[0]
	// p 指针变量
	// arr 地址常量
	// *(arr + i)
	// *(p + i)
	// arr[i]
	// p[i]
	// *(p++)
	int i = 0;
	for(i = 0 ; i< 5 ; i++)
	{
		printf("%d\n",*(arr++));
	}
	


	return 0;
}

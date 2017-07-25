#include <stdio.h>
 
int main()
{
	// int a = 20;
	// int * p = &a;
	// *p == a
	// int* *p1 = &p
	// **p
	
	//p = &a;
	//
	//
	int arr[5] = {8,2,9,4,1};
	int *p = &arr[0];
	/*
	printf("%d\n",*p);
	//p 1byte
	//  4
	// 0x100 - 0x103  0x104
	// p + 1
	// p + 4
	
	int * p1 = p + 1;
	int * p2 = p + 4;
	p + 1*(sizeof(int))
	printf("p1:%d\tp2:%d\n",*p1 , *p2);
	*/
	// arr == p == &arr[0];
	//arr[i]
	//p[i]
	printf("%p\n",arr);
	printf("%p\n",p);
	printf("%p\n",&arr[0]);
	int i = 0;
	for(i = 0 ; i < 5; i++)
	{
//		printf("%d\n",arr[i]);
//		printf("%d\n",i[p]);
//		printf("%d\n",p[i]);
		printf("%d\n",*(arr+i));
		//p[i]
		// *(p + i)
		// p[i]
		// *(arr + i)
		// arr[i]
		// *(i + p)
		// i[p]
		printf("%d\n",*(p + i));
		//*(p + 0)
		//*(p + 4)
		//
	}










	return 0;
}





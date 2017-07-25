#include<stdio.h>

int main()
{
	int a = 0;
	char ch = 'a';
	char swp = '\n';


	scanf("%c",&ch);	//\n
	scanf("%c",&swp);	//\n  !!!

	scanf("%d",&a);	//20 \n
	scanf("%c",&swp);	// \n	!!!
	printf("%d %c\n",a,ch); 
	return 0;
}














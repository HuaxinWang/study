#include <stdio.h>

int main()
{
	int tmp = 0;
	int z = 0;
	int f = 0;
	int i = 0;
	for(i = 0 ; i < 10 ; i++){
		scanf("%d",&tmp);
		if(tmp > 0){
			z += tmp;
		}else{
			f += tmp;
		}
	}

	printf("正数:%d\t负数:%d\n",z,f);
	return 0;
}

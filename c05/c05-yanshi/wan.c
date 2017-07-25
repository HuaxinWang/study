#include <stdio.h>

int main()
{
	int year = 1900 , month = 1;
	while(1){
		printf("please input date:");
		scanf("%d%d",&year , &month);
		if(year < 1900 || month < 1 || month > 12){
			printf("date error!\n");
		}else{
			break;
		}
	}
	//1900 1 1 -- 2016 12 31
	//2017 1 1 -- 2017 6 30 
	//2017 7 1
	int i = 0;
	int sum = 0;
	for(i = 1900 ; i < year ; i++)
	{
		if(i%4 == 0 && i%100 != 0 || i%400 == 0)
		{
			sum += 366;
		}else{
			sum += 365;
		}
	}

	int day = 0;
	for(i = 1 ; i <= month ; i++)
	{
		switch(i)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				sum += 31;
				day = 31;
				break;
			case 2:
				if(year%4 == 0 && year%100 != 0 || year%400 == 0){
					sum += 29;
					day = 29;
				}else{
					sum += 28;
					day = 28;
				}
				break;
			default:
				sum += 30;
		}
	}
	sum -= day;
	int week = 0;
	week = sum % 7 + 1;

	printf("sun\tmon\ttues\twed\tthur\tfir\tsat\n");
	for(i = 0 ; i < week ; i++)
	{
		printf(" \t");
	}
	for(i = 1 ; i <= day ; i++)
	{
		printf("%d\t",i);
		if((i + week)%7 == 0)
		{
			printf("\n");
		}
	}

	printf("\n");


}

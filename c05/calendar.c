#include<stdio.h>

int main()
{
	int year,month;
	int day;
	int weekday;
	int allday = 0;
	int monthDay;
	int i = 1900;
	int m = 1;
	printf("请输入您想要查询的年月日,用空格隔开:");
	scanf("%d%d%d",&year,&month,&day);
	getchar();
	for(i = 1900;i < year;i++)
	{
		if(i % 4 ==0 && i % 100 !=0 || i % 400 == 0)
		{	
			allday += 366;		
		}
		else
		{
			allday += 365;
		}
	}	
	for(m = 1;m < month;m++)
	{
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			allday += 31;
		}
		else if(m==4||m==6||m==9||m==11)
		{
			allday += 30;

		}
		else if(m==2&&(i % 4 ==0 && i % 100 !=0 || i % 400 == 0))
		{
			allday += 29;
		}
		else if(m==2&&(i % 4 !=0 && i % 100 ==0 || i % 400 != 0))
		{
			allday += 28;
		}
	
	}
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			monthDay = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			monthDay = 30;
			break;
		case 2:
			if(i % 4 ==0 && i % 100 !=0 || i % 400 == 0)
			{
				monthDay = 29;
			}
			else if(i % 4 !=0 && i % 100 ==0 || i % 400 != 0)
			{
				monthDay = 28;
			}
	}
	weekday = (allday + 1) % 7;
	printf("你要查询的是%d年%d月%d日\n",year,month,day);
	printf("\n周日\t周一\t周二\t周三\t周四\t周五\t周六\n");
	int n;
	for(n=0;n<weekday;n++)
	{
		printf(" \t");
	}
	int j;
	for(j=1;j<=monthDay;j++)
	{
		printf("%d\t",j);
		n++;
		if(n%7==0)
		{
			printf("\n");
		}

	}
	printf("\n");







	return 0;
}

/*
 ============================================================================
 Name        : calendar.c
 Author      : Shouvik Banik
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void main()
{
	char c,s[10];
	int i=0,choice=0,j=0,count,cal[5][7],max,flag=0,bdate=2,bmonth=9,byear=1996,leapflag=1,date,month,year,day=1,memoflag=0;
	printf("Enter the date(dd.mm.yyyy) for calendar,today for todays memo or birthday for list of all birthdays of friends: ");
	while((c=getchar())!='\n')
	{
		s[i]=c;
		i++;
	}
	if((s[0]=='b')&&(s[1]='i')&&(s[2]=='r')&&(s[3]=='t')&&(s[4]=='h')&&(s[5]=='d')&&(s[6]=='a')&&(s[7]=='y'))
	{
		printf("All birthdays::\n");
		printf("6th April->Anchal Mishra\n");
		printf("8th May->Koustav Manna\n");
		printf("24th July->Soumya Ghosh\n");
		printf("18th August->Subhamay Pal\n");
		printf("2nd September->Shouvik Banik\n");
		printf("28th September->Fayezur Rahman\n");
		printf("14th November->Biswanath Sinha\n");
		printf("14th December->Ritwik Ghosh\n");

		exit(0);
	}
	if((s[0]=='t')&&(s[1]='o')&&(s[2]=='d')&&(s[3]=='a')&&(s[4]=='y'))
	{
		time_t mytime;
		struct tm *mytym;
		mytime=time(NULL);
		mytym=localtime(&mytime);
		date=mytym->tm_mday;
		month=1 + mytym->tm_mon;
		year=1990 + mytym->tm_year;
		printf("Today's date is:%d.%d.%d",date,month,2017);
		if((date==6)&&(month==4))
			printf("->Anchal Mishra's birthday!\n");
		if((date==14)&&(month==11))
			printf("->Biswanath Sinha's birthday!\n");
		if((date==2)&&(month==9))
			printf("->Happy Birthday to you!!!\n");
		if((date==28)&&(month==9))
			printf("->Fayezur Rahman's birthday!\n");
		if((date==24)&&(month==7))
			printf("->Soumya Ghosh's birthday!\n");
		if((date==8)&&(month==5))
			printf("->Koustav Manna's birthday!\n");
		if((date==14)&&(month==12))
			printf("->Ritwik Ghosh's birthday!\n");
		if((date==18)&&(month==8))
			printf("->Subhamay Pal's birthday!\n");
		exit(0);
	}
	date=(((s[0]-48)*10)+(s[1]-48));
	month=(((s[3]-48)*10)+(s[4]-48));
	year=(((s[6]-48)*1000)+((s[7]-48)*100)+((s[8]-48)*10)+(s[9]-48));
	printf("\nDate given: %d.%d.%d\n",date,month,year);
	while(flag==0)
	{
		day++;
		bdate++;
		if(day==7)
		{
			day=0;
		}
		if((bmonth==1)&&(bdate==32))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==2)&&(bdate==29)&&(leapflag==0))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==2)&&(bdate==30)&&(leapflag==1))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==3)&&(bdate==32))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==4)&&(bdate==31))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==5)&&(bdate==32))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==6)&&(bdate==31))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==7)&&(bdate==32))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==8)&&(bdate==32))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==9)&&(bdate==31))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==10)&&(bdate==32))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==11)&&(bdate==31))
		{
			bdate=1;
			bmonth++;
		}
		else if((bmonth==12)&&(bdate==32))
		{
			bdate=1;
			bmonth++;
		}
		if(bmonth==13)
		{
			byear++;
			bdate=1;
			bmonth=1;
			if(byear%400==0)
				leapflag=1;
			else if(byear%100==0)
				leapflag=0;
			else if(byear%4==0)
				leapflag=1;
			else
				leapflag=0;
		}
		if(bdate==date)
		{
			if(bmonth==month)
			{
				if(byear==year)
				{
					flag=1;
				}
			}
		}
	}
	if(day==0)
		printf("%d.%d.%d Day::Sunday",bdate,bmonth,byear);
	if(day==1)
		printf("%d.%d.%d Day::Monday",bdate,bmonth,byear);
	if(day==2)
		printf("%d.%d.%d Day::Tuesday",bdate,bmonth,byear);
	if(day==3)
		printf("%d.%d.%d Day::Wednesday",bdate,bmonth,byear);
	if(day==4)
		printf("%d.%d.%d Day::Thursday",bdate,bmonth,byear);
	if(day==5)
		printf("%d.%d.%d Day::Friday",bdate,bmonth,byear);
	if(day==6)
		printf("%d.%d.%d Day::Saturday",bdate,bmonth,byear);
	printf("\n");
	while(bdate!=1)
	{
		bdate--;
		day--;
		if(day==-1)
			day=6;
	}
	for(i=0;i<5;i++)
		for(j=0;j<7;j++)
		{
			cal[i][j]=100;
		}
	if(bmonth==1)
		max=31;
	if((bmonth==2)&&(leapflag==1))
		max=29;
	if((bmonth==2)&&(leapflag==0))
		max=28;
	if(bmonth==3)
		max=31;
	if(bmonth==4)
		max=30;
	if(bmonth==5)
		max=31;
	if(bmonth==6)
		max=30;
	if(bmonth==7)
		max=31;
	if(bmonth==8)
		max=31;
	if(bmonth==9)
		max=30;
	if(bmonth==10)
		max=31;
	if(bmonth==11)
		max=30;
	if(bmonth==12)
		max=31;
	count=1;
	j=day;
	for(i=0;i<5;i++)
	{
		for(j;j<7;j++)
		{
			cal[i][j]=count;
			count++;
			if(count>max)
				break;
		}
		j=0;
	}
	if(cal[0][5]==1)
	{
		if(max==31)
		{
			cal[0][0]=31;
		}
	}
	if(cal[0][6]==1)
	{
		if(max>=30)
		{
			cal[0][0]=30;
		}
		if(max==31)
		{
			cal[0][1]=31;
		}
	}
	for(i=0;i<30;i++)
		printf("_");
	if(bmonth==1)
		printf("\n%s ,%d\n","January",byear);
	if(bmonth==2)
		printf("\n%s ,%d\n","February",byear);
	if(bmonth==3)
		printf("\n%s ,%d\n","March",byear);
	if(bmonth==4)
		printf("\n%s ,%d\n","April",byear);
	if(bmonth==5)
		printf("\n%s ,%d\n","May",byear);
	if(bmonth==6)
		printf("\n%s ,%d\n","June",byear);
	if(bmonth==7)
		printf("\n%s ,%d\n","July",byear);
	if(bmonth==8)
		printf("\n%s ,%d\n","August",byear);
	if(bmonth==9)
		printf("\n%s ,%d\n","September",byear);
	if(bmonth==10)
		printf("\n%s ,%d\n","October",byear);
	if(bmonth==11)
		printf("\n%s ,%d\n","November",byear);
	if(bmonth==12)
		printf("\n%s ,%d\n","December",byear);

	for(i=0;i<30;i++)
		printf("_");
	printf("\n");
	printf("S  M  T  W  T  F  S\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<7;j++)
		{
			if(cal[i][j]!=100)
			{
				if(cal[i][j]<10)
					printf("%d  ",cal[i][j]);
				else
					printf("%d ",cal[i][j]);
			}
			else
				printf("   ");
		}
		printf("\n");
	}
	printf("Do you want to see the full calendar for %d year?(1/0)",byear);
	scanf("%d",&choice);
	if(choice==1)
	{
		while(bmonth>=1)
		{
			while(bdate!=1)
			{
				bdate--;
				day--;
				if(day==-1)
					day=6;
			}
			if(bmonth==1)
				break;
			bmonth--;
			if(bmonth==1)
			{
				bdate=31;
				day--;
			}
			else if((bmonth==2)&&(leapflag==1))
			{
				bdate=29;
				day--;
			}
			else if((bmonth==2)&&(leapflag==0))
			{
				bdate=28;
				day--;
			}
			else if(bmonth==3)
			{
				bdate=31;
				day--;
			}
			else if(bmonth==4)
			{
				bdate=30;
				day--;
			}
			else if(bmonth==5)
			{
				bdate=31;
				day--;
			}
			else if(bmonth==6)
			{
				bdate=30;
				day--;
			}
			else if(bmonth==7)
			{
				bdate=31;
				day--;
			}
			else if(bmonth==8)
			{
				bdate=31;
				day--;
			}
			else if(bmonth==9)
			{
				bdate=30;
				day--;
			}
			else if(bmonth==10)
			{
				bdate=31;
				day--;
			}
			else if(bmonth==11)
			{
				bdate=30;
				day--;
			}
			if(day==-1)
			{
				day=6;
			}

		}
		for(bmonth=1;bmonth<=12;bmonth++)
		{
			for(i=0;i<5;i++)
				for(j=0;j<7;j++)
				{
					cal[i][j]=100;
				}
			if(bmonth==1)
				max=31;
			if((bmonth==2)&&(leapflag==1))
				max=29;
			if((bmonth==2)&&(leapflag==0))
				max=28;
			if(bmonth==3)
				max=31;
			if(bmonth==4)
				max=30;
			if(bmonth==5)
				max=31;
			if(bmonth==6)
				max=30;
			if(bmonth==7)
				max=31;
			if(bmonth==8)
				max=31;
			if(bmonth==9)
				max=30;
			if(bmonth==10)
				max=31;
			if(bmonth==11)
				max=30;
			if(bmonth==12)
				max=31;
			count=1;
			j=day;
			for(i=0;i<5;i++)
			{
				for(j;j<7;j++)
				{
					cal[i][j]=count;
					count++;
					if(count>max)
						break;
				}
				j=0;
			}
			if(cal[0][5]==1)
			{
				if(max==31)
				{
					cal[0][0]=31;
				}
			}
			if(cal[0][6]==1)
			{
				if(max>=30)
				{
					cal[0][0]=30;
				}
				if(max==31)
				{
					cal[0][1]=31;
				}
			}
			for(i=0;i<30;i++)
				printf("_");
			if(bmonth==1)
				printf("\n%s ,%d\n","January",byear);
			if(bmonth==2)
				printf("\n%s ,%d\n","February",byear);
			if(bmonth==3)
				printf("\n%s ,%d\n","March",byear);
			if(bmonth==4)
				printf("\n%s ,%d\n","April",byear);
			if(bmonth==5)
				printf("\n%s ,%d\n","May",byear);
			if(bmonth==6)
				printf("\n%s ,%d\n","June",byear);
			if(bmonth==7)
				printf("\n%s ,%d\n","July",byear);
			if(bmonth==8)
				printf("\n%s ,%d\n","August",byear);
			if(bmonth==9)
				printf("\n%s ,%d\n","September",byear);
			if(bmonth==10)
				printf("\n%s ,%d\n","October",byear);
			if(bmonth==11)
				printf("\n%s ,%d\n","November",byear);
			if(bmonth==12)
				printf("\n%s ,%d\n","December",byear);

			for(i=0;i<30;i++)
				printf("_");
			printf("\n");
			printf("S  M  T  W  T  F  S\n");
			for(i=0;i<5;i++)
			{
				for(j=0;j<7;j++)
				{
					if(cal[i][j]!=100)
					{
						if(cal[i][j]<10)
							printf("%d  ",cal[i][j]);
						else
							printf("%d ",cal[i][j]);
					}
					else
						printf("   ");
				}
				printf("\n");
			}
			i=0;
			if(bmonth==1)
			{
				while(i<31)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if((bmonth==2)&&(leapflag==0))
			{
				while(i<28)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if((bmonth==2)&&(leapflag==1))
			{
				while(i<29)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==3)
			{
				while(i<31)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==4)
			{
				while(i<30)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==5)
			{
				while(i<31)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==6)
			{
				while(i<30)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==7)
			{
				while(i<31)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==8)
			{
				while(i<31)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==9)
			{
				while(i<30)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==10)
			{
				while(i<31)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==11)
			{
				while(i<30)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
			if(bmonth==12)
			{
				while(i<31)
				{
					day++;
					if(day==7)
						day=0;
					i++;
				}
			}
		}
	}
	printf("\nThank you!!!\n");
}











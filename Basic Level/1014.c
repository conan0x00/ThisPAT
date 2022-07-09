#include<stdio.h>
#include <stdlib.h>

#define Nmax 62

int main()
{
	int i=0,j=0,count=0;
	int dd=0,hh=0,mm=0;
	char day[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char s1[Nmax],s2[Nmax],s3[Nmax],s4[Nmax];
	
	//输入部分
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	scanf("%s",s4);

	i = 0;
	count = 0;
	while(s2[i] != '\0' && s1[i] != '\0' && count != 2)
	{
		if(s2[i] == s1[i])
		{
			if(count == 1)
			{	
				if(s1[i] - '0' >=0 && s1[i] - '0'<10)
				{
					hh = s1[i] - '0';
					count++;
				}
				else if(s1[i] >= 'A' && s1[i] <= 'N')
				{
					hh = s1[i] - 'A'+10;
					count++;
				}
			}
			if(count == 0 && s1[i] >= 'A' && s1[i] <= 'G')
			{
				dd = s1[i] - 'A';
				count++;
			}
		}
		i++;
	}

	i = 0;
	while(s3[i] != '\0' && s4[i] !='\0' && i< 60)
	{
		if(s3[i] == s4[i])
		{
			if((s3[i] >= 'a' && s3[i] <= 'z') || (s3[i] >= 'A' && s3[i] <= 'Z' )) 
				break;
		}
		i++;
	}
	mm = i;

	printf("%s %02d:%02d",day[dd],hh,mm);

	return 0;
}

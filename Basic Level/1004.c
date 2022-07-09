#include<stdio.h>
#include<string.h>

struct Grade
{
	char name[11];
	char ID[11];
	int score;
};

int main()
{	
	int i=0,temp=0,N=0;
	char s1[11],s2[11];
	struct Grade max,min;
	
	scanf("%d",&N);
	if(N <1)
		return -1;

	max.score = 0;
	min.score = 100;
	for (i = 0; i < N; ++i)
	{
		scanf("%s %s %d",s1,s2,&temp);
		if(temp <0 || temp > 100)
			return -1;
		if(temp > max.score)
		{
			max.score = temp;
			strcpy(max.name,s1);
			strcpy(max.ID,s2);
		}
		if(temp < min.score)
		{
			min.score = temp;
			strcpy(min.name,s1);
			strcpy(min.ID,s2);
		}
	}
	printf("%s %s\n",max.name,max.ID);
	printf("%s %s",min.name,min.ID);
	
	return 0;
}

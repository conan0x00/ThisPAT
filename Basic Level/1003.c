#include<stdio.h>
#include<stdlib.h>

#define Nmax 100

int main()
{	
	int i=0,j=0,N=0;
	int p=0,t=0,a=0,tag=0,pre_a=0,post_a=0;
	int *data;
	char s[Nmax];
	
	scanf("%d",&N);
	if(N <1 || N > 9)
		return -1;
	data = (int *)malloc(sizeof(int)*N);

	for (i = 0; i < N; ++i)
	{
		data[i] = 0;
		scanf("%s",s);
		j = 0;
		p = 0;
		a = 0;
		t = 0;
		tag = 0;
		pre_a = 0;
		post_a = 0;
		while(s[j] != '\0')
		{
			if (s[j] != 'P' && s[j] != 'A' && s[j] != 'T')
			{
				tag = 1;
				break;
			}
			else if(s[j] == 'P')
			{
				if (p==0)
					p = 1;
				else
				{
					p = 2;
					break;
				}
			}
			else if(s[j] == 'A')
			{
				if(p == 1 && t == 0)
					a++;
				if(p == 0)
					pre_a++;
				if( t==1 )
					post_a++;
			}
			else if(s[j] == 'T')
			{
				if(p==1 && a>0 && t==0)
					t = 1;
				else
				{
					t = 2;
					break;
				}
			}
			j++;
		}
		if (tag == 0 && p==1 && a>0 && t==1 && pre_a*a == post_a)
			data[i] = 1;
	}

	for(i=0;i<N-1;i++)
	{
		if(data[i] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	if(data[N-1] == 1)
		printf("YES");
	else
		printf("NO");

	free(data);
	return 0;
}

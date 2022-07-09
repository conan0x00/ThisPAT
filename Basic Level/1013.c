#include<stdio.h>
#include<stdlib.h>

#define Nmax 10000
#define NCol 10

int main()
{
	int i=0,tag=0,j=0,count=0;
	int M=0,N=0;
	int a[Nmax]={0};

	scanf("%d %d",&M,&N);
	if(M<1 || N<1 || M>N || N > Nmax)
	{
		printf("输入参数M、N错误\n");
		return -1;
	}
	if(N == 1)
	{
		printf("%d",2);
		return 0;
	}

	a[0] = 2;
    //构造N个素数表
    count = 1;
    i = 3;
    while(count < N)
    {
    	tag = 1;
    	for(j = 0; j < count; j++)
		{
			if (i % a[j] == 0) //非素数
			{
				tag = 0;
				break;
			}
		}
		if(tag) //找到一个新素数
			a[count++] = i;
		i++;
    }

	for (j = M-1; j < N; j++)
	{
		if ((j-M+1)%NCol == 0)
			printf("%d",a[j]);
		else 
			printf(" %d",a[j]);

		if ((j-M+1)%NCol == NCol-1 && (j-M+2)-N !=0)
			printf("\n");
	}
    return 0;
}

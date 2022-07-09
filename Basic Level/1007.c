#include<stdio.h>
#include<stdlib.h>

#define Nmax 100000
#define NPrime 9600 //根据素数定理，Nmax以内素数个数为9592

int main()
{
	int i=0,j=0,tag=0;
	int N=0;
	int length=1;		//素数个数
	int count=0;		//素数对个数
	int a[NPrime]={0}; //用于存放Nmax内的素数

	scanf("%d",&N);
	if (N < 2 || N > Nmax)
	{
		printf("参数N错误\n");
		return -1;
	}

	a[0] = 2; //第一个素数 
	//构造N以内的素数表
	for (i = 3; i <= N; i=i+2)
	{
		tag = 1;

		for(j = 0; j < length; j++)
		{
			if (i % a[j] == 0) //非素数
			{
				tag = 0;
				break;
			}
		}

		if(tag) //找到一个新素数
		{
			 
			if((i-a[length-1]) == 2) //此素数与前一个构成素数对
				count++;
			a[length++] = i;
		}
	}
	printf("%d",count);
	return 0;
}

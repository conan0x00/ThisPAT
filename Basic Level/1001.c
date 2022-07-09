#include<stdio.h>

int main()
{
	int count=0;
	int N=0;

	//输入部分
	scanf("%d",&N);
	if ( N < 1 || N >1000)
	{
		printf("输入参数错误\n");
		return -1;
	}

	while(N > 1)
	{
		if(N%2 == 0)
			N = N/2;
		else
			N = (3*N+1)/2;

		count++;
	}
	printf("%d", count);

	return 0;
}

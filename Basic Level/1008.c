#include<stdio.h>
#include<stdlib.h>
#define Nmax 100

void Reverse(int a[], int start, int end)
{
	int i=0;
	int temp=0;
	for (i = start; i <= (start+end)/2; ++i)
	{
		temp = a[i];
		a[i] = a[start+end-i];
		a[start+end-i] = temp;
	}
}

int main()
{
	int i=0,j=0,temp=0;
	int N=0,M=0;
	int *a;

	scanf("%d %d",&N,&M);
	if (N < 1 || N > Nmax || M<0)
	{
		printf("参数N、M错误\n");
		return -1;
	}
	//当M过大时，等价于M-N, M-2N ...	
	M = M % N;

	a = (int *)malloc(sizeof(int)*N);
	for (i = 0; i < N; ++i)
		scanf("%d",&a[i]);

	if(M > 0) //需要移位
	{
		Reverse(a,0,N-M-1);
		Reverse(a,N-M,N-1);
		Reverse(a,0,N-1);
	}

	printf("%d",a[0]);
	for (i = 1; i < N; ++i)
		printf(" %d",a[i]);

	free(a);
	return 0;
}

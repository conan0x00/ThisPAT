#include<stdio.h>
#include <stdlib.h>

int main()
{
	int i=0,j=0,k=0,temp=0,length=0;
	int K=0,N=0;
	int *data;

	//输入部分
	scanf("%d",&K);
	if ( K < 1 || K > 99)
	{
		printf("输入参数错误\n");
		return -1;
	}
	data = (int *)malloc(sizeof(int)*K);	

	for (i = 0; i < K; ++i)
	{
		scanf("%d",&data[i]);
		if(data[i] < 2 || data[i] > 100)
			return -1;
	}

	
	length = K;
	for (i = 0; i < K; ++i)
	{
		if(data[i] == 0)  //已被别的数包含
			continue;
		temp = data[i];
		while(temp > 1)
		{
			if(temp%2 == 0)
				temp = temp/2;
			else
				temp = (3*temp+1)/2;

			for(j=0;j<K;j++)
			{
				if(j != i && data[j] == temp)
				{
					data[j] = 0;
					length--;
				}
			}
		}
	}
	

	for (i = 0; i < length; ++i)
	{
		temp = 0;
		k = 0;
		for (j = 0; j < K; ++j)
		{
			if(data[j] > temp)
			{
				k=j;
				temp = data[j];
			}
		}
		if(i==0)
			printf("%d",data[k]);
		else
			printf(" %d",data[k]);
		data[k] = 0;
	}
	

	free(data);
	return 0;
}

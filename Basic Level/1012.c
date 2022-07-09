#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=0,j=0;
    int temp=0;
    int N=0;
   	int A[5]={0};
   	int tag[5]={0};
   	int count = 0;
   	int flag=1;

    scanf("%d",&N);

    if(N < 1 || N > 1000)
    {
    	printf("输入N错误\n");
    	return -1;
    }
 
    //开始统计
    for (j = 0; j < N; ++j)
    {
    	scanf("%d", &temp);
    	if(temp < 1 || temp > 1000)
    	{
    		printf("输入数据错误\n");
    		return -1;
    	}

    	i = temp%5;
    	switch(i)
    	{
    		case 0: if(temp%2 ==0) A[i] += temp; tag[i]=1; break;
    		case 1: A[i] += flag*temp; flag=-flag; tag[i]=1; break;
    		case 2: A[i]++; tag[i]=1; break;
    		case 3: A[i] += temp; count++; tag[i]=1; break;
    		case 4: if(temp > A[i]) A[i]=temp; tag[i]=1; break;
    	}	
    }

    if(A[0] ==0)
    	printf("%c",'N');
    else
    	printf("%d",A[0]);

    for (j = 1; j < 5; j++)
    {
    	if(tag[j])
    	{
    		if(j==3)
    			printf(" %.1f",(float) A[j]/count);
    		else
    			printf(" %d",A[j]);
    	}
    	else
    		printf(" %c",'N');
    }
    return 0;
}

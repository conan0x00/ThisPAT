#include<stdio.h>

int Compare(long int A,long int B,long int C)
{
	if(A > 0 && B > 0 && A+B <= 0)
		return 1;
	else if(A < 0 && B < 0 && A+B >= 0)
		return 0;
	else if(A+B > C)
		return 1;
	else
		return 0;
}

int main()
{
    long int A=0,B=0,C=0;
    int i=0,T=0;
    int aa[10];

    scanf("%d",&T);
    if(T < 1 || T > 10)
    {
    	printf("输入正整数T错误\n");
    	return -1;
    }

    for (i = 0; i < T; ++i)
    {
    	scanf("%ld %ld %ld",&A,&B,&C);
    	aa[i] = Compare(A,B,C);
    }

    for (i = 0; i < T; ++i)
    {
		if(i==T-1)
    	{
	    	if(aa[i])
	    		printf("Case #%d: true",i+1);
	    	else
	    		printf("Case #%d: false",i+1);
    	}
    	else
    	{
	    	if(aa[i])
	    		printf("Case #%d: true\n",i+1);
	    	else
	    		printf("Case #%d: false\n",i+1);    		
    	}
    }

    return 0;
}

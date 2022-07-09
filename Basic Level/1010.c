#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i=1,N=0;
    int a=0,b=0;
    char c;
    int *aa;

    scanf("%d %d",&a,&b);

    if(b < 0)
    {
    	printf("输入错误\n");
    	return -1;
    }
    else if(b == 0)
    {
        printf("%d %d",0,0);
        return 0;
    }

    aa = (int *)malloc(sizeof(int)*2*b);
    aa[0] = a*b; 
    aa[1] = b-1;
    N = b;

    while(getchar() != '\n' && i < N)
    {
    	scanf("%d %d",&a,&b);
        if (b > 0)
        {
        	aa[2*i] = a*b;
        	aa[2*i+1] = b-1;
        	i++;
        }
    }
    N = i;

    for(i=0;i<2*N-1;i++)
        printf("%d ",aa[i]);
    printf("%d",aa[2*N-1]);

    free(aa);
    return 0;
}

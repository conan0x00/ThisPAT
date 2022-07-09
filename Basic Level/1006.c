#include<stdio.h>

void PrintN(int n)
{
    int i=0;
    int n0,n1,n2;
    
    n0 = n%10;
    n = n/10;
    n1 = n%10;
    n2 = n/10;
    for(i=0;i < n2; i++)
        printf("%c",'B');
    for(i=0;i < n1; i++)
        printf("%c",'S');
    for(i=0;i < n0; i++)
        printf("%d",i+1);

    return;

}

int main()
{
    int n=0;

    scanf("%d",&n);
    if(n<1 || n>1000)
    {
        printf("错误的输入\n");
        return -1;
    }

    PrintN(n);
    return 0;
}

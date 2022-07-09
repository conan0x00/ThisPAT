#include<stdio.h>

#define Nmax 100

int main()
{	
	int i=0,j=0,count=0;
	char s[81];
	int N=0;
	int data[Nmax]={-1}; //用于纪录第i个单词开始位置和结束位置

	fgets(s,81,stdin);
	i=0;
	//找到第一个不是空格的位置
	while(s[i] == ' ' && i < 80)
		i++;
	data[0] = i;
	count = 1;
	for (; i < 81; ++i)
	{
		if (s[i]==' ') //每两个单词间仅一个空格
		{
			data[2*count-1] = i-1;
			data[2*count] = i+1;
			count++;
		}
		if(s[i]== '\n' || s[i] == '\0')//最后一个单词结尾
		{
			data[2*count-1] = i-1;
			break;
		}
	}

	for(i=count; i> 1; i--)
	{	
		for(j=data[2*i-2];j<=data[2*i-1];j++)
			printf("%c",s[j]);
		printf(" ");
	}
	for(j=data[0];j<=data[1];j++)
			printf("%c",s[j]);

	return 0;
}

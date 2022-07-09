#include<stdio.h>

void PrintPinyin(int a)
{
	if(a==0)
		return;
	PrintPinyin(a/10);
	switch(a % 10)
	{
		case 0: printf("%s ","ling"); break;
		case 1: printf("%s ","yi"); break;
		case 2: printf("%s ","er");	break;
		case 3: printf("%s ","san"); break;
		case 4: printf("%s ","si"); break;
		case 5: printf("%s ","wu"); break;
		case 6: printf("%s ","liu"); break;
		case 7: printf("%s ","qi"); break;
		case 8: printf("%s ","ba"); break;
		case 9: printf("%s ","jiu"); break;
	}

	return;
}

int main()
{
	int sum=0;
	int count=1;
	char c;

	scanf("%c",&c);
	if ((c -'0' <= 0) || (c-'0' >9))
	{
		printf("输入错误\n");
		return -1;
	}

	while ( (c -'0'>=0) && (c-'0'<=9))
	{
		sum += c -'0';
		scanf("%c",&c);
		count++;
	}
	if (count > 101)
	{
		printf("自然数过大\n");
		return -1;
	}

	if(sum == 0)
		return 0;

	PrintPinyin(sum/10);
	switch(sum % 10)
	{
		case 0: printf("%s","ling"); break;
		case 1: printf("%s","yi"); break;
		case 2: printf("%s","er");	break;
		case 3: printf("%s","san"); break;
		case 4: printf("%s","si"); break;
		case 5: printf("%s","wu"); break;
		case 6: printf("%s","liu"); break;
		case 7: printf("%s","qi"); break;
		case 8: printf("%s","ba"); break;
		case 9: printf("%s","jiu"); break;
	}
	return 0;
}

#include<stdio.h>
int main()
{
	char str[100],temp;
	int start=0,end=0;
	printf("enter string :");
	scanf("%s",str);
	while(str[end]!='\0')
	{
		end++;
	}
	end--;
	while(start<end)
	{
		temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		start++;end--;
	}
	printf("%s\n",str);
	return 0;
}

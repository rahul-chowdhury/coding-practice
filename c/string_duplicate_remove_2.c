#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],ascii[256];
	int x=0,i,j;
	printf("enter string :");
	scanf("%s",str);
	for(i=0;i<256;i++)
	{
		ascii[i]=0;
	}
	for(i=0;i<strlen(str);i++)
	{
		ascii[str[i]]++;
	}
	for(i=0;i<256;i++)
	{
		if(ascii[i]>0)
		{
			str[x++]=i;
		}
	}
	str[x]='\0';
	printf("%s\n",str);
	return 0;
}

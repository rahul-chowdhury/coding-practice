#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

void shift_spaces(char *s,int n)
{
	int next_pos=-1;
	
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]==' ')
		{
			next_pos=i;
		}
		if(s[i]!=' ' && next_pos!=-1)
		{
			s[next_pos]=s[i];
			next_pos--;
			s[i]=' ';
		}
	}
}
			

void reverse(int *a,int start,int end)
{
	int temp;
	while(start<=end)
	{
		temp=a[start];
		a[start]=a[end];
		a[end]=temp;
		start++;
		end--;
	}
}


void rotate(int *a,int n,int x)
{
	reverse(a,0,x-1);
	reverse(a,x,n-1);
	reverse(a,0,n-1);
}

int main()
{
	int (*a)=new int[10];
	for(int j=0;j<10;j++)
	{
		a[j]=rand()%100;
		cout<<a[j]<<" ";
	}
		
	cout<<endl;
	rotate(a,10,6);
	for(int j=0;j<10;j++)
	{
		//a[j]=rand()%100;
		cout<<a[j]<<" ";
	}
	cout<<endl;
	
	char s[]="my name is rahul";
	int n=sizeof(s)/sizeof(char);
	shift_spaces(s,n-1);
	cout<<s<<endl;
	return 0;
}
		

#include<iostream>
#include<stdlib.h>
using namespace std;

void print_spiral(int **a,int n)
{
	int top=0,bottom=n-1,left=0,right=n-1;
	while(top<=bottom && left<=right)
	{
		for(int i=left;i<=right;i++)
		{
			cout<<a[top][i]<<" ";
		}
		cout<<endl;
		top++;
		for(int i=top;i<=bottom;i++)
		{
			cout<<a[i][right]<<" ";
		}
		cout<<endl;
		right--;
		for(int i=right;i>=left;i--)
		{
			cout<<a[bottom][i]<<" ";
		}
		cout<<endl;
		bottom--;
		for(int i=bottom;i>=top;i--)
		{
			cout<<a[i][left]<<" ";
		}
		cout<<endl;
		left++;
	}
}


int main()
{
	int *(*a)=new int*[5];
	for(int i=0;i<5;i++)
	{
		a[i]=new int[5];
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			a[i][j]=rand()%100;
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;cout<<endl;cout<<endl;
	print_spiral(a,5);
	return 0;
}
		

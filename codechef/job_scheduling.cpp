#include<iostream>
using namespace std;
#include<string>

int main()
{
	int n,no_of_jobs;
	cin>>n;
	int input[n][10000];
	for(int k=0;k<n;k++)
	{
		cin>>no_of_jobs;
		input[k][0]=no_of_jobs;
		for(int i=1;i<=2*no_of_jobs;i++)
		cin>>input[k][i];
	}
	for(int k=0;k<n;k++)
	{
		int job[input[k][0]][2];
		int x=0;
		for(int i=1;i<=2*input[k][0];i=i+2)
		{
			job[x][0]=input[k][i];
			job[x++][1]=input[k][i+1];
		}
		
	}
	return 0;
}

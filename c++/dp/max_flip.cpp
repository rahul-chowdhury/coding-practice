#include<iostream>
#include<limits.h>
using namespace std;


int max_flip(int *a,int n)
{
	int sum0[n],sum1[n],beg=-1,end=-1,cur=0,outsidemax=INT_MIN,insidemax=INT_MIN;
	if(a[0]==1)
	{
		sum0[0]=0;
	}
	else
	{
		sum0[0]=1;
	}
	sum1[0]=1-sum0[0];
	for(int i=1;i<n;i++)
	{
		sum0[i] =sum0[i-1]+((a[i]==0)?1:0);
		sum1[i] =sum1[i-1]+((a[i]==1)?1:0);
	}
	
	while(cur!=n)
	{
		outside1=
		if(beg!=0)
		{
			
}

int main()
{
	return 0;
}

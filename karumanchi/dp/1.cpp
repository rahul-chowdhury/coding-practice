#include<bits/stdc++.h>
using namespace std;


long int f(int n)
{
	if(n==0 || n==1)
		return 2;
	long int t[n+1],sum=0;
	t[0]=t[1]=2;
	t[2]=8;
	for(int i=3;i<n;i++)
	{
		t[i] =t[i-1]+2*t[i-1]*t[i-2];
		
		
	}
	return t[n];
}

int main()
{
	int n=4;
	cout<<f(2)<<" "<<f(5)<<" "<<f(7)<<endl;
	return 0;
}

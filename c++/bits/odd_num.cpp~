#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int a[]={12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};
	int n=sizeof(a)/sizeof(a[0]);
	int result=0,sum;
	for(int i=0;i<32;i++)
	{
		sum=0;
		int x=(1<<i);
		for(int j=0;j<n;j++)
		{
			if(x&a[j])
			sum++;
		}
		if(sum%3!=0)
		result |=x;
	}
	cout<<"result="<<result<<endl;
	return 0;
}
		

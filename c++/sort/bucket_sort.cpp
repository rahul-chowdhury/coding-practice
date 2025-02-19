#include <bits/stdc++.h>
using namespace std;

int * bucket_sort(int *a,int n,int buckets,int *b)//n=no. of elements in the array ; 
{
	int c[buckets],x=0;
	
	for(int i=0;i<buckets;i++)
		c[i]=0;

	for(int i=0;i<n;i++)
		c[a[i]]++;
		
	for(int i=0;i<buckets;i++)
	{
		for(int k=1;k<=c[i];k++)
			b[x++]=i;
	}
	
	
}

int main()
{
	int a[]={2,4,56,77,8,99,0,-12};
	int b[sizeof(a)/sizeof(int)];
	int min=a[0],max=a[0];
	for(int i=1;i<sizeof(a)/sizeof(int);i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	if(min<0)//scaling up for negative values
	{
		for(int i=0;i<sizeof(a)/sizeof(int);i++)
		{
			a[i]+=-min;
		}
	}
	
	bucket_sort(a,sizeof(a)/sizeof(int),max+1+-min,b);
	if(min<0)//scaling down to get original values
	{
		for(int i=0;i<sizeof(a)/sizeof(int);i++)
		{
			b[i]-=-min;
		}
	}
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<b[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}

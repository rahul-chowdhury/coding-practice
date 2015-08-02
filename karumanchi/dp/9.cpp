#include<bits/stdc++.h>
using namespace std;

int maximum(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int max_sum_contiguous_subsequence(int *a,const int &n)
{
	
	int max[n];
	if(n>=1)
		max[0]=a[0];
	if(n>=2)
		max[1]=maximum(a[0],a[1]);
	for(int i=2;i<n;i++)
	{
		max[i]=maximum(a[i]+max[i-2],max[i-1]);
	}
	return max[n-1];
}

int main()
{
	int a[]={-2,11,-4,13,-5,2};
	cout<<"max sum is "<<max_sum_contiguous_subsequence(a,sizeof(a)/sizeof(int))<<endl;
	
	return 0;
}

	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				

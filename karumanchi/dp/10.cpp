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
	max[n-1]=a[n-1];
	max[n-2]=maximum(a[n-1],a[n-2]);
	for(int i=n-3;i>=0;i--)
	{
		max[i]=maximum(a[i]+max[i+2],max[i+1]);
	}
	return max[0];
}

int main()
{
	int a[]={-2,11,-4,13,-5,2};
	cout<<"max sum is "<<max_sum_contiguous_subsequence(a,sizeof(a)/sizeof(int))<<endl;
	
	return 0;
}

	
			
			
			
			
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				

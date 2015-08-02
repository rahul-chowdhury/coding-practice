#include<bits/stdc++.h>
using namespace std;


int max_sum_contiguous_subsequence(int *a,int n,int *start,int *end)
{
	
	int max_sum=INT_MIN,sum_ending_here=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>max_sum)
		{
			max_sum=a[i];
			*start=i;
			*end=i;
		}
	}
	if(max_sum<=0)
		return max_sum;
	*start=*end=0;		
	for(int i=0;i<n;i++)
	{
		sum_ending_here +=a[i];
		if(sum_ending_here<0)
		{
			sum_ending_here=0;
			if(i<n-1)
				*start=i+1;
			continue;
		}
		if(sum_ending_here>max_sum)
		{
			max_sum=sum_ending_here;
			*end=i;
		}
	}
	return max_sum;
}

int main()
{
	int a[]={-2,11,-4,13,-5,2},start=0,end=0;
	cout<<"max sum is "<<max_sum_contiguous_subsequence(a,sizeof(a)/sizeof(int),&start,&end)<<endl;
	for(int i=start;i<=end;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				

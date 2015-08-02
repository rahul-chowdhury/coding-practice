#include<bits/stdc++.h>
using namespace std;


int max_sum_contiguous_subsequence(int *a,int n,int *start,int *end)
{
	int sum,global_max=a[0],local_start,local_end,max;
		
	for(int i=0;i<n;i++)
	{
		max=a[i];
		local_start=i;
		sum=a[i];
		for(int j=i+1;j<n;j++)
		{
			sum +=a[j];
			if(max<sum)
			{
				max=sum;
				local_end=j;
			}
		}
		if(max>global_max)
		{
			global_max=max;
			*start=local_start;
			*end=local_end;
		}
	}
	return global_max;
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

	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
				

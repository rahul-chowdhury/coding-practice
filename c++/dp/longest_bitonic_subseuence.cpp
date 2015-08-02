#include<bits/stdc++.h>
using namespace std;

void calc_lis(int *a,int n,int *lis)
{
	if(n==0)
		return;
	lis[0]=1;
	int max;
	for(int i=1;i<n;i++)
	{	
		max=1;
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j] && lis[j]+1>max)
				max=lis[j]+1;
		}
		lis[i]=max;
	}
}

void calc_dis(int *a,int n,int *dis)
{
	if(n==0)
		return;
	dis[n-1]=1;
	int max;
	for(int i=n-2;i>=0;i--)
	{	
		max=1;
		for(int j=n-1;j>i;j--)
		{
			if(a[j]<a[i] && dis[j]+1>max)
				max=dis[j]+1;
		}
		dis[i]=max;
	}
}


int calc_lbs(int *a,int n)
{
	int lis[n],dis[n],max=1;
	calc_lis(a,n,lis);
	calc_dis(a,n,dis);
	for(int i=0;i<n;i++)
	{
		
			cout<<lis[i]<<" ";
		
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		
			cout<<dis[i]<<" ";
		
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		
			if(lis[i]+dis[i]-1>max)
				max=lis[i]+dis[i]-1;
		
	}
	return max;
}

int main()
{
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", calc_lbs( arr, n ) );
 
  //getchar();
  return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


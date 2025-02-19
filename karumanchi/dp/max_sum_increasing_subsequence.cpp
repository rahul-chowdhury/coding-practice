#include<bits/stdc++.h>
using namespace std;

void msis(int *reconstruct,int *a,int n,int *global_max,int *global_max_ending)
{
	int dp[n];
	*global_max=a[0];
	*global_max_ending=0;
	dp[0]=a[0];
	reconstruct[0]=0;
	for(int i=1;i<n;i++)
	{
		int max=a[i],last_max=i;
		for(int j=0;j<i;j++)
		{
			if(dp[j]+a[i]>max && a[j]<a[i])
			{
				max=dp[j]+a[i];
				last_max=j;
			}
		}
		dp[i]=max;
		if(dp[i]>*global_max)
		{
			*global_max=dp[i];
			*global_max_ending=i;
		}
		reconstruct[i]=last_max;
	}
	
}

void reconstruction(int *reconstruct,int *a,int global_max_ending)
{
	int i=global_max_ending;
	stack<int>s;
	s.push(a[i]);
	while(reconstruct[i]!=i)
	{
		i=reconstruct[i];
		s.push(a[i]);
	}
	while(!s.empty())
	{
		cout<<s.top()<<"  ";
		s.pop();
	}
	cout<<endl;
}

int main()
{
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
  	int n = sizeof(arr)/sizeof(arr[0]);
  	int global_max,global_max_ending;
  	int reconstruct[n];
  	msis(reconstruct,arr,n,&global_max,&global_max_ending);
 	reconstruction(reconstruct,arr,global_max_ending);
  return 0;
}


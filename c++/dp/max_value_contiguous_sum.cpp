#include<iostream>
#include<limits.h>
using namespace std;

int maxm(int a,int b)
{
	if(a>b)return a;
	return b;
}

int min(int a,int b)
{
	if(a>b)return b;
	return a;
}

int max_value_contiguous_sum(int *a,int n)
{
	int max=INT_MIN,max1,max2;
	max=(a[1]-a[0])?a[1]:a[0];
	max1=a[1];
	max2=a[0];
	for(int i=2;i<n;i++)
	{
		max=maxm(a[i]+max2,max1);
		max2=max1;
		max1=max;
	}
	return max;
}


int lis(int *a,int n)
{
	int m[n],max=1;
	for(int i=0;i<n;i++)
	m[i]=1;
	for(int i=1;i<n;i++)
	{
		
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i] && m[j]+1>m[i])
			m[i]=m[j]+1;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(m[i]>max)
		max=m[i];
	}
	return max;
}

int tiling(int n)
{
	int a[n+1];
	for(int i=0;i<=n;i++)
		a[i]=0;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<=n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	return a[n];
}

int lps(string s)
{
	int dp[s.length()][s.length()];
	int n=s.length();
	int max=1;
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
		if(i<n-1)
		{
			if(s[i]==s[i+1])
			{
				dp[i][i+1]=2;
				max=2;
			}
			else
				dp[i][i+1]=0;
		}
		
	}
	for(int l=3;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j])
			{
				cout<<s[i]<<endl;
				dp[i][j]=2+dp[i+1][j-1];
				max=2+dp[i+1][j-1];
			}
			else
			{
				dp[i][j]=maxm(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return max;
}


int lpsubstring(string s)
{
	bool dp[s.length()][s.length()];
	int n=s.length();
	int max=1;
	for(int i=0;i<n;i++)
	{
		dp[i][i]=1;
		if(i<n-1)
		{
			if(s[i]==s[i+1])
			{
				dp[i][i+1]=true;
				max=2;
			}
			else
				dp[i][i+1]=false;
		}
		
	}
	for(int l=3;l<=n;l++)
	{
		for(int i=0;i<=n-l;i++)
		{
			int j=i+l-1;
			if(s[i]==s[j] && dp[i+1][j-1])
			{
				cout<<i<<"...."<<j<<endl;
				dp[i][j]=true;
				max=l;
			}
			else
			{
				dp[i][j]=false;
			}
		}
	}
	return max;
}
int game(int *a,int i,int j)
{
	if(i==j)
		return a[i];
	if(j==i+1)
		return maxm(a[i],a[i+1]);
	return maxm(a[i]+min(game(a,i+1,j-1),game(a,i+2,j)),a[j]+min(game(a,i+1,j-1),game(a,i,j-2)));
}

bool subset_sum(int *a,int n,int sum)
{
	bool dp[sum+1][n];
	for(int i=0;i<n;i++)
		dp[0][i]=true;
	for(int i=1;i<=sum;i++)
		dp[i][0]=false;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			dp[j][i]=dp[j][i-1];
			if(j-a[i]>=0)
			dp[j][i]=dp[j][i-1] || dp[j-a[i]][i-1];
		}
	}
	return dp[sum+1][n-1];
}


int opt_jump(int *a,int n)
{
	int dp[n];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<n;i++)
	{
		int min=INT_MAX;
		for(int j=0;j<i;j++)
		{
			if(a[j]>=(i-j))
			{
				if(min>dp[j]+1)
					min=dp[j]+1;
			}
		}
		dp[i]=min;
	}
	return dp[n-1];
}

void maxj(int *a,int n)
{
	int b[n],max=INT_MIN;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		b[i]=max;
	}
	max=INT_MIN;
	for(int i=n-2;i>=0;i--)
	{
		if(b[i+1]-a[i]>max)
		{
			max=b[i+1]-a[i];
			
		}
	}
	cout<<"max diff is"<<max<<endl;
}
		
		
		
		
int main()
{
	int a[]={1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	//a={{2,11},{4,13},{5,2}};
	int value[]={1,3,4};
	
	int n=sizeof(a)/sizeof(a[0]);
	//cout<<opt_jump(a,n)<<endl;
	//cout<<max_value_contiguous_sum(a,n)<<endl;
	//cout<<lis(a,6)<<endl;
	//cout<<(subset_sum(a,6,9)?"true":"false")<<endl;
	//cout<<game(a,0,5)<<endl;
	//cout<<tiling(3)<<endl;
	//cout<<lps("12qwerty3443qwerty21")<<endl;
	//cout<<lpsubstring("12qwerty3443qwerty21")<<endl;
	int b[]={34,8,10,3,2,80,30,33,1};
	maxj(b,9);
	return 0;
}
	

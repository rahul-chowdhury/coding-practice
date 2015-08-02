#include<bits/stdc++.h>
using namespace std;

int max(int &a,int &b)
{
	if(a>b)
		return a;
	return b;
}

int LCS(int m,int n,string **reconstruct,string x,string y)
{
	int dp[m+1][n+1];
	for(int i=0;i<m;i++)
		dp[i][0]=0;
	for(int j=0;j<n;j++)
		dp[0][j]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
				reconstruct[i][j]="*";
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(dp[i][j]==dp[i-1][j])
				{
					reconstruct[i][j]="^";
				}
				else
				{
					reconstruct[i][j]="<";
				}
			}
		}
	}
	return dp[m][n];
}

void reconstruction(string **reconstruct,int &m,int &n,string &x,int &lcs_length)
{
	int i=m,j=n;
	string lcs="";
	while(lcs_length!=0)
	{
		if(reconstruct[i][j]=="*")
		{
			lcs.insert(0,1,x[i-1]);
			i--;
			j--;
			lcs_length--;
		}
		else if(reconstruct[i][j]=="<")
		{
			j--;
		}
		else
		{
			i--;
		}
	}
	cout<<lcs<<endl;
}


int main()
{
	string x="abcbdab";
	string y="bdcaba";
	int m=x.length(),n=y.length();
	string **reconstruct;
	reconstruct=new string *[m+1];
	for(int i=0;i<=m;i++)
		reconstruct[i]=new string[n+1];
	int lcs_length=LCS(m,n,reconstruct,x,y);
	//cout<<"xx"<<endl;
	reconstruction(reconstruct,m,n,x,lcs_length);
	return 0;
}



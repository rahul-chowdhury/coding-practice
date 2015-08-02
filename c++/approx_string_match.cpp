#include<iostream>
#include<string>
using namespace std;
 int cost[100][100];
int min(int a,int b,int c)
{
	return (a>b)?((b>c)?c:b):((a<c)?a:c);
}

int match(char a,char b)
{
	if(a==b)
		return 0;
	return 1;
}
int insert(char a,char b)
{
	return 1;
}
int delete1(char a,char b)
{
	return 1;
}

int compare(string s,string t)
{
	int match_cost,insert_cost,delete_cost;
	if(s.length()==0 && t.length()==0)
	return 0;
	if(s.length()==0)
	return t.length();
	if(t.length()==0)
	return s.length();
	for(int i=0;i<s.length();i++)
	{
		cost[i][0]=i;
	}
	for(int i=0;i<t.length();i++)
	{
		cost[0][i]=i;
	}
	for(int i=1;i<=s.length();i++)
	{
		for(int j=1;j<=t.length();j++)
		{
			match_cost=cost[i-1][j-1]+match(s[i-1],t[j-1]);
			insert_cost=cost[i][j-1]+insert(s[i-1],t[j-1]);
			delete_cost=cost[i-1][j]+delete1(s[i-1],t[j-1]);
			cost[i][j]=min(match_cost,insert_cost,delete_cost);
		}
		
	}
	
	return cost[s.length()][t.length()];
}

int main()
{

	string s="Thou shalt not kill",t="You should not murder";
	
	int x=compare(s,t);
	cout<<x<<endl;
	return 0;
}






	

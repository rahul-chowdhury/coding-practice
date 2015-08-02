#include<iostream>
#include<string>
using namespace std;
string s;

void comb(int n,char *a)
{
	if(n==0)
	{
		cout<<a;
		cout<<endl;
		return;
	}
	for(int i=0;i<s.length();i++)
	{
		bool check=true;
		for(int j=n;j<s.length();j++)
		{
			if(s[i]==a[j])
			{
				check=false;
				break;
			}
		}
		if(check==true)
		{
			a[n-1]=s[i];
			comb(n-1,a);
		}
	}
}

int main()
{
	s="123";
	char *a=new char[s.length()];
	comb(s.length(),a);
	return 0;
}
	

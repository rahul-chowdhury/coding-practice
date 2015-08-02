#include<bits/stdc++.h>
using namespace std;
typedef unsigned char byte;
bool check_encoding(byte *encoding,int n)
{
	int i=7,count=0;
	if(n==0)
		return true;
	if(n==1)
	{
		if(1<<7 & encoding[0] ==0)
			return true;
		return false;
	}
	while(i>=0 && ((1<<i & encoding[0])==1))
	{
		count++;
		i--;
	}
	for(i=1;i<=count;i++)
	{
		if(encoding[i] & 1<<7 !=1 || encoding[i] & 1<<6 !=0)
		{
			return false;
		}
	}
	return true;
}

void char_to_binary(char c)
{
	//string s="";
	cout<<sizeof(char)/sizeof(unsigned char)<<endl;
	for(int i=7;i>=0;i--)
	{
		cout<<!!(c>>7);
		c = c<<1;
		//cout<<c<<endl;
	}
	cout<<endl;
	//cout<<s<<endl;
}
int main()
{
	string s="€";
	char const *c = s.c_str();
	int n=sizeof(c)/sizeof(c[0]);
	/*for(int i=0;i<n;i++)
	{
	//cout<<c[i]<<endl;
	char_to_binary(c[i]);
	}*/
	char_to_binary('a');
	
	/*byte a[]={(byte)11101011, (byte)10110011, (byte)11110000};
	for(int i=0;i<3;i++)
		cout<<a[i]<<endl;
	if(check_encoding(a,3))
		cout<<"positive"<<endl;
	else
		cout<<"negative"<<endl;*/
	return 0;
}

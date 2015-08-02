#include<bits/stdc++.h>
using namespace std;



void print_byte(unsigned char c)
{
	for(int i=7;i>=0;i--)
	{
		if(c&(1<<i))
			cout<<1;
		else
		cout<<0;
	}
}
int main()
{
	string s = "this is my name";
	char const *c = s.c_str();
	int n = sizeof(c)/sizeof(c[0]);
	unsigned char new_string[n];
	 for(int i=0;i<n;i++)
	 {
	 	print_byte(c[i]);
	 	cout<<" ";
	 }
	 cout<<endl;
	for(int byte=n-1;byte>=0;byte--)
	{
		
		unsigned char temp=0;
		for(int bit=7;bit>=0;bit--)
		{
			temp |= (((c[byte]&(1<<bit))>>bit)<<(7-bit));
		}
		new_string[n-1-byte]=temp;
	}
	 for(int i=0;i<n;i++)
	 {
	 	print_byte(new_string[i]);
	 	cout<<" ";
	 }
	 cout<<endl;
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	string input;
	cout<<"enter input :";
	getline(cin,input);
	char c;
	int ascii[256],max=-1;
	for(int i=0;i<256;i++)
	{
		ascii[i]=0;
	}
	for(int i=0;i<input.length();i++)
	{
		ascii[input[i]]++;
		if(ascii[input[i]]>max)
		{
			max=ascii[input[i]];
			c=input[i];
		}
	}
	for(int i=input.length()-1;i>=0;i--)
	{
		if(input[i]==c)
		{
			cout<<"index is "<<i<<endl;
			break;
		}
	}
	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	string input;
	int x=0,start,end;
	cout<<"enter input :";
	getline(cin,input);
	for(int i=0;i<input.length()/2;i++)
	{
		char temp=input[i];
		input[i]=input[input.length()-1-i];
		input[input.length()-1-i]=temp;
	}
	cout<<input;
	while(x<input.length())
	{
		while(x<input.length() && input[x]==' ')
		x++;
		start=x;
		while(x<input.length() && input[x]!=' ')
		x++;
		end=x-1;
		cout<<"strat="<<start<<" end= "<<end<<endl;
		for(int i=start;i<=(start+end)/2;i++)
		{
			char temp=input[i];
			input[i]=input[end-i+start];
			input[end-i+start]=temp;
		}
		cout<<input;
	}
	cout<<input;
		
	return 0;
}

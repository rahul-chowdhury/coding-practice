#include<iostream>
using namespace std;
#include<string>

int main()
{
	int n;
	cin>>n;
	string words[n];
	for(int k=1;k<=n;k++)
	{
		cin>>words[k-1];
	}
	for(int k=1;k<=n;k++)
	{
		string s=words[k-1];
		int begin=0,end=s.length()-1,mistake=0,possible=1;
		while(end>begin )
		{
			if(s[begin]==s[end])
			{
				begin++;
				end--;
			}
			else
			{
				if(s[begin]==s[end-1])
				{
					end--;
					mistake++;
				}
				else if(s[begin+1]==s[end])
				{
					begin++;
					mistake++;
				}
				else
				{
					possible=0;
					break;
				}
			}
			if(mistake>1)
			{
				possible=0;
				break;
			}
		}
		if(possible==1)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}
			
			
			
			
			
			
			
			
			
			
			
			
				
				

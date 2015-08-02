#include<iostream>
using namespace std;
#include<string>

int main()
{
	int n;
	cin>>n;
	string set_of_words[n];
	for(int k=1;k<=n;k++)
	{
		cin>>set_of_words[k-1];
	}
	for(int k=1;k<=n;k++)
	{
		string s=set_of_words[k-1];
		
		int lds[s.length()];
		string words[s.length()];
		int maxLength = 1;
		lds[0] = 1;
		
		words[0]=s[0];
		for (int i = 1; i < s.length(); i++)
		{
		   lds[i] = 1;
		   
			words[i]=s[i];
		   for (int j = i - 1; j >= 0; j--)
		      if (lds[j] + 1 > lds[i] && words[j].find(s[i])>words[j].length())
		      {
			 lds[i] = lds[j] + 1;
			 
			 words[i]+=words[j];
			 
		      }

		   if (lds[i] > maxLength)
		   {
		      maxLength = lds[i];
		   }
		}
		cout<<maxLength<<endl;
	}
	return 0;
}

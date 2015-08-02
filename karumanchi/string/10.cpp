#include<bits/stdc++.h>
using namespace std;


void find_all_permutations(string original,bool *used,int depth,string *permutation)
{
	if(depth==original.length())
	{
		cout<<*permutation<<endl;
		return;
	}
	for(int i=0;i<original.length();i++)
	{
		if(used[i]==false)
		{
			used[i]==true;
			(*permutation)[depth]=original[i];
			//cout<<*permutation<<endl;
			find_all_permutations(original,used,depth+1,permutation);
			used[i]=false;
		}
	}
}


int main()
{
	string s= "radish";
	bool used[s.length()];
	string permutation=s;
	for(int i=0;i<s.length();i++)
	{
		used[i]=false;
	}
	find_all_permutations(s,used,0,&permutation);
	//cout<<s<<endl;
	return 0;
}	

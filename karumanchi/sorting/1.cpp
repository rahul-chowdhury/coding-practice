//#include<bits/stdc++.h>
#include<unordered_map>

#include<iostream>
using namespace std;

bool check_duplicates(int *a,int n)
{
	unordered_map<int,int>m;
	unordered_map<int,int>::iterator it;
	for(int i=0;i<n;i++)
	{
		if((it=m.find(a[i]))==m.end())
			m.insert(pair<int,int>(a[i],0));
		else 
			return true;
	}
	return false;
}

int main()
{
	int a[]={1,4,5,5,6};
	int n=sizeof(a)/sizeof(int);
	if(check_duplicates(a,n))
		cout<<"duplicate exists"<<endl;
	else
		cout<<"duplicate does not exist"<<endl;
	return 0;
}

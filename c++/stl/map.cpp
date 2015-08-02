#include<map>
#include<unordered_map>

#include<iostream>
#include<string>

using namespace std;

bool check_duplicate(int *a,int n)
{
	unordered_map<int,int> m;
	unordered_map<int,int>::iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(a[i]);
		if(it==m.end())
		{
			m.insert(pair<int,int>(a[i],1));
		}
		else
		{
			return true;
		}
	}
	return false;
}


bool check_same(int *a,int *b,int n)
{
	unordered_map<int,int> m;
	unordered_map<int,int>::iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(a[i]);
		if(it==m.end())
		{
			m[a[i]]=1;
		}
		else
		{
			m[a[i]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		it=m.find(b[i]);
		if(it==m.end() )
		{
			return false;
			
		}
		else
		{
			m[b[i]]--;
		}
		if(m[b[i]]==0)
		{
			m.erase(it);
		}
	}
	return true;
}
		
bool symmetric_pair(pair<int,int> *a,int n)
{
	unordered_map<int,int> m;
	unordered_map<int,int>::iterator it;
	for(int i=0;i<n;i++)
	{
		it=m.find(a[i].first);
		if(it==m.end())
		{
			m[a[i].first]=a[i].second;
		}
	}
	for(int i=0;i<n;i++)
	{
		it=m.find(a[i].second);
		if(it!=m.end() && it->second==a[i].first)
		{
			return true;
		}
	}
	
	return false;
}
int main()
{
	
	int a[]={1,2,4,6,5,7};
	int b[]={1,2,4,6,5,5};
	pair<int,int> c[]={make_pair(1,3),make_pair(3,5),make_pair(5,3)};
	int n=sizeof(a)/sizeof(a[0]);
	if(check_duplicate(a,n))
		cout<<"duplicate exists"<<endl;
	else
		cout<<"duplicate does not exist"<<endl;
	if(check_same(a,b,n))
		cout<<"same"<<endl;
	else
		cout<<"different"<<endl;
	if(symmetric_pair(c,3))
		cout<<"symmetric pair exists"<<endl;
	else
		cout<<"sym pair does not exist"<<endl;
	
	return 0;
}

#include<iostream>
#include<list>
#include<map>
using namespace std;
int main()
{
	list<int>l;
	map<int,int>m;
	l.push_back(5);
	l.push_back(6);
	l.push_back(2);
	l.push_back(1);
	l.push_back(3);
	l.push_back(5);
	l.push_back(9);
	l.push_back(0);
	for(list<int>::iterator i=l.begin();i!=l.end();i++)
	{
		if(m.find(*i)!=m.end())
		{
			cout<<"duplicate exists"<<endl;
			break;
		}
		else
		{
			m[*i]=*i;
		}
	}
	return 0;
}
	
		


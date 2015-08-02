#include<iostream>
#include<stack>
using namespace std;

stack<int>s,temp;
void sort()
{
	
	while(!s.empty())
	{
		int data=s.top();
		s.pop();
		temp.push(data);
	}
	
	while(!temp.empty())
	{
		int min=temp.top();
		temp.pop();
		//cout<<"dsfsf"<<endl;
		while(!s.empty() && s.top()<min)
		{
			int data=s.top();
			s.pop();
			temp.push(data);
		}
		s.push(min);
	}
}

int main()
{
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(1);
	s.push(2);
	
	sort();
	while(s.empty()==false)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}

#include<iostream>
#include<stack>
using namespace std;

stack<int>s;
void reverse()
{
	if(s.empty())
	return;
	int data=s.top();
	s.pop();
	reverse();
	s.push(data);
}

int main()
{
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	reverse();
	while(s.empty()==false)
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}

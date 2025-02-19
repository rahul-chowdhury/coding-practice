#include<iostream>
using namespace std;
#include<queue>
#include<stack>

queue<int> q,t;
stack<int> s;
void reverse()
{
	while(!q.empty())
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	
}

void sort()
{		
	while(!q.empty())
	{
		t.push(q.front());
		q.pop();
	}
	
	while(!t.empty())
	{
		int min=t.front();
		t.pop();
		while(!q.empty() && min<=q.front())
		{
			t.push(q.front());
			q.pop();
		}
		q.push(min);
	}
}
		
	
	
	
	
	
	
int main()
{
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(1);
	sort();
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	return 0;
}


#include <unistd.h>
#include<iostream>
using namespace std;
int main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
	cout<<"child"<<endl;
	}
	else
	{
	cout<<"parent"<<endl;
	cout<<"parent"<<endl;
	cout<<"parent"<<endl;
	cout<<"parent"<<endl;
	}
	return 0;
}

#include<iostream>
#include<stdlib.h>
#include <queue> 
#include <vector>
#include<climits>
using namespace std;

int main()
{

	vector<int>test;
	test.resize(5);
	test.assign(5,0);
	for(int i=0;i<5;i++)
	{
		cout<<test[i]<<endl;
	}
	test.resize(6);
	test[5]=9;
	for(int i=0;i<6;i++)
	{
		cout<<test[i]<<endl;
	}
	return 0;
}

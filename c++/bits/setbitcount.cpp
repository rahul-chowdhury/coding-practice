#include<iostream>
#include<limits.h>
using namespace std;
int min(int x,int y)
{
	return y+((x-y)&((x-y)>>(31)));
}
int main()
{
	int x=INT_MAX,y=-597,z=2,biti,bitj,i=0,j=5,test;
	int div=4;
	x=x^1;
	
	cout<<"x="<<x<<endl;
	return 0;
}

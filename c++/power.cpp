#include<iostream>
using namespace std;

int power(int a,int b)
{	

	if(b==0)
	return 1;
	int temp=power(a,b/2);
	if(b%2==0)
	return temp*temp;
	else
	{
	if(b>0)
	return a*temp*temp;
	}
	
}

int main()
{
	cout<<power(4,5)<<endl;
}

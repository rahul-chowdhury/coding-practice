#include<iostream>
using namespace std;
int sum_of_digits(int n)
{
	if(n==1)
		 return 1;
	else
	{
		int temp=n,sum=0;
		while(temp!=0)
		{
			sum += temp%10;
			temp /=10;
		}
		return sum+sum_of_digits(n-1);
	}
}
int main()
{
	int n;
	cout<<"input:";
	cin>>n;
	cout<<"output: "<<sum_of_digits(n)<<endl;
	 return 0;
}


#include<iostream>
using namespace std;
void reverse(int *a,int start,int end)
{
	while(start<end)
	{
		int temp=a[start];
		a[start]=a[end];
		a[end]=temp;
		start++;
		end--;
	}
}
void rotate(int *a,int n,int d)
{
	reverse(a,0,d);
	reverse(a,d+1,n-1);
	reverse(a,0,n-1);
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int n=7;
	rotate(a,n,3);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}

#include<iostream>
#include<string>

using namespace std;



void insertion(int *a,int n)
{
	int j,temp;
	for(int i=1;i<n;i++)
	{
		j=i;
		temp=a[i];
		while(j>=1 && a[j-1]>a[i])
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=temp;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void shell(int *a,int n)
{
	int j,temp,h=n-1;
	for(;h>=1;h=h/3)
	{
		for(int i=h+1;i<n;i++)
		{
			j=i;
			temp=a[i];
			while(j>=h+1 && a[j-h]>a[i])
			{
				a[j]=a[j-h];
				j=j-h;
			}
			a[j]=temp;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	
	int a[]={1,2,4,6,5,7};
	int n=sizeof(a)/sizeof(a[0]);
	insertion(a,n);
	shell(a,n);
	return 0;
}

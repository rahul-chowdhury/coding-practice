#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int *a,int low,int high)
{
	for(int i=low;i<high;i++)
	{
		for(int j=low;j<high-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

int main()
{
	int a[]={2,4,56,77,8,99,0,-112};
	bubble_sort(a,0,sizeof(a)/sizeof(int)-1);
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

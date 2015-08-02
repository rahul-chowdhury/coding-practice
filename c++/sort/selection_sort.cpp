#include <bits/stdc++.h>
using namespace std;

void selection_sort(int *a,int low,int high)
{
	int min_pos,temp;
	for(int i=low;i<high;i++)
	{
		min_pos=i;
		for(int j=i+1;j<=high;j++)
		{
			if(a[j]<a[min_pos])
			{
				min_pos=j;
			}
		}
		temp=a[i];
		a[i]=a[min_pos];
		a[min_pos]=temp;
	}
}

int main()
{
	int a[]={2,4,56,77,8,99,0,-112};
	selection_sort(a,0,sizeof(a)/sizeof(int)-1);
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

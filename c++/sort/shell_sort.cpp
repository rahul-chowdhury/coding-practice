#include <bits/stdc++.h>
using namespace std;
#define SHELL_SORT_CONSTANT 3
void shell_sort(int *a,int low,int high)
{
	int min,temp,j;
	for(int h=(int)(pow(SHELL_SORT_CONSTANT,floor(log(high-low+1)/log(SHELL_SORT_CONSTANT))));h>=1;h=h/SHELL_SORT_CONSTANT)
	{
		//cout<<h<<endl;
		for(int i=h+low;i<=high;i++)
		{
			temp=a[i];
			j=i-h;
			while(j>=low && a[j]>temp)
			{
				a[j+h]=a[j];
				j=j-h;
			}
			a[j+h]=temp;
		
		}
	}
}

int main()
{
	int a[]={2,4,56,77,8,99,0,-112};
	shell_sort(a,0,sizeof(a)/sizeof(int)-1);
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}

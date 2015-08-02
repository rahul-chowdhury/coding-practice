#include <bits/stdc++.h>
using namespace std;

int * counting_sort(int *a,int n,int k,int *b)//n=no. of elements in the array ; k=max possible no. of values in the array
{
	int c[k];
	
	for(int i=0;i<k;i++)
		c[i]=0;

	for(int i=0;i<n;i++)
		c[a[i]]++;
		
	for(int i=1;i<k;i++)
		c[i]=c[i]+c[i-1];
		
	for(int i=n-1;i>=0;i--)//to make this stable sort
	{
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
	
	
}

int main()
{
	clock_t t1=clock();
	int a[]={2,4,-56,77,8,99,0,-12,3,54,78,245,7,454,8976,3,3,35,2,-5,24,54,776};
	int b[sizeof(a)/sizeof(int)];
	int min=a[0],max=a[0];
	for(int i=1;i<sizeof(a)/sizeof(int);i++)
	{
		if(a[i]<min)
			min=a[i];
		if(a[i]>max)
			max=a[i];
	}
	if(min<0)//scaling up for negative values
	{
		for(int i=0;i<sizeof(a)/sizeof(int);i++)
		{
			a[i]+=-min;
		}
	}
	
	counting_sort(a,sizeof(a)/sizeof(int),max+1+-min,b);
	cout<<clock()-t1<<endl;
	if(min<0)//scaling down to get original values
	{
		for(int i=0;i<sizeof(a)/sizeof(int);i++)
		{
			b[i]-=-min;
		}
	}
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		cout<<b[i]<<" ";
	}
	
	cout<<endl;
	return 0;
}

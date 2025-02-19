#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int min(int a,int b)
{
	if(a>b)
		return b;
	return a;
}

pair<int,int> find_max_product_pair(int *a,int n)
{
	if(n==0 || n==1)
		return make_pair(0,0);
	int max1=max(a[0],a[1]),max2=min(a[0],a[1]),min1=min(a[0],a[1]),min2=max(a[0],a[1]),temp;
	for(int i=2;i<n;i++)
	{
		if(a[i]>=max1)
		{
			temp=max1;
			max1=a[i];
			max2=temp;
		}
		if(a[i]<max1 && a[i]>max2)
		{
			max2=a[i];
		}
		if(a[i]<=min1)
		{
			temp=min1;
			min1=a[i];
			min2=temp;
		}
		if(a[i]>min1 && a[i]<min2)
		{
			min2=a[i];
		}
	}
	
	if(max1*max2 > min1*min2)
	{
		return make_pair(max1,max2);
	}
	else
	{
		return make_pair(min1,min2);
	}
}
	
	
int main()
{
    int arr[] = {-1, -3, -4, 2, 0, -5} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    pair<int, int> max_product;
    max_product=find_max_product_pair(arr, n);
    cout<<"pair is "<<max_product.first<<","<<max_product.second<<endl;
    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		

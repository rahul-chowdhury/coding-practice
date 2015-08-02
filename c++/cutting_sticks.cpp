#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;
int coord[50][50],a[50];
int minimum(int a,int b)
{
	if(a<b)return a;
	return b;
}
int cut(int left,int right)
{
	if(right==left+1)
		return 0;
	int cost=INT_MAX;
	for(int i=left+1;i<right;i++)
	{
		if(coord[left][i]==-1)  
			coord[left][i]=cut(left,i);
		
		if(coord[i][right]=-1)
			coord[i][right]=cut(i,right);
				
		cost=minimum(cost,coord[left][i]+coord[i][right]+(a[right]-a[left]));
	}
	return cost;
}	
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int n,l;
	cout<<"enter n:";
	cin>>n;
	cout<<"enter l:";
	cin>>l;
	for(int i=0;i<50;i++)
	for(int j=0;j<50;j++)
	coord[i][j]=-1;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
	cout<<"enter the coordinate of cut "<<i<<":";
	cin>>a[i];
	}
	a[n+1]=l;
	qsort(a,n+2,sizeof(int),compare);
	cout<<"minimum cost is "<<cut(0,n+1)<<endl;
	return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int max(int a,int b)
{
if(a>b)return a;
return b;
}

int main() {
   int edges,no_of_nodes,src,dest,wgt;
   cin>>no_of_nodes;
   cin>>edges;
   int a[no_of_nodes][no_of_nodes];
   //for(int i=0;i<no_of_nodes;i++)
   {
   	 for(int j=0;j<no_of_nodes;j++)
   {
   a[i][j]=-1;
   }
}
   //struct node *root=(struct node *)malloc(sizeof(struct node));
   for(int i=0;i<edges;i++)
   {
   	cin>>src;
   	cin>>dest;
   	cin>>wgt;
   	a[src-1][dest-1]=wgt;
   	
   	
   	for(int j=0;j<no_of_nodes;j++)
   	{
   		if(a[j][src-1]>=0)
   		{
   			a[j][dest-1]=max(a[j][src-1]+a[src-1][dest-1],a[j][dest-1]);
   		}
   	}
   }
   	
   	cout<<a[0][no_of_nodes-1]<<endl;
   	
   
   
    return 0;
}


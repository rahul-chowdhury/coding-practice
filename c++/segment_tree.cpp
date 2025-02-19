#include<iostream>
#include <vector>
#include<stdlib.h>
#include<math.h>
using namespace std;
struct node
{
	int start,end,sum;
};
int fill_segment_tree(int a[],vector<struct node>segtree,int first,int last,int current_node);
void make_segment_tree(int a[],vector<struct node>segtree,int n)
{
	int height=(int)ceil(log2(n));
	int maxsize=2*(int)pow(2,height)-1;
	segtree.resize(maxsize);
	fill_segment_tree(a,segtree,0,n-1,0);
}

int fill_segment_tree(int a[],vector<struct node>segtree,int first,int last,int current_node)
{
	if(first=last)
	{
		segtree[current_node].sum=a[first];
		return a[first];
	}
	int mid=(first+last)/2;
	segtree[current_node].sum=fill_segment_tree(a,segtree,0,mid,2*current_node+1)+fill_segment_tree(a,segtree,mid+1,last,2*current_node+2);
	return segtree[current_node].sum;
}

int main()
{return 0;}


#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;
int matrix[50][50],start,end,num_of_vertices,length[50];

void traverse(int vertex)
{
	if(vertex==end)
		return;
	for(int i=1;i<=num_of_vertices;i++)
	{
		if(matrix[vertex][i]==1)
		{
			if(length[i]<=length[vertex]+1)
			{
				continue;
			}
			else
			{
				length[i]=length[vertex]+1;
				traverse(i);
			}
		}
	}
}

int main()
{
	int e;
	cout<<"enter the number of vertices :";
	cin>>num_of_vertices;
	cout<<"enter the number of edges :";
	cin>>e;
	cout<<"enter edges:"<<endl;
	for(int i=1;i<=num_of_vertices;i++)
	{
		for(int j=1;j<=num_of_vertices;j++)
		{
			matrix[i][j]=0;
		}
	}
	for(int i=1;i<=e;i++)
	{
		
		cout<<"edge "<<i<<":\nenter source :";
		int source;
		cin>>source;
		cout<<"enter destination :";
		int dest;
		cin>>dest;
		matrix[source][dest]=1;
		matrix[dest][source]=1;
	}
	for(int i=1;i<=num_of_vertices;i++)
	{
		length[i]=INT_MAX;
	}
	cout<<"enter start vertex:";
	cin>>start;
	cout<<"enter end vertex:";
	cin>>end;
	length[start]=0;
	traverse(start);
	if(length[end]>e)
	{
		cout<<"no path exists"<<endl;
	}
	else
		cout<<"path length="<<length[end]<<endl;
	
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

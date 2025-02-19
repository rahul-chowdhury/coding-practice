#include<iostream>
#include<limits.h>
#define INF 99999
#define V 4
using namespace std;
int min(int a,int b)
{
	//cout<<"ll"<<endl;
	return (a<b)?a:b;
}
void print(int a[][V])
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			if(a[i][j]==INF)
			cout<<"  ";
			else
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void floydWarshell(int a[][V])
{
	for(int i=0;i<V;i++)
	{
	a[i][i]=0;
	}
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
			
			
				
			a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			print(a);
			cout<<endl;
			}
		}
	}
}
			

	
int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floydWarshell(graph);
    print(graph);
    return 0;
}

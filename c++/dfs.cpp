#include<iostream>
#include<stdlib.h>
#include <queue> 
#include <vector>
#include<climits>
using namespace std;
int time1=0;
typedef struct edge
{
	
	int destination;
	int weight;
	struct edge *next;
}edge;

typedef struct graph
{
	vector<edge *> edge_list;
	bool directed;
	int no_of_edges;
	int no_of_vertices;
	vector<int>outdegree;
	vector<bool >discovered;
	vector<int >parent;
	vector<int >distance_from_source;
	vector<bool>processed;
	vector<int>entry_time;
	vector<int>exit_time;
}graph;

void initialize_graph(graph *g,int v)
{
	g->edge_list.resize(v);
	g->edge_list.assign(v,NULL);
	g->outdegree.resize(v);
	g->outdegree.assign(v,0);
	g->discovered.resize(v);
	g->discovered.assign(v,false);
	g->processed.resize(v);
	g->processed.assign(v,false);
	g->parent.resize(v);
	g->parent.assign(v,-1);
	g->distance_from_source.resize(v);
	g->distance_from_source.assign(v,INT_MAX);
	g->no_of_vertices=v;
	g->entry_time.resize(v);
	g->entry_time.assign(v,-1);
	g->exit_time.resize(v);
	g->exit_time.assign(v,-1);
}
void display_graph(graph *g)
{
	for(int i=0;i<g->no_of_vertices;i++)
	{
	
		cout<<i;
		edge *new_edge=g->edge_list[i];
		while(new_edge!=NULL)
		{
			cout<<"-->"<<new_edge->destination;
			new_edge=new_edge->next;
		}
		cout<<endl;
	}
}

void display_start_end(graph *g)
{
	for(int i=0;i<g->no_of_vertices;i++)
	{
	
		cout<<i<<":"<<g->entry_time[i]<<" "<<g->exit_time[i]<<endl;
		
	}
}

		
void depth_first_search(graph *g,int vertex)
{
	g->entry_time[vertex]=time1++;	
	int e,e1;
	edge *new_edge=g->edge_list[vertex];
	g->discovered[vertex]=true;
	while(new_edge)
	{
		if(g->discovered[new_edge->destination]==false)
		{
			
			depth_first_search(g,new_edge->destination);
			
		}
		new_edge=new_edge->next;
		
	}
	g->exit_time[vertex]=time1++;
	g->processed[vertex]=true;
}
int main()
{
	int v;
	cout<<"enter the no. of vertices :";
	cin>>v;

	graph *g=(graph *)malloc(sizeof(graph));
	initialize_graph(g,v);
	for(int i=0;i<v;i++)
	{
		cout<<"enter outdegree of vertex "<<i<<":";
		cin>>g->outdegree[i];
		for(int j=1;j<=g->outdegree[i];j++)
		{
			int x;
			cout<<"enter outgoing vertex "<<j<<":";
			cin>>x;
			edge *e=(edge *)malloc(sizeof(edge));
			e->destination=x;
			edge *temp=g->edge_list[i];
			g->edge_list[i]=e;
			e->next=temp;
		}
	}
	
	display_graph(g);
	depth_first_search(g,0);
	display_start_end(g);
	return 0;
}

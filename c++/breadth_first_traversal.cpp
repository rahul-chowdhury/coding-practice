#include<iostream>
#include<stdlib.h>
#include <queue> 
#include <vector>
#include<climits>
using namespace std;
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

void display_distance_from_source(graph *g)
{
	for(int i=0;i<g->no_of_vertices;i++)
	{
	
		cout<<i<<":"<<g->distance_from_source[i]<<endl;
		
	}
}

		
void breadth_first_search(graph *g,int start_vertex)
{
	queue<int> vertex_queue;	
	int e,e1;
	edge *new_edge;
	vertex_queue.push(start_vertex);
	g->distance_from_source[start_vertex]=0;
	g->discovered[start_vertex]=true;
	while(!vertex_queue.empty())
	{
		e=vertex_queue.front();
		vertex_queue.pop();
		cout<<e<<" ";
		new_edge=g->edge_list[e];
		while(new_edge!=NULL)
		{
			e1=new_edge->destination;
			if(g->discovered[e1]==false)
			{
				vertex_queue.push(e1);
				g->discovered[e1]=true;
				g->parent[e1]=e;
				g->distance_from_source[e1]=g->distance_from_source[e]+1;
			}
			new_edge=new_edge->next;
		}
		g->processed[start_vertex]=true;
	}
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
	breadth_first_search(g,0);
	display_distance_from_source(g);
	return 0;
}

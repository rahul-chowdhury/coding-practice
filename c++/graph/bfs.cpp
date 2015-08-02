#include<iostream>
#include<list>
#include<queue>
using namespace std;

struct graph
{
	int V;
	list<int> *adj;
};
list<int> stack,stack2;
void initialize(struct graph *g,const int & a)
{	
	g->V=a;
	g->adj=new list<int>[a];
}

void bfs(struct graph *g,int start)
{
	bool *visited=new bool[g->V];
	for(int i=0;i<g->V;i++)
	visited[i]=false;
	visited[start]=true;
	list<int> queue;
	queue.push_back(start);
	list<int>:: iterator i;
	while(!queue.empty())
	{
		int u=queue.front();
		queue.pop_front();
		cout<<u<<" ";
		for(i=g->adj[u].begin();i!=g->adj[u].end();i++)
		{
			if(visited[*i]==false)
			{
				queue.push_back(*i);
				visited[*i]=true;
			}
		}
	}
	cout<<endl;
}

bool bipartite(struct graph *g,int start)
{
	int *color=new int[g->V];
	for(int i=0;i<g->V;i++)
	color[i]=-1;
	queue<int>q;
	color[start]=0;
	q.push(start);
	list<int>:: iterator i;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		//cout<<u<<" ";
		for(i=g->adj[u].begin();i!=g->adj[u].end();i++)
		{
			if(color[*i]==color[u])
			{
				return false;
			}
			else
			{
				color[*i]=1-color[u];
				q.push(*i);
			}
		}
	}
	return true;
}

void dfs(struct graph *g,int vertex,bool *visited)
{
	
	visited[vertex]=true;
	stack.push_front(vertex);
	list<int>:: iterator i,j;
	cout<<vertex<<" ";
	for(i=g->adj[vertex].begin();i!=g->adj[vertex].end();i++)
	{
		if(visited[*i]==true)
		{
			for(j=stack.begin();j!=stack.end();j++)
			{
				if(*i==*j)
				cout<<"cycle exists"<<endl;
			}
		}
		if(visited[*i]==false)
		{
			dfs(g,*i,visited);
		}
	}
	stack.pop_front();

	
}

void topo_sort(struct graph *g,int vertex,bool *visited)
{
	
	visited[vertex]=true;
	
	list<int>:: iterator i,j;
	//cout<<vertex<<" ";
	for(i=g->adj[vertex].begin();i!=g->adj[vertex].end();i++)
	{
		
		if(visited[*i]==false)
		{
			topo_sort(g,*i,visited);
		}
	}
	//cout<<vertex<<" ";
	stack2.push_front(vertex);

	
}		
	

int main()
{
	struct graph *g=new struct graph;
	initialize(g,6);
	g->adj[5].push_back(2);
	g->adj[5].push_back(0);
	g->adj[4].push_back(0);
	g->adj[4].push_back(1);
	g->adj[2].push_back(3);
	g->adj[3].push_back(1);
	
	//bfs(g,2);
	bool *visited=new bool[g->V];
	for(int i=0;i<g->V;i++)
	visited[i]=false;
	//dfs(g,2,visited);
	cout<<endl;
	for(int i=0;i<g->V;i++)
	visited[i]=false;
	for(int i=0;i<g->V;i++)
	{
	if(visited[i]==false)
	topo_sort(g,i,visited);
	}
	while(stack2.empty()==false)
	{
	cout<<stack2.front()<<" ";
	stack2.pop_front();
	}
	cout<<endl;
	
	bool check=bipartite(g,0);
	if(check==true)
	cout<<"bipartite"<<endl;
	else
	cout<<"not bipartite"<<endl;
	return 0;
}


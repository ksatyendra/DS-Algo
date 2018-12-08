#include<iostream>
#include<list>
#include<stdio.h>

using namespace std;

struct Graph
{
	int V;
	list<int> *adj;
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int a, int b)
	{
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};
int main()
{
	int v,e,a,b;  list<int>::iterator it;
	cout<<"\nEnter no. of Vertex : "; cin>>v;
	cout<<"\nEnter no. of Edges : ";  cin>>e;
	Graph G(v);
	for(int i=0; i< e; i++)
	{
		printf("\nEnter %d Edge start and end : ", i+1);
		cin>>a>>b;
		G.addEdge(a,b);
	}
	b = 0;
	for(int i=0; i < v; i++)
	{
		cout<<i<<"->";
		for(it = G.adj[i].begin(); it!=G.adj[i].end(); it++)
			cout<<" -> "<<*it;
		cout<<"\n";
	}
	for(int i=0; i<v; i++)
		if(G.adj[i].empty())
		{
			cout<<"\nNot Connected !\n"; b=0; break;
		}
		else
			b = 1;
	if(b)
		cout<<"\nConnected !\n";
}
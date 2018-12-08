#include<iostream>
#include<list>
#include<stdio.h>
#include<vector>
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
	}
	void BFS(int s);
};
void Graph::BFS(int s)
{
	int visited[V];
	for(int i=0; i<V; i++)
		visited[i] = 0;
	list<int> Q;
	visited[s] = 1;
	Q.push_back(s);   list<int>::iterator it;
	while(!Q.empty())
	{
		s = Q.front();
		Q.pop_front();
		cout<<s<<" ";
		for(it = adj[s].begin(); it != adj[s].end(); ++it)
        {
            if(!visited[*it])
            {
                visited[*it] = 1;
                Q.push_back(*it);
            }
        }
	}
}

int main()
{
	int v=6,e,a,b;  list<int>::iterator it;
	//cout<<"\nEnter no. of Vertex : "; cin>>v;
	//cout<<"\nEnter no. of Edges : ";  cin>>e;
	Graph G(v);
	/*for(int i=0; i< e; i++)
	{
		printf("\nEnter %d Edge start and end : ", i+1);
		cin>>a>>b;
		G.addEdge(a,b);
	}*/
	G.addEdge(0,1);G.addEdge(0,2); G.addEdge(1,4); G.addEdge(2,1); G.addEdge(2,3);
	G.addEdge(2,4); G.addEdge(2,5); G.addEdge(3,0); G.addEdge(3,5); G.addEdge(4,5);
	for(int i=0; i < v; i++)
	{
		cout<<i<<"->";
		for(it = G.adj[i].begin(); it!=G.adj[i].end(); it++)
			cout<<" -> "<<*it;
		cout<<"\n";
	}
	cout<<"\nEnter Starting Vertex for BFT : "; cin>>a;
	cout<<"\n";
	G.BFS(a);
	return 0;
}

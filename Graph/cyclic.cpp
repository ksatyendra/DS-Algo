#include<bits/stdc++.h>
using namespace std;

struct Graph
{
	int V;
	list<int> *adj;
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int a, int b){
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};
int main()
{
	int v,e,a,b;  list<int>::iterator it;
	cout<<"\nEnter no. of Vertex : "; cin>>v;
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

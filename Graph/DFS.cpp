#include<iostream>
#include<list>
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
	void DFS(int s);
};
void Graph::DFS(int s)
{
	int visited[V]; list<int>::iterator it;
	for(int i=0; i<V; i++) visited[i] = 0;
	list<int> stack;  stack.push_front(s); visited[s] = 1;
	while(!stack.empty())
	{
		s = stack.front(); stack.pop_front();
		cout<< s << " ";
		for(it = adj[s].begin(); it != adj[s].end(); ++it)
         if(!visited[*it]) visited[*it] = 1,stack.push_front(*it);
	}
}
int main()
{
	int v=7,e,a,b;  list<int>::iterator it;	Graph G(v);
	G.addEdge(0,1);G.addEdge(0,2); G.addEdge(1,4); G.addEdge(2,1); G.addEdge(2,3);
	G.addEdge(2,4); G.addEdge(2,5); G.addEdge(3,0); G.addEdge(3,5); G.addEdge(4,5);
	for(int i=0; i < v; i++)
	{
		cout<<i<<"->";
		for(it = G.adj[i].begin(); it!=G.adj[i].end(); it++) cout<<" -> "<<*it;
		cout<<"\n";
	}
	cout<<"\nEnter Starting Vertex for DFT : "; cin>>a;	G.DFS(a);
}
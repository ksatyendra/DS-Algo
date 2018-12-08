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
		//adj[b].push_back(a);
	}

};
int DFS(Graph G,int s, int visited[],int &t)
{
	visited[s] = 1;list<int>::iterator it;
	t++;  //cout<<" "<<s;
	for(it = G.adj[s].begin(); it != G.adj[s].end(); it++)
		if(!visited[*it])
			DFS(G, *it,visited,t);
}
int startToend(Graph G,int st,int v)
{
	int visited[v];
	for(int t=0; t<v; t++)
		visited[t]=0;
    int t = 0;
    DFS(G,st,visited,t);
	if(t == v){
        //cout<<"Yeah!\n";
        return 1;
	}
	//cout<<"Nope !\n";
	return 0;
}
int main()
{
	int v=6,e,a,b;  list<int>::iterator it;
	//cout<<"\nEnter no. of Vertex : "; cin>>v; //int visited[v];
	//cout<<"\nEnter no. of Edges : ";  cin>>e;
	Graph G(v);
	/*for(int i=0; i< e; i++)
	{
		printf("\nEnter %d Edge start and end : ", i+1);
		cin>>a>>b;
		G.addEdge(a,b);
	}*/
	G.addEdge(0,1); G.addEdge(0,2); G.addEdge(1,3); G.addEdge(2,3); G.addEdge(3,0); G.addEdge(4,5);G.addEdge(5,4);
	G.addEdge(5,0);
	b = 0;
	for(int i=0; i < v; i++)
	{
		cout<<i<<"->"; //visited[i]=0;
		for(it = G.adj[i].begin(); it!=G.adj[i].end(); it++)
			cout<<" -> "<<*it;
		cout<<"\n";
	}
	for(int i=0; i<v; i++)
	{
		if(startToend(G,i,v)){
			b=1; //cout<<"Hi!";
		}
		else{
			b = 0; break;
        }
	}
	if(b)
		cout<<"\nStrongly Connected !\n";
	else
	{
		for(int i=0; i<v; i++)
			if(startToend(G,i,v)){
			b=1; //cout<<"Hi!";
		}
		else{
			b = 0; break;
        }
        if(b)
            cout<<"\nWeakly Connected !";
        else
            cout<<"\nNot Connected !";
	}
	cout<<"\n\n";
	return 0;
}

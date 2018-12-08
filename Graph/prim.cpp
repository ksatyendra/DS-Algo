#include<iostream>
#include<stdio.h>
#include<vector>
#include <iomanip>
#include <list>
using namespace std;
#define V 7
#define MAX 1000
struct MyType{
	int visited;
	int wt;
	int Pv;
	MyType(){
		visited = 0; wt = MAX; Pv = 0;
	}
};
void addEdge(vector<vector<int> > & G, int a, int b, int wt)
{
	G[a][b] = wt;
	G[b][a] = wt;
}
void display(MyType D[])
{
	cout<<"\n----Dijkstra's Table-----\n";
	cout<<" "<<setw(4)<<"Vs"<<setw(4)<<"Pv"<<setw(4)<<"Wt\n";
	for(int i=0; i<V; i++)
	{
		cout<<setw(4)<<D[i].visited<<setw(4)<<D[i].Pv;
		if(D[i].wt == MAX)
		cout<<setw(4)<<"*"<<"\n";
		else
		cout<<setw(4)<<D[i].wt<<"\n";
	}
}
int minWeight(MyType D[])
{
	int MIN = MAX;
	int j = 0;
	for(int i=0; i<V; i++)
	{
		if(D[i].wt < MIN && D[i].visited==0)
		{
			MIN = D[i].wt; j = i;
		}
	}
	return j;
}
int main()
{
	vector<vector<int> > G;  int i,j=0,st,count=0;  vector<int> ar; MyType D[10];
	for( i= 0 ;i <V; i++)
	{
		for(j=0; j < V; j++)
			ar.push_back(0);
		G.push_back(ar);
	}
	addEdge( G, 0,1,2); addEdge( G, 0,3,1); addEdge( G, 1,3,3); addEdge( G, 1,4,10);
	addEdge( G, 2,0,4); addEdge( G, 2,5,5); addEdge( G, 3,2,2); addEdge( G, 3,4,7);
	addEdge( G, 3,5,8); addEdge( G, 3,6,4); addEdge( G, 4,6,6); addEdge( G, 6,5,1);
	cout<< "\nEnter Starting Vertex : "; cin>>st;
	j=0;
	D[st].wt = 0; D[st].Pv = -1;
	while( j < V)
	{
		D[st].visited = 1;
		for(i=0; i < V; i++)
		{
			if(G[st][i]!=0)
            {
                if(!D[i].visited && D[i].wt > G[st][i]){
                    D[i].wt = G[st][i] ;
                    D[i].Pv = st;
                }
            }
		}
		//display(D);
		st = minWeight(D);
		j++;
	}
	for(i=0;i<V; i++)
        count+=D[i].wt;
    cout<< "\nMinimum Length : "<<count<<"\n";
	return 0;
}

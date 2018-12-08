#include<iostream>
#include<stdio.h>
#include<vector>
#include <iomanip>
#include <list>
using namespace std;
#define V 7

struct MyType{
	int visited;
	int wt;
	int Pv;
	MyType(){
		visited = 0; wt = INT_MAX; Pv = 0;
	}
};
void addEdge(vector<vector<int> > & G, int a, int b, int wt){
	G[a][b] = wt;
}
void display(MyType D[]){
	cout<<"\n\n----Dijkstra's Table-----\n";
	for(int i=0; i<V; i++){
		cout<<setw(4)<<D[i].visited<<setw(4)<<D[i].Pv;
		if(D[i].wt == INT_MAX)
		cout<<setw(4)<<"0"<<"\n";
		else
		cout<<setw(4)<<D[i].wt<<"\n";
	}
	cout<<"\n";
}
int minWeight(MyType D[]){
	int MIN = INT_MAX;
	int j = 0;
	for(int i=0; i<V; i++){
		if(D[i].wt < MIN && !D[i].visited){
			MIN = D[i].wt; j = i;
		}
	}
	return j;
}
void displayPath(MyType D[], int st, int end){
    int i=end;
    cout<<"\n\n-------Path From End to Start-----\n\n";
    while(i!=st){
        cout<<"["<<i+1<< "]-->";
        i = D[i].Pv;
    }
    cout<<"["<<i+1<< "]";
    cout<<"\n\nDistance Travel : "<<D[end].wt<< "\n";
}
int main()
{
	vector<vector<int> > G;  int i,j=0,st,end,cur;  vector<int> ar; MyType D[10];
	for( i= 0 ;i <V; i++){
		for(j=0; j < V; j++)
			ar.push_back(0);
		G.push_back(ar);
	}
	addEdge( G, 0,1,2); addEdge( G, 0,3,1); addEdge( G, 1,3,3); addEdge( G, 1,4,10);
	addEdge( G, 2,0,4); addEdge( G, 2,5,5); addEdge( G, 3,2,2); addEdge( G, 3,4,2);
	addEdge( G, 3,5,8); addEdge( G, 3,6,4); addEdge( G, 4,6,6); addEdge( G, 6,5,1);
	cout<< "\nEnter Starting Vertex : "; cin>>st;
	cout<< "\nEnter End Point : "; cin>>end;
	cur = st;
	D[cur].wt = 0; D[cur].Pv = cur;
	while(cur!=end){
		D[cur].visited = 1;
		for(i=0; i < V; i++){
			if(G[cur][i]!=0 && !D[i].visited){
                if(D[cur].wt + G[cur][i] < D[i].wt){
                    D[i].wt = D[cur].wt + G[cur][i] ;
                    D[i].Pv = cur;
                }
            }
		}
		cur = minWeight(D);
	}
    displayPath(D,st,end);
	return 0;
}

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define V 7
#define E 12
struct Edge{
	int src;
	int dst;
	int Wt;
};
bool compare(const Edge &a, const Edge &b){
    return (a.Wt < b.Wt);
}
void addEdge(Edge &D,int a, int b, int wt)
{
	D.Wt = wt; D.src = a; D.dst = b;
}
int find(int S[], int X)
{
    if(S[X] == -1)
        return X;
    else
       return S[X] = find(S, S[X]);
}
void Union(int S[], int a, int b)
{
    if(S[b] == -1)
        S[b] = a;
    else
    {
        if(S[a]==-1)
            S[a] = b;
        else
            Union(S,S[a],b);
    }
}
int main()
{
    int G[V][V] = {
        {0,2,4,1,0,0,0},
        {2,0,0,3,10,0,0},
        {4,0,0,2,0,5,0},
        {1,3,2,0,2,8,4},
        {0,10,0,2,0,0,6},
        {0,0,5,8,0,0,1},
        {0,0,0,4,6,1,0}
    };
	int i,j=0,X,Y,count=0; Edge D[E]; int S[V];
	for( i= 0 ;i <V; i++)
	{
		S[i] = -1;
	}
	addEdge( D[0] ,0,1,2); addEdge( D[1] , 0,3,1); addEdge( D[2] , 1,3,3); addEdge( D[3] , 1,4,10);
	addEdge( D[4] ,2,0,4); addEdge( D[5] , 2,5,5); addEdge( D[6] , 3,2,2); addEdge( D[7] , 3,4,7);
	addEdge( D[8] ,3,5,8); addEdge( D[9] , 3,6,4); addEdge( D[10],4,6,6); addEdge( D[11] , 6,5,1);
	sort(D , D+E, compare);
    for(i=0; i<E; i++)
    {
        X = find(S, D[i].src);
        Y = find(S, D[i].dst);
        //cout<<X<< " "<< Y<<"\n";
        if(X!=Y)
        Union(S, X, Y);
    }
    cout<<"\nDisplaying Set : \n";
    for(i=0; i< V; i++)
        cout<<" "<<S[i];
    cout<<"\n";
    for(i=0; i< V; i++)
    {
        if(S[i]!=-1)
            count += G[i][S[i]];
    }
    cout<<"\nShortest Length : "<<count<<"\n\n";;
	return 0;
}

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#define V 10
#define E 15
using namespace std;
struct Vertex{
    int count;
    int index;
};
bool compare(Vertex V1,Vertex V2)
{
    return (V1.count < V2.count);
}
void DFS(int G[][V], int st, int visited[], stack<int> &Index){
    stack<int> S;
    S.push(st); visited[st]=1;
    while(!S.empty()){
        st = S.top(); S.pop();
        cout<<" "<<st; Index.push(st);
        for(int i=0; i<V; i++){
            if(G[st][i]!=0 && !visited[i]){
                visited[i] = 1;
                S.push(i);
            }
        }
    }
    cout<<"\n";
}
int main(){
    int G[V][V] = {
        {0,1,0,1,0,0,0,0,0,0},
        {0,0,1,0,0,1,0,0,0,0},
        {1,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,1,0,1,0,0},
        {0,0,0,0,0,1,0,0,0,1},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0},
    };
    int T[V][V]; stack<int> Index;
	int i,j=0,count=0;  int visited[V]; vector<Vertex> rank; Vertex tmp;
	for( i= 0 ;i <V; i++){
	    for(j=0; j < V; j++)
            T[i][j] = G[j][i];
		visited[i] = 0;
	}
	for(i=0; i<V; i++){
        if(!visited[i])
            DFS(G, i, visited,Index);
        while(!Index.empty()){
            tmp.index = Index.top(); Index.pop();
            tmp.count = count++;
            rank.push_back(tmp);
        }
	}
	sort(rank.begin() , rank.end(), compare);
    for(i=0; i<V; i++){
        cout<< " ["<<rank[i].index<<","<<rank[i].count<<"]";
        visited[i] = 0;
    }
    cout<<"\n\n---- Displaying Strongly Connected Vertex ----\n";
    for(i=V-1; i>=0; i--){
        if(!visited[i])
            DFS(T, rank[i].index, visited,Index);
	}
	return 0;
}

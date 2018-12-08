#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
#define V 7

using namespace std;
vector<int> Ap;
void DFS(int G[][V],int st, vector<int> &num,int TEdge[],int visited[]){
    int i,k; static int c=0;
    num[st] = c++;
    cout<<" "<<st; visited[st] = 1;
    for(i=0; i<V; i++)
    if(G[st][i]!=0 && !visited[i]){
        TEdge[i] = st;
        DFS(G, i, num, TEdge, visited);
    }
}
void computeLow(int G[][V],int st, vector<int> num, vector<int> &low, int TEdge[]){
    int i,j,k;
    low[st] = num[st];
    for(i=0; i<V; i++){
        if(G[st][i]!=0){
            if(num[i] > num[st]){
                computeLow(G, i, num, low, TEdge);
                low[st] = min(low[st],low[i]);
            }
            else if( TEdge[st]!= i )
                low[st] = min(low[st], num[i]);
        }
    }
}
void computeArtPt(int st){
    set<int>::iterator i;
    set<int> s( Ap.begin(), Ap.end() );
    i = find(s.begin(), s.end(), st);
    s.erase(i);
    for(i=s.begin(); i!=s.end(); i++)
        cout<<"\n"<<*i;
}
void compareEdge(int G[][V], vector<int> num, vector<int> low ){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(G[i][j]!=0){
                if( low[j] >= num[i])
                    Ap.push_back(i);
            }
        }
    }
}
int main(){
    int G[V][V] = {
        {0,1,0,1,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,1,0,0,1},
        {1,0,1,0,1,1,0},
        {0,0,0,1,0,1,0},
        {0,0,0,1,1,0,0},
        {0,0,1,0,0,0,0},
    };
    vector<int> num,low; int TEdge[V]; int visited[V];
    int i,j,k;
    for(i=0; i<V; i++){
            TEdge[i]=-1;
        visited[i] = 0;
        low.push_back(-1);
        num.push_back(-1);
    }
    cout<<"\nDFS from vertex 0 : ";
    DFS(G, 0, num, TEdge, visited);
    computeLow(G, 0, num, low, TEdge);
    compareEdge(G,num,low);
    for(i=0; i<low.size(); i++)
        cout<<" "<<low[i];
    cout<<"\n\nArticulation Points Are : ";
    computeArtPt(0);
    return 0;
}

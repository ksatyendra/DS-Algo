#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#define V 9

using namespace std;
vector<int> Ap;

void DFS(int G[][V],int st, vector<int> &num,int Edge[][V],int visited[]){
    int i,k; static int c=0;
    num[st] = c++;
    cout<<" "<<st; visited[st] = 1;
    for(i=0; i<V; i++)
    if(G[st][i]!=0){
        if(!visited[i]){
            Edge[st][i] = 1; Edge[i][st] = -1;
            DFS(G, i, num, Edge, visited);
        }
        else{
            if(!Edge[st][i])  //if not tree nor parent edge
                Edge[st][i] = 2;
        }
    }
}
void computeLow(int G[][V],int st, vector<int> num, vector<int> &low, int Edge[][V]){
    int i;
    low[st] = num[st];
    for(i=0; i< V; i++){
        if(G[st][i]!=0){
            if(Edge[st][i]==1){
                computeLow(G, i, num, low, Edge);
                low[st] = min(low[st],low[i]);
            }
            else if(Edge[st][i] == 2){
                low[st] = min(low[st], num[i]);
            }
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
        {0,1,0,0,0,0,0,0,0},
        {1,0,1,0,1,1,0,0,0},
        {0,1,0,1,1,0,1,0,0},
        {0,0,1,0,0,0,0,0,0},
        {0,1,1,0,0,1,1,0,0},
        {0,1,0,0,1,0,1,1,0},
        {0,0,1,0,1,1,0,0,1},
        {0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,1,0,0},
    };
    vector<int> num,low; int Edge[V][V]; int visited[V];
    int i,j,k;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++)
            Edge[i][j] = 0;
        visited[i] = 0;
        low.push_back(-1);
        num.push_back(-1);
    }
    cout<<"\nDFS from vertex 0 : ";
    DFS(G, 0, num, Edge, visited);
    /*for(i=0; i<V; i++){
        cout<<"\n";
        for(j=0; j<V; j++)
            cout<<setw(3)<<Edge[i][j];
    }*/
    computeLow(G, 0, num, low, Edge);
    compareEdge(G,num,low);
    cout<<"\nLow Value : \n";
    for(i=0; i<low.size(); i++)
        cout<<" "<<low[i];
    cout<<"\n\nArticulation Points Are : ";
    computeArtPt(0);
    cout<<"\n-----\n\t------\n\t\t--------";
    return 0;
}
/*int G[V][V] = {
        {0,1,0,1,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,1,0,0,1},
        {1,0,1,0,1,1,0},
        {0,0,0,1,0,1,0},
        {0,0,0,1,1,0,0},
        {0,0,1,0,0,0,0},
    };
*/
/*int G[V][V] = {
    {0,1,0,0,0,0,0,0,0},
    {1,0,1,0,1,1,0,0,0},
    {0,1,0,1,1,0,1,0,0},
    {0,0,1,0,0,0,0,0,0},
    {0,1,1,0,0,1,1,0,0},
    {0,1,0,0,1,0,1,1,0},
    {0,0,1,0,1,1,0,0,1},
    {0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,1,0,0},
}
*/
/*int G[V][V] = {
        {0,1,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0},
        {0,1,0,1,0,0,0,0},
        {0,0,1,0,1,1,0,0},
        {0,0,0,1,0,1,0,0},
        {0,0,0,1,1,0,1,0},
        {0,0,0,0,0,1,0,1},
        {0,0,0,0,0,0,1,0},
    };*/

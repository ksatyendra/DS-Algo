#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>
#include<iomanip>
#define V 7

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
            if(!Edge[st][i])
                Edge[st][i] = 2;
        }
    }
}
void DFS(int G[][V],int st,int s,int visited[], int &tag){
    int i,k;
    cout<<" "<<st; //visited[st] = 1;
    for(i=0; i<V; i++)
    if(G[st][i]!=0){
        if(i==s){ tag = 0;  G[st][i] = G[i][st] = 0; return;}
        if(tag ){
            //cout<<" f "<<tag;
            G[st][i] = G[i][st] = 0;
            DFS(G,i,s,visited, tag);
        }
        break;
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
void removeDuplicate(vector<int> &Vec){
    int k = Vec[0]; vector<int>::iterator it;
    it = find(Vec.begin()+1, Vec.end(), k);
    Vec.erase(it, Vec.end());
    for(it = Vec.begin(); it!=Vec.end(); it++)
        cout<<" "<<*it;
    Vec.erase(Vec.begin(), Vec.end());
    cout<<"\n";
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
    vector<int> num,low; int Edge[V][V]; int visited[V]; int Gc[V][V];
    int i,j,k;
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            Edge[i][j] = 0;
            Gc[i][j] = G[i][j];
        }
        visited[i] = 0;
        low.push_back(-1);
        num.push_back(-1);
    }
    cout<<"\nDFS from vertex 0 : ";
    DFS(G, 0, num, Edge, visited);

    computeLow(G, 0, num, low, Edge);
    compareEdge(G,num,low);
    cout<<"\nLow Value : \n";
    for(i=0; i<low.size(); i++){
        cout<<" "<<low[i];
        visited[i] = 0;
    } int tag;
    cout<<"\n\nBiconnected Components Are : \n";
    set<int>::iterator is;
    set<int> s( Ap.begin(), Ap.end() );
    is = find(s.begin(), s.end(), 0);
    num.erase(num.begin(), num.end());
    for(is=s.begin(); is!=s.end(); is++){
        //cout<<"\n A :"<<*is<<"\n";
        tag = 1;
        if(is==s.begin())
            continue;
        DFS(G,*is, *is, visited, tag);
        cout<<"\n";
    }
    //for(i=0; i<V; i++){
        //cout<<"\n";
        //for(j=0; j<V; j++)
            //cout<<setw(3)<<G[i][j];
        //cout<<" "<<visited[i];
    //}
    cout<<"\n-----\n\t------\n\t\t--------";
    return 0;
}

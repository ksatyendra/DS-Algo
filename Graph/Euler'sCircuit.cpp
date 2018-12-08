#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<setjmp.h>
#define V 12

using namespace std;

int checkEuler(int G[][V]){
    int count;
    for(int i=0; i<V; i++){
        count =0;
        for(int j=0; j<V; j++)
            if(G[i][j])
                count++;
        if(count %2 != 0)
            return 0;
    }
    return 1;
}
void DFS(int G[][V],int st, vector<int> &tmp){
    int i,k;
    tmp.push_back(st);
    for(i=0; i<V; i++)
    if(G[st][i]!=0){
        G[i][st] = G[st][i] = 0;
        DFS(G, i, tmp);
    }
}
void Update(int G[][V],int Gc[][V],vector<int> Vec){
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
        G[i][j] = Gc[i][j];
    //cout<<"\nVector = ";
    for(i=0; i < Vec.size()-1; i++){
        G[Vec[i]][Vec[i+1]] = 0;
        G[Vec[i+1]][Vec[i]] = 0;
        //cout<<" "<<Vec[i];
    }
    //cout<<"\n";
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
        Gc[i][j] = G[i][j];
        //cout<<" "<<G[i][j];
        }
        //cout<<"\n";
    }
    //cout<<"\n";
}
void removeDuplicate(vector<int> &Vec){
    int k = Vec[0]; vector<int>::iterator it;
    it = find(Vec.begin()+1, Vec.end(), k);
    Vec.erase(it+1, Vec.end());
}
int main(){
    int G[V][V] = {
        {0,0,1,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,1,0,0,0,0},
        {1,1,0,1,0,1,1,0,1,0,0,0},
        {1,0,1,0,1,0,1,0,0,1,1,0},
        {0,0,0,1,0,0,0,0,0,1,0,0},
        {0,0,1,0,0,0,0,0,1,0,0,0},
        {0,0,1,1,0,0,0,0,1,1,0,0},
        {0,1,0,0,0,0,0,0,1,0,0,0},
        {0,0,1,0,0,1,1,1,0,1,0,1},
        {0,0,0,1,1,0,1,0,1,0,1,1},
        {0,0,0,1,0,0,0,0,0,1,0,0},
        {1,0,0,0,0,0,0,0,1,1,0,0},
    };
    int Gc[V][V];
    int i,j,k=0,r=0,count,flg; vector<int> Ar,tmp; vector<int>::iterator it,t;
    if(checkEuler(G))
        cout<<"Proceed.!!\n";
    else{
        cout<<"\nStop !!\n";
        goto label;
    }
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
        Gc[i][j] = G[i][j];
    Ar.push_back(k);
    do{
        DFS(G,k,tmp);
        /*cout<<"\nBefore Update : ";
        for(it = tmp.begin(); it!=tmp.end(); it++)
            cout<<" "<<*it;
        cout<<"\n";*/
        removeDuplicate(tmp);
        t = find(Ar.begin(),Ar.end(), k);
        Ar.insert(t+1, tmp.begin()+1, tmp.end());
        flg=0; count = 0; Update(G,Gc,tmp);
        tmp.erase(tmp.begin(),tmp.end());
        /*for(it = Ar.begin(); it!=Ar.end(); it++)
            cout<<" "<<*it;
        cout<<"\n"; */ ++r;
        for(i=r; i<Ar.size(); i++){
            for(j=0; j< V; j++)
            if(G[Ar[i]][j]!=0)
                count++;
            if(count>0){
                k = Ar[i]; flg=1;
                break;
            }
        }
        //cout<<"k = "<<k<<"\n";
    }while(flg!=0);
    cout<<"\nTravel On the Path Shown ..\n\n";
    for(i=0; i< Ar.size(); i++)
        cout<<" "<<Ar[i];
    label:
    cout<<"\n\n---------\n\t------------\n\t\t------------";
    return 0;
}

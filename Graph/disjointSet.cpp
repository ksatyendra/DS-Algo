#include<iostream>
#include <stdlib.h>
using namespace std;
#define MAX 10
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
void UnionHeight(int Set[], int a, int b)
{
    if(Set[b] < Set[a])
        Set[a] =b;
    else
    {
        if(Set[a] == Set[b])
            a--;
        Set[b] = a;
    }
}
int find(int Set[], int X)
{
    if(Set[X] == -1)
        return X;
    else
        find(Set, Set[X]);
}
int UnionCompress(int Set[], int a)
{
    if(Set[a] < 0)
        return a;
    else
        return (Set[a] = find(Set, a));
}

int main()
{
    int Set[MAX]; int a,b,N;
    for(int i=0; i<MAX; i++)
        Set[i] = -1;
    cout<<"\nEnter no. of edge : " ; cin>>N;
    for(int i=0; i<N; i++)
    {
        cout<<"\nEnter a & b : "; cin>>a>>b;
        Union(Set, a, b);
    }
    cout<<"\nEnter Element to Find : "; cin>>a;
    cout<<find(Set, a);
    return 0;
}

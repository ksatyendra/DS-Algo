#include<bits/stdc++.h>
using namespace std;
void display(vector<int>v,int n)
{
    cout<<"\nArray Elements: ";
    for(int i=0;i<n;i++)
     cout<<" "<<v[i];
    cout<<"\n";
}
void heapify(vector<int> &v, int n){
    int s,f,i;
    for(int i=1;i<n;i++)
    {
        int val=v[i];s=i;f=(s-1)/2;
        while(s>0 && v[f]>val)
         v[s]=v[f],s=f,f=(s-1)/2;
        v[s]=val;
    }
}
void sort(std::vector<int>&v,int n)
{
    heapify(v,n);
    for(int i=1;i<=n;i++)
    {
        swap(v[0],v[n-i]);
        heapify(v,n-i);
    }
}
int main()
{
    vector<int> v(50);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
     cin>>v[i];
    sort(v,n);
    display(v,n);
}

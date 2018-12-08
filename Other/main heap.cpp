#include<bits/stdc++.h>
using namespace std;
struct Heap
{
    int N; int in;
    Heap(){ N = 0; in = -1; }
    Heap(const Heap &H){
        N = H.N;
        in = H.in;
    }
};
int getKey(fstream & fin){
    int k;
    if(fin>>k);
    else
        k = INT_MAX;
    return k;
}
void display(vector<Heap> H, int n){
    cout<<"\nHeap Elements are : ";
    for(int i=0; i<n; i++)
        printf(" %d,%d ", H[i].N, H[i].in);
    cout<<"\n";
}
void heapify(vector<Heap> &H, int n){
    int s,f,i;
    for (int i = 1; i < n; ++i)
    {
        Heap val = H[i]; s = i; f = (s-1)/2;
        while(s>0 && H[f].N > val.N){
            H[s] = H[f]; s = f; f = (s-1)/2;
        }
        H[s] = val;
    }
    //display(H,n);
}

bool isComplete(vector<Heap> H, int n){
    for(int i=0; i<n; i++){
        if(H[i].N != INT_MAX)
            return false;
    }
    return true;
}
int main()
{
    vector<Heap> v(4);  fstream file[4]; char ch[2];
    for(int i=0; i<4; i++){
        ch[0] = (char)(i+48); ch[1] = '\0';
        file[i].open(ch,ios::in);
    }
    int n=4,i=0;
    for(int j=0; j<n; j++){
        v[j].N = getKey(file[j]);
        //cout<<v[j].N<<"A";
        v[j].in = j;
    }
    while(!isComplete(v,n)){

        heapify(v,n);
        cout<<" "<<v[0].N;
        v[0].N = getKey(file[v[0].in]);
    }
    return 0;
}

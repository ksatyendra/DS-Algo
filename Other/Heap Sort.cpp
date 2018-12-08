#include<iostream>
using namespace std;
void heapify(int *a,int en)
{
 for(int j=en/2;j>0;j--)
  for(int i=j,k=2*j;k<=en;i=k,k=2*i)
  {
   if(k<en&&a[k+1]<a[k])
    k++;
   if(a[i]>a[k])
    swap(a[i],a[k]);
  }
}
void heapsort(int *a,int en)
{
 heapify(a,en);
 cout<<a[1]<<" ";
 while(en>1)
 {
  swap(a[1],a[en--]);
  heapify(a,en);
  cout<<a[1]<<" ";
 }
}
int main()
{
    int n;
    cout<<"\nEnter no. of Elements : ";
    cin>>n;
    int *a=new int [n+1];
    for(int i=1;i<=n;i++)
     cin>>a[i];
    heapsort(a,n);
}

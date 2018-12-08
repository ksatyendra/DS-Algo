#include <bits/stdc++.h>
using namespace std;
void merg(int a[],int low,int high,int mid)
{
    int *b=new int[high-low];
    int i,j,k=0;
    for(i=low,j=mid;i<mid&&j<=high;a[i]<a[j]?b[k++]=a[i++]:b[k++]=a[j++]);
    for(;i<mid;b[k++]=a[i++]);
    for(;j<=high;b[k++]=a[j++]);
    for(;k>0;--k,a[low+k]=b[k]);
}
int main()
{
    int k,m,i,n=10;
    //printf("\nEnter Array Size : ");
    //cin>>n;
    //printf("\nEnter Array Elements : ");
    int A[10]={7,8,4,2,6,5,0,-5,0,0};
    for(k=1;k<n;k*=2)
     for(i=0;i<n;i+=2*k)
     {
      m=i+2*k;
      m<=n?merg(A,i,m-1,m-k):merg(A,i,n-1,m-k);
     }
    printf("\nSorted Array : ");
    for(int i=0;i<n;i++)
     cout<<" "<<A[i];
   cin>>i;
}
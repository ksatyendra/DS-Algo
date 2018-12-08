#include<bits/stdc++.h>
using namespace std;
int Partition(int *a,int l,int r)
{
 int i,j=l-1;
 for (i = l; i < r; ++i)
  if(a[i]<a[r]) swap(a[i],a[++j]);
 swap(a[r],a[++j]);
 return j;
}
void Quick_Sort(int *a, int l, int r)
{
 if(l>=r) return;
 int p=Partition(a,l,r);
 Quick_Sort(a,l,p-1);
 Quick_Sort(a,p+1,r);
}
void display(int *a,int n)
{
 cout<<"\nArray is :\n";
 for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
}
int main()
{
 int i,n,*arr;
 cout<<"\nEnter no. of elements : ";
 cin>>n;
 arr=new int[n];
 cout<<"\nEnter Data : ";
 for(i=0;i<n;i++)
  cin>>arr[i];
 display(arr,n);
 Quick_Sort(arr,0,n-1);
 display(arr,n);
}
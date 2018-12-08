#include<iostream>
#include<conio.h>
using namespace std;
bool binarysearch(int *a,int st,int en,int data)
{
 if(st<=en)
 {
  int mid=(st+en)/2;
  a[mid]<data?st=mid+1:en=mid-1;
  return (a[mid]==data)||binarysearch(a,st,en,data);
 }
 return 0;
}
int main()
{
 int i,n1,n2,n;
 cout<<"\nEnter No. of elements in Set 1 & Set 2 : ";
 cin>>n1>>n2;
 int *a=new int[n1];
 int *b=new int[n2];
 int *c=new int[n1];
 cout<<"\nEnter elements of Set 1 :\n";
 for(i=0;i<n1;i++) cin>>a[i];
 cout<<"\nEnter elements of Set 2 :\n";
 for(i=0;i<n2;i++) cin>>b[i];
 for(i=0,n=0;i<n2;i++)
  if(binarysearch(a,0,n1-1,b[i]))
   c[n++]=b[i],cout<<".";
 cout<<"\nUnion of both set is :\n";
 for(i=0;i<n;i++) cout<<c[i]<<" ";
}
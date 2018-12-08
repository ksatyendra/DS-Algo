#include<iostream>
using namespace std;
int *CountSort(int *arr,int *ind,int n,int a,int b)
{
 int i,j,*c=new int[n];
 for(j=0,i=0;i<=b-a;i++)
  for(;ind[i]>0;ind[i]--)
   c[j++]=i+a;
 return c;
}
void display(int *a,int n)
{
 cout<<"\nArray is :\n";
 for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
}
int main()
{
 int i,n,a,b,*arr,*ind,*out;
 cout<<"\nEnter no. of elements : ";
 cin>>n;
 arr=new int[n];
 cout<<"\nEnter range of data : ";
 cin>>a>>b;
 ind=new int[b-a+1];
 for(i=0;i<=b-a;i++)
  ind[i]=0;
 cout<<"\nEnter Data : ";
 for(i=0;i<n;i++)
  cin>>arr[i],ind[arr[i]-a]++;
 display(arr,n);
 out=CountSort(arr,ind,n,a,b);
 display(out,n);
}
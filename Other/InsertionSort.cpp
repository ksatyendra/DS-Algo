#include<iostream>
using namespace std;
void InsertSort(int *arr,int n)
{
 int i,j,k;
 for(i=1;i<n;i++)
 {
  for(j=i,k=arr[i];j && k<arr[j-1];j--)
   arr[j]=arr[j-1];
  arr[j]=k;
 }
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
 InsertSort(arr,n);
 display(arr,n);
}
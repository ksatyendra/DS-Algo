#include<iostream>
using namespace std;
void Merge(int a[],int low,int high)
{
 int i,j,k=0,mid=(low+high)/2+1,*b=new int[high-low+1];
 for(i=low,j=mid; i<mid && j<=high; b[k++]= a[i]<a[j] ? a[i++] : a[j++]);
 for(;i<mid; b[k++]=a[i++]);
 for(;j<=high; b[k++]=a[j++]);
 for(;k>0; a[low-1+k--]=b[k]);
}
void MergeSort(int a[],int low,int high)
{
 if(low>=high) return;
 int mid=(low+high)/2;
 MergeSort(a,low,mid);
 MergeSort(a,mid+1,high);
 Merge(a,low,high);
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
 MergeSort(arr,0,n-1);
 display(arr,n);
}
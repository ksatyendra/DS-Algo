#include<bits/stdc++.h>
using namespace std;
int size;
void QuickSort(int *arr, int left, int right)
{
 int tmp,i=left,j=right,pivot=arr[(left+right)/2];
 while (i<=j)
 {
  while(arr[i]<pivot) i++;
  while (arr[j]>pivot) j--;
  if (i<=j)
  {
   swap(arr[i],arr[j]);
   i++;
   j--;
  }
 };
 if(left<j)
  QuickSort(arr,left,j);
 if(i<right)
  QuickSort(arr,i,right);
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
 QuickSort(arr,0,n-1);
 display(arr,n);
}
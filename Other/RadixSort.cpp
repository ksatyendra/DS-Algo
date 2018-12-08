#include<iostream>
using namespace std;
int GetMaximum(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void CountSort(int arr[], int n, int exp)
{
    int *output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (i=0;i<n;i++)
        arr[i]=output[i];
}
void RadixSort(int arr[], int n)
{
    int m = GetMaximum(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        CountSort(arr, n, exp);
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
 RadixSort(arr,n);
 display(arr,n);
}
#include<iostream>
using namespace std;
void display(int *a,int n)
{
 cout<<"\nArray is :\n";
 for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
 cout<<endl;
}
void Count_Sort(int *x,int a,int b,int n,int *y)
{
 int i,k,*ct=new int[b-a+1];
 for(i=a;i<=b;i++)
  ct[i-a]=0;
 for(i=0;i<n;i++)
  ct[x[i]-a]++;
 for(i=a+1;i<=b;i++)
  ct[i-a]+=ct[i-a-1];
 for(i=0;i<n;i++)
  y[--ct[x[i]-a]]=x[i];
}
int main()
{
 int i,n,a,b,*inp,*out;
 cout<<"\nEnter no. of elements : ";
 cin>>n;
 inp=new int[n];
 out=new int[n];
 cout<<"\nEnter range of data : ";
 cin>>a>>b;
 cout<<"\nEnter data : ";
 for(i=0;i<n;i++)
  cin>>inp[i];
 display(inp,n);
 Count_Sort(inp,a,b,n,out);
 display(out,n);
} // 8 3 12 4 5 7 4 9 8 10 11
// 4 -4 4 -3 4 -4 1
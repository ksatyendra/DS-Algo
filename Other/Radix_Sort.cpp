#include<iostream>
using namespace std;
void display(int *a,int n)
{
 cout<<"\nArray is :\n";
 for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
 cout<<endl;
}
int Max_Dig(int *x,int n)
{
 int mx = 0,c=0;
 for (int i = 0; i < n; ++i)
  if(mx < x[i]) mx=x[i];
 while(mx > 0) c++,mx/=10;
 return c;
}
void Count_Sort(int *x,int n,int z)
{
 int i,k,*y,*ct=new int[10];
 y=new int[n];
 for(i=0;i<10;i++)
  ct[i]=0;
 for(i=0;i<n;i++)
  ct[(x[i]/z)%10]++;
 for(i=1;i<10;i++)
  ct[i]+=ct[i-1];
 for(i=n-1;i>=0;i--)
 { k=(x[i]/z)%10; y[--ct[k]]=x[i]; }
 for(i=0;i<n;i++)
  x[i]=y[i];
}
void Radix_Sort(int *x,int n)
{
 int digits=Max_Dig(x,n);
 for (int i = 0, z = 1; i < digits; z *= 10,++i)
  Count_Sort(x,n,z);
 display(x,n);
}
int main()
{
 int i,n;
 cout<<"\nEnter no. of elements : ";
 cin>>n;
 int *inp=new int[n];
 cout<<"\nEnter data : ";
 for(i=0;i<n;i++)
  cin>>inp[i];
 display(inp,n);
 Radix_Sort(inp,n);
 display(inp,n);
} // 12 3 12 4 5 7 4 9 8 10 11 14 76
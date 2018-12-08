#include<iostream>
using namespace std;
int a[10]={3,4,2,5,7,5,4,6,8,9},n=10,top;
void push(int k)
{
 a[++top]=k;
}
int pop()
{
 return a[top--];
}
void rev(int a[],int k)
{
    if(k>0)
    {
     int b=pop();
     rev(a,k-1);
     push(b);
    }
    else
    {
     int b=pop(),c=pop();
     push(b);
     push(c);
    }
}
int main()
{
    int i,j;
    top=9;
    for(j=1;j<n-1;j++)
     for(i=0;i<n-j;i++)
      rev(a,i);
    for(i=0;i<10;i++)
     cout<<a[i]<<" ";
}

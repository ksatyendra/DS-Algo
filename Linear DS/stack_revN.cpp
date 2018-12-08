#include<iostream>
using namespace std;
char *a;
int n,top;
void push(char k)
{
 a[++top]=k;
}
char pop()
{
 return a[top--];
}
void revs(char *a,int k,int b)
{
 if(k)
 {
  int c=pop();
  revs(a,k-1,b);
  push(c);
 }
 else
  push(b); 
}
void rev(char *a,int k)
{
 char b=pop();
 revs(a,k-1,b);
}
int main()
{
    int i=n+1,j;
    cin>>n;
    top=n-1;
    a=new char[n];
    cin>>a;
    while(--i)
     rev(a,i);
    for(i=0;i<10;i++)
     cout<<char(a[i])<<" ";
    cin>>i;
}
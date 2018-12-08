#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
char *a;
int top,n=20;
bool isempty()
{
 return top==-1;
}
bool isfull()
{
 return top==n-1;
}
void display()
{
 if(!isempty())
 {
  cout<<"\nString is : ";
  for(int i=0;i<=top;i++)
   cout<<a[i];
  cout<<endl<<endl;
 }
 else
  cout<<"\nStack is empty.\n";
}
void push(char k)
{
 a[++top]=k;
}
char pop()
{
 return a[top--];
}
void revs(int k,int y)
{
 if(k)
 {
  int x=pop();
  revs(k-1,y);
  push(x);
 }
 else
  push(y);
}
void str_rev()
{
 int x,i;
 for(i=top;i>0;revs(i--,x))
  x=pop();
}
int main()
{
 char *b=new char[n];
 bool ch=1;
 while(ch)
 {
  top=-1;
  a=new char[n];
  cout<<"Enter the String : ";
  cin>>b;
  n=strlen(b);
  for(int i=0;i<n;i++)
   push(b[i]);
  str_rev();
  display();
  cout<<"\nDo you want to continue then enter 1 else 0 : \n";
  cin>>ch;
 }
 return 0;
}

#include<iostream>
#include<conio.h>
using namespace std;
char *a,*b;
int top,n=50;
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
  cout<<"\nStack  is : ";
  for(int i=0;i<=top;i++)
  cout<<a[i]<<" ";
 }
 cout<<"\nStack is empty.";
}
void push(char k)
{
  a[++top]=k;
}
char pop()
{
 return a[top--];
}
bool parenthesis_check()
{
     for(int i=0;b[i]!='\0';i++)
      switch(b[i])
      {
         case '(' :
         case '{' :
         case '[' : push(b[i]);
                    break;
         case ')' : if(isempty()||pop()!='(')
                     return 0;
                    break;
         case '}' : if(isempty()||pop()!='{')
                     return 0;
                    break;
         case ']' : if(isempty()||pop()!='[')
                     return 0;
                    break;
      }
      if(top==-1)
       return 1;
      else
      { 
       while(top>=0)
        top--;
       return 0;
      }
}
int main()
{
 bool ch=1;
 top=-1;
 a = new char [n];
 b=new char[n];
 while(ch)
 {
  cout<<"Enter Expression to check parenthesis  :  ";
  cin>>b;
  if(parenthesis_check())
   cout<<"\nNo Error in the parenthesis.\n";
  else
   cout<<"\nError in the parenthesis.\n";
  cout<<"\nDo you want to continue then enter 1 else 0 : \n";
  cin>>ch;
 }
 return 0;
}

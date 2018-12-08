#include<iostream>
#include<conio.h>
using namespace std;
char *b;
int *a,top,n=50;
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
void push(int k)
{
  a[++top]=k;
}
int pop()
{
 return a[top--];
}
int postfix_evaluation()
{
     int x,y,i;
     for(i=0;b[i]!='\0';i++)
     {
      if(b[i]>='0'&&b[i]<='9')
       push(b[i]-48);
      else 
      {
       y = pop(); x = pop(); 
       switch(b[i])
       {
         case '+' : push(x+y); break;
         case '-' : push(x-y); break;
         case '*' : push(x*y); break;
         case '/' : push(x/y); break;
       }
      }
     }  
     return pop();
}
int main()
{
 bool ch=1;
 top=-1;
 a = new int [n];
 b = new char[n];
 while(ch)
 {
  cout<<"Enter Postfix Expression  :  ";
  cin>>b;
  cout<<"\nSolution for the postfix expression : "<<postfix_evaluation();
  cout<<"\nDo you want to continue then enter 1 else 0 : \n";
  cin>>ch;
 }
 return 0;
}

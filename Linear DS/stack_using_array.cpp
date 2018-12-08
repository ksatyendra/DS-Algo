#include<iostream>
#include<conio.h>
using namespace std;
int *a;
int top,n;
bool isempty()
{
 if(top==-1)
 {
  cout<<"\nStack is EMPTY!\n";
  return true;
 }
 return false;
}
bool isfull()
{
 if(top==n-1)
 {
  cout<<"\nStack is FULL!\n";
  return true;
 }
 return false;
}
void display()
{
 if(!isempty())
 {
  cout<<"\nStack  is : ";
  for(int i=0;i<=top;i++)
  cout<<a[i]<<" ";
 }
}
void push()
{
 if(!isfull())
 { 
  cout<<"\nEnter element to push : ";
  cin>>a[++top];
  display();
 }
}
void pop()
{
 if(!isempty())
 {
  cout<<"\nPopped element : "<<a[top--]<<endl;
  display();
 }
}
int main()
{
 int ch=1;
 top=-1;
 cout<<"Enter no. of elements to initialize the stack : ";
 cin>>n;
 a=new int[n];
 while(ch)
 {
  cout<<"\n\nOptions :\n=>1 to Display the Stack\n=>2 to Find the current status ofStack\n=>3 to Push an element in Stack\n=>4 to Pop an element from Stack\n";
  cout<<"=>5 to check if Stack is Empty\n=>6 to check if Stack is Full\n=>0 to Terminate the Program\n\nEnter choice from above options : ";
  cin>>ch;
  if(!ch)
   break;
  else if(ch==1)
   display();
  else if(ch==2)
   cout<<"\nStack has "<<top+1<<"elements.\nAnd current position of Top is "<<top<<endl;
  else if(ch==3)
   push();
  else if(ch==4)
   pop();
  else if(ch==5)
  { 
   if(!isempty())
    cout<<"\nStack is not Empty.\n";
  }
  else if(ch==6)
  {
   if(!isfull())
    cout<<"\nStack is not Full.\n";
  }
  else
   cout<<"*\nWRONG CHOICE! Try Again...*\n";
 }
 return 0;
}

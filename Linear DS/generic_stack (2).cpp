#include<iostream>
#include<conio.h>
using namespace std;
union grp
{
 int x;
 float y;
 char z;
}*a; 
int top,type,n;
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
   switch(type)
   { 
    case 1 : cout<<a[i].x<<" ";break;
    case 2 : cout<<a[i].y<<" ";break;
    case 3 : cout<<a[i].z<<" ";break;
   }
 }
}
void push()
{
 if(!isfull())
 { 
  cout<<"\nEnter element to push : ";
  switch(type)
  { 
   case 1 : cin>>a[++top].x<<" ";break;
   case 2 : cin>>a[++top].y<<" ";break;
   case 3 : cin>>a[++top].z<<" ";break;
  }
  display();
 }
}
void pop()
{
 if(!isempty())
 {
  cout<<"\nPopped element : ";
  switch(type)
  { 
   case 1 : cout<<a[top--].x<<" ";break;
   case 2 : cout<<a[top--].y<<" ";break;
   case 3 : cout<<a[top--].z<<" ";break;
  }
  cout<<endl;
  display();
 }
}
int main()
{
 int ch=1;
 top=-1;
 cout<<"Enter no. of elements to initialize the stack : ";
 cin>>n;
 cout<<"\nEnter the type [1 for int & 2 for float & 3 for char] : ";
 cin>>type;
 a=new grp[n];
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

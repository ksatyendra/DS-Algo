#include<iostream>
#include<conio.h>
using namespace std;
int *a,top1,top2,n=10;
bool isempty1()
{
 return top1==-1;
}
bool isempty2()
{
 return top2==n;
}
bool isfull()
{
 return top1==top2-1;
}
void display1()
{
 if(!isempty1())
 {
  cout<<"\n\nStack 1 is : ";
  for(int i=0;i<=top1;i++)
   cout<<a[i]<<" ";
  cout<<"\n\n";
 }
 cout<<"\n\nStack is empty.";
}
void display2()
{
 if(!isempty2())
 {
  cout<<"\nStack 2 is : ";
  for(int i=n;i>=top2;i--)
   cout<<a[i]<<" ";
  cout<<"\n\n";
 }
 cout<<"\nStack is empty.";
}
void push1(int k)
{
  a[++top1]=k;
}
void push2(int k)
{
  a[--top2]=k;
}
int pop1()
{
 return a[top1--];
}
int pop2()
{
 return a[top2++];
}
int main()
{
 int x , ch = 1;
 top1 = -1; top2 = n;
 a = new int [n];
 while(ch)
 {
  cout<<"\n\nEnter option :\n1 to push in stack 1\t\t2 to push in stack 2\n3 to pop from stack 1\t\t4 to pop from stack 2\n5 to display stack 1\t\t6 to display stack 2\n7 to check underflow\t\t8 to check overflow\n0 to terminate    :    ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : if(!isfull())
            {
             cout<<"\n\nEnter data to push : ";
             cin>>x;
             push1(x);
            }
            else
             cout<<"\nStack is full.\n";
            break;
   case 2 : if(!isfull())
            {
             cout<<"\n\nEnter data to push : ";
             cin>>x;
             push2(x);
            }
            else
             cout<<"\nStack is full.\n";
            break;
   case 3 : if(!isempty1())
             cout<<"\nPopped Data from Stack 1 : "<<pop1()<<"\n\n";
            else
             cout<<"\nStack 1 is Empty.\n";
            break;
   case 4 : if(!isempty2())
             cout<<"\nPopped Data from Stack 2 : "<<pop2()<<"\n\n";
            else
             cout<<"\nStack 2 is Empty.\n";
            break;
   case 5 : display1();
            break;
   case 6 : display2();
            break;
   case 7 : if(isempty1()&&isempty2())
              cout<<"\n\nBoth stacks are in underflow.\n\n";
            else if(isempty1())
              cout<<"\n\nStacks 1 is in underflow.\n\n";
            else if(isempty1())
              cout<<"\n\nStacks 2 is in underflow.\n\n";
            else
             cout<<"\n\nNeither stack is in underflow.\n\n";
            break;
   case 8 : if(isfull())
             cout<<"\n\nOverflow is going to happen.\n\n";
            else
             cout<<"\n\nOverflow is not there.\n\n";
            break;
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

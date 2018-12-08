#include<iostream>
#include<conio.h>
using namespace std;
int *a,*b,front1,rear1,rear2,n=10;
bool isempty()
{
 return front1>rear1;
}
bool isfull()
{
 return rear1==n-1;
}
void display()
{
 if(!isempty())
 {
  cout<<"\n\nstack(queue) is : ";
  for(int i=front1;i<=rear1;i++)
   cout<<a[i]<<" ";
  cout<<"\n\n";
 }
 else
  cout<<"\n\nstack(queue) is empty.";
}
void insr(int k)
{
 a[++rear1]=k;
}
void push(int k)
{
 b[++rear2]=k;
}
int delt()
{
 return a[front1++];
}
int pop()
{
 while(rear2<rear1-1)
  push(delt());
 int x = delt();
 swap(a,b);
 rear2=-1; rear1--; front1=0;
 return x;
}
int main()
{
 int x , ch = 1;
 front1 = 0; rear1 = -1; rear2  = -1;
 a = new int [n];
 b = new int [n]; 
 while(ch)
 {
  cout<<"\n\nEnter option :\n1 to push in stack(queue)\n2 to pop from stack(queue)\n3 to display stack(queue)\n4 to check empty\n5 to check full\n0 to terminate    :    ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : if(!isfull())
            {
             cout<<"\n\nEnter data to push : ";
             cin>>x;
             insr(x);
            }
            else
             cout<<"\nstack(queue) is full.\n";
            break;
   case 2 : if(!isempty())
             cout<<"\nDeleted Data from Stack 1 : "<<pop()<<"\n\n";
            else
             cout<<"\nstack(queue) is Empty.\n";
            break;
   case 3 : display();
            break;
   case 4 : if(isempty())
              cout<<"\n\nstack(queue) is empty.\n\n";
            else
             cout<<"\n\nstack(queue) has "<<rear1-front1+1<<" elements.\n\n";
            break;
   case 5 : if(isfull())
              cout<<"\n\nstack(queue) is full.\n\n";
            else
             cout<<"\n\nstack(queue) is not full.\n\n";
            break;
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

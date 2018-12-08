#include<iostream>
using namespace std;
int *a,*b,top1,top2,n=10;
bool isempty()
{
 return top1==-1;
}
bool isfull()
{
 return top1==n-1;
}
void display()
{
 if(!isempty())
 {
  cout<<"\n\nqueue(stack) is : ";
  for(int i=0;i<=top1;i++)
   cout<<a[i]<<" ";
  cout<<"\n\n";
 }
 else
  cout<<"\n\nqueue(stack) is empty.";
}
void push1(int k)
{
 a[++top1]=k;
}
void push2(int k)
{
 b[++top2]=k;
}
int pop1()
{
 return a[top1--];
}
int pop2()
{
 return b[top2--];
}
int pop()
{
 while(top1>0)
  push2(pop1());
 int x = pop1();
 while(top2>=0)
  push1(pop2());
 return x;
}
int main()
{
 int x , ch = 1;
 top1 = -1;top2 = -1;
 a = new int [n];
 b = new int [n]; 
 while(ch)
 {
  cout<<"\n\nEnter option :\n1 to insert in queue(stack)\n2 to delete from queue(stack)\n3 to display queue(stack)\n4 to check empty\n5 to check full\n0 to terminate    :    ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : if(!isfull())
            {
             cout<<"\n\nEnter data to insert : ";
             cin>>x;
             push1(x);
            }
            else
             cout<<"\queue(stack) is full.\n";
            break;
   case 2 : if(!isempty())
             cout<<"\nDeleted Data from Stack 1 : "<<pop()<<"\n\n";
            else
             cout<<"\nqueue(stack) is Empty.\n";
            break;
   case 3 : display();
            break;
   case 4 : if(isempty())
              cout<<"\n\nqueue(stack) is empty.\n\n";
            else
             cout<<"\n\nqueue(stack) has "<<top1+1<<" elements.\n\n";
            break;
   case 5 : if(isfull())
              cout<<"\n\nqueue(stack) is full.\n\n";
            else
             cout<<"\n\nqueue(stack) is not full.\n\n";
            break;
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

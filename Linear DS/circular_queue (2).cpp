#include<iostream>
#include<conio.h>
using namespace std;
int *a,front,rear,n=10;
bool isempty()
{
 return front>rear;
}
bool isfull()
{
 return rear-front==n-1;
}
void display()
{
 if(!isempty())
 {
  cout<<"\n\nQueue is : ";
  for(int i=front;i<=rear;i++)
   cout<<a[i%n]<<" ";
  cout<<"\n\n";
 }
 else
  cout<<"\n\nQueue is empty.";
}
void insr(int k)
{
  a[(++rear)%n]=k;
}
int delt()
{
  return a[(front++)%n];
}
int main()
{
 int x , ch = 1;
 front = 0;
 rear = -1;
 a = new int [n];
 while(ch)
 {
  cout<<"\n\nEnter option :\n1 to insert in queue\n2 to delete from queue\n3 to display queue\n4 to check empty\n5 to check full\n0 to terminate    :    ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : if(!isfull())
            {
             cout<<"\n\nEnter data to insert : ";
             cin>>x;
             insr(x);
            }
            else
             cout<<"\nQueue is full.\n";
            break;
   case 2 : if(!isempty())
             cout<<"\nDeleted Data from Stack 1 : "<<delt()<<"\n\n";
            else
             cout<<"\nQueue is Empty.\n";
            break;
   case 3 : display();
            break;
   case 4 : if(isempty())
              cout<<"\n\nQueue is empty.\n\n";
            else
             cout<<"\n\nQueue has "<<rear-front+1<<" elements.\n\n";
            break;
   case 5 : if(isfull())
              cout<<"\n\nQueue is full.\n\n";
            else
             cout<<"\n\nQueue is not full.\n\n";
            break;
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

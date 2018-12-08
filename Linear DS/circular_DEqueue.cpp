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
  for(int i=front+n;i<=rear+n;i++)
   cout<<a[i%n]<<" ";
  cout<<"\n\n";
 }
 else
  cout<<"\n\nQueue is empty.";
}
void insrB(int k)
{
  a[(--front+n)%n]=k;
}
void insrE(int k)
{
  a[(++rear+n)%n]=k;
}
int deltB()
{
  return a[((front++)+n)%n];
}
int deltE()
{
  return a[((rear--)+n)%n];
}
int main()
{
 int x , ch = 1;
 front = 0;
 rear = -1;
 a = new int [n];
 while(ch)
 {
  cout<<"\n\nEnter option :\n1 to insert at begining in queue\n2 to insert at last in queue\n3 to delete at begining in queue\n4 to delete at last in queue\n5 to display queue\n6 to check empty\n7 to check full\n0 to terminate    :    ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : if(!isfull())
            {
             cout<<"\n\nEnter data to insert : ";
             cin>>x;
             insrB(x);
            }
            else
             cout<<"\nQueue is full.\n";
            break;
   case 2 : if(!isfull())
            {
             cout<<"\n\nEnter data to insert : ";
             cin>>x;
             insrE(x);
            }
            else
             cout<<"\nQueue is full.\n";
            break;
   case 3 : if(!isempty())
             cout<<"\nDeleted Data from Stack 1 : "<<deltB()<<"\n\n";
            else
             cout<<"\nQueue is Empty.\n";
            break;
   case 4 : if(!isempty())
             cout<<"\nDeleted Data from Stack 1 : "<<deltE()<<"\n\n";
            else
             cout<<"\nQueue is Empty.\n";
            break;
   case 5 : display();
            break;
   case 6 : if(isempty())
              cout<<"\n\nQueue is empty.\n\n";
            else
             cout<<"\n\nQueue has "<<rear-front+1<<" elements.\n\n";
            break;
   case 7 : if(isfull())
              cout<<"\n\nQueue is full.\n\n";
            else
             cout<<"\n\nQueue is not full.\n\n";
            break;
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

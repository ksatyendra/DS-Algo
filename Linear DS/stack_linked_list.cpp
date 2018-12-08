#include<iostream>
#include<conio.h>
using namespace std;
struct lst
{
 int data;
 lst *next;
};
bool isempty(lst *l)
{
 return l==NULL;
}
void display(lst *l)
{
 if(l)
 {
  display(l->next);
  cout<<l->data<<" ";
 }
}
void push(lst* &a)
{
 if(a==NULL)
 {
  a=new lst;
  cout<<"\nEnter data : ";
  cin>>a->data;
  a->next=NULL;
  return;
 }
 lst *l=new lst;
 cout<<"\nEnter data : ";
 cin>>l->data;
 l->next=a;
 a=l;
}
void create(lst* &l)
{
 l=NULL;
 int n;
 cout<<"\nEnter no. of elements : ";
 cin>>n;
 for(int i=0;i<n;i++)
  push(l);
}
int pop(lst* &a)
{
 int x=a->data;
 lst *t=a;
 a=a->next;
 delete t;
 return x;
}
int main()
{
 int ch,n,ss;
 lst *head=NULL;
 while(ch)
 {
  cout<<"Enter option :\n1 to create a Stack";
  cout<<"\n2 to push an element in stack.\n3 to pop an element from stack.";
  cout<<"\n4 to display Stack.\n0 to terminate the Program.    :    \n";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : create(head); break;
   case 2 : push(head); break;
   case 3 : if(isempty(head))
            {
             cout<<"\nStack is empty.\n\n";
             break;
            }
            ss=pop(head); 
            cout<<"Popped data : "<<ss<<endl; break;
   case 4 : if(isempty(head))
            {
             cout<<"\nStack is empty.\n\n";
             break;
            }
            cout<<"\n\nStack is : ";
            display(head);
            cout<<"\n\n"; break; 
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

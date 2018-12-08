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
void ins(lst* &a)
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
  ins(l);
}
int del(lst* &a)
{
 int x;
 lst *t,*l;
 if(a->next==NULL)
 {
  t=a;
  x=a->data;
  a=NULL;
  delete t;
  return x;
 }
 for(l=a;l->next->next;l=l->next);
 x=l->next->data;
 t=l->next;
 if(a->next==t)
  a->next=NULL;
 l->next=NULL;
 delete t;
 return x;
}
int main()
{
 int ch,n,ss;
 lst *head=NULL;
 while(ch)
 {
  cout<<"Enter option :\n1 to create a Queue";
  cout<<"\n2 to insert an element in Queue.\n3 to delete an element from Queue.";
  cout<<"\n4 to display Queue.\n0 to terminate the Program.    :    ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : create(head); break;
   case 2 : ins(head); break;
   case 3 : if(isempty(head))
            {
             cout<<"\nQueue is empty.\n\n";
             break;
            }
            ss=del(head); 
            cout<<"Deleted data : "<<ss<<endl; break;
   case 4 : if(isempty(head))
            {
             cout<<"\nQueue is empty.\n\n";
             break;
            }
            cout<<"\n\nQueue is : ";
            display(head);
            cout<<"\n\n"; break; 
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

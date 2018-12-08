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
 if(!isempty(l))
 {
  lst *t;
  cout<<"\n\nLinked List is : ";
  for(t=l;t->next!=l;t=t->next)
   cout<<t->data<<" ";
  cout<<t->data<<"\n\n";
 }
 else
  cout<<"\n\nLinked List is empty.\n\n";
}
void insert_pos(lst* &a,int n)
{
 lst *l,*d=new lst;
 cout<<"\nEnter data : ";
 cin>>d->data;
 d->next=NULL;
 if(!n) 
 {
  cout<<"\nWRONG POSITION.\n"; 
  return;
 }
 if(n==1)
 {
  d->next=a;
  if(!a)
  {
   d->next=d;
  }
  for(l=a;l->next!=a;l=l->next);
  l->next=d;
  a=d;
  return;
 } 
 for(l=a,--n;--n&&(l->next!=a);l=l->next);
 if(n) 
 {
  cout<<"\nWRONG POSITION.\n"; 
  return;
 }
 lst *t=l->next;
 l->next=d;
 d->next=t;
}
void insert_begin(lst* &l)
{
 insert_pos(l,1);
}
void insert_end(lst* &a)
{
 lst *l;
 if(a==NULL)
 {
  a=new lst;
  cout<<"\nEnter data : ";
  cin>>a->data;
  a->next=a;
  return;
 }
 for(l=a;l->next!=a;l=l->next);
 l->next=new lst;
 l=l->next;
 cout<<"\nEnter data : ";
 cin>>l->data;
 l->next=a;
}
void insert_before(lst* &a,int n)
{
 lst *l,*d;
 d=new lst;
 cout<<"\nEnter data : ";
 cin>>d->data;
 if(a->data==n)
 {
  insert_pos(a,1);
  return;
 }
 for(l=a;(l->next!=a) && (l->next->data!=n);l=l->next);
 if(l->next==a) 
 {
  cout<<"\nGiven value is not there in Linked List.\n";
  return;
 }
 lst *t=l->next; 
 l->next=d;
 l=l->next;
 l->next=t;
}
void insert_after(lst* &a,int n)
{
 if(a->data==n)
 {
  insert_pos(a,2);
  return;
 }
 lst *l,*d;
 d=new lst;
 cout<<"\nEnter data : ";
 cin>>d->data;
 for(l=a->next;(l!=a) && (l->data!=n);l=l->next);
 if(l==a) 
 {
  cout<<"\nGiven value is not there in Linked List.\n";
  return;
 }
 lst *t=l->next; 
 l->next=d;
 l=l->next;
 l->next=t;
}
void create(lst* &l)
{
 l=NULL;
 int n;
 cout<<"\nEnter no. of elements : ";
 cin>>n;
 for(int i=0;i<n;i++)
  insert_end(l);
}
void delete_pos(lst* &a,int n)
{
 lst *t,*l;
 if(!n) 
 {
  cout<<"\nWRONG POSITION.\n"; 
  return;
 }
 if(n==1)
 {
  l=a;
  for(t=a;t->next!=a;t=t->next);
  t->next=a->next;
  a=a->next;
  delete l;
  return;
 } 
 for(--n,l=a;--n&&(l->next!=a);l=l->next);
 if(n) 
 {
  cout<<"\nWRONG POSITION.\n"; 
  return;
 }
 t=l->next;
 l->next=l->next->next;
 delete t;
}
void delete_begin(lst* &l)
{
 delete_pos(l,1);
}
void delete_end(lst* &a)
{
 lst *t,*l;
 if(!a)
 {
  cout<<"\nEmpty Linked List.\n\n";
  return;
 }
 if(!(a->next))
 {
  t=a;
  a=NULL;
  delete t;
  return;
 }
 for(l=a;l->next->next!=a;l=l->next);
 t=l->next;
 l->next=a;
 delete t;
}
void delete_before(lst* &a,int n)
{
 lst *l,*d;
 if(a->data==n)
 {
  cout<<"\nThere is nothing before given value in Linked List.\n";
  return;
 }
 if(a->next->data==n)
 {
  delete_pos(a,1);
  return;
 }
 for(l=a;(l->next->next!=a) && (l->next->next->data!=n);l=l->next);
 if(!(l->next->next)) 
 {
  cout<<"\nGiven value is not there in Linked List.\n";
  return;
 }
 lst *t=l->next; 
 l->next=l->next->next;
 delete t;
}
void delete_after(lst* &a,int n)
{
 lst *l;
 if(a->data==n)
 {
  delete_pos(a,2);
 }
 for(l=a->next;(l!=a) && (l->data!=n);l=l->next);
 if(!l) 
 {
  cout<<"\nGiven value is not there in Linked List.\n";
  return;
 }
 lst *t=l->next; 
 l->next=l->next->next;
 delete t;
}
void delete_value(lst* &a,int n)
{
 lst *l;
 if(a->data==n)
 {
  lst *t=a;
  if(a->next==a)
   a=NULL;
  else
   a=a->next;
  delete t;
  return;
 }
 for(l=a;(l->next!=a) && (l->next->data!=n);l=l->next);
 if(l->next==a) 
 {
  cout<<"\nGiven value is not there in Linked List.\n";
  return;
 }
 lst *t=l->next; 
 l->next=l->next->next;
 delete t;
}
int main()
{
 int ch,n;
 lst *head=NULL;
 while(ch)
 {
  cout<<"Enter option :\n1 to create a Linked List.";
  cout<<"\n2 to insert at begin in Linked List.\n3 to insert at last in Linked List.";
  cout<<"\n4 to insert by position in Linked List.\n5 to insert before an element in Linked List.";
  cout<<"\n6 to insert after an element in Linked List.\n7 to delete at begin in Linked List.";
  cout<<"\n8 to delete at last in Linked List.\n9 to delete by position in Linked List.";
  cout<<"\n10 to delete before an element in Linked List.\n11 to delete after an element in Linked List.";
  cout<<"\n12 to delete by data value in Linked List.\n13 to display the Linked List   :   ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : create(head); break;
   case 2 : insert_begin(head); break;
   case 3 : insert_end(head); break;
   case 4 : cout<<"\nEnter the position : "; cin>>n;
            insert_pos(head,n); break;
   case 5 : cout<<"\nEnter the data before which you want: "; cin>>n;
            insert_before(head,n); break;
   case 6 : cout<<"\nEnter the data after which you want: "; cin>>n;
            insert_after(head,n); break;
   case 7 : delete_begin(head); break;
   case 8 : delete_end(head); break;
   case 9 : cout<<"\nEnter the position : "; cin>>n; 
            delete_pos(head,n); break;
   case 10 : cout<<"\nEnter the data before which you want: "; cin>>n;
             delete_before(head,n); break;
   case 11 : cout<<"\nEnter the data after which you want: "; cin>>n;
             delete_after(head,n); break;
   case 12 : cout<<"\nEnter the data : "; cin>>n;
             delete_value(head,n); break;
   case 13 : display(head); break; 
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

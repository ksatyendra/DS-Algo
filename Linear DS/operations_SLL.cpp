#include<iostream>
#include<conio.h>
using namespace std;
struct node
{
 int data;
 node *next;
};
bool isempty(node *l)
{
 return l==NULL;
}
void display(node *l)
{
 if(!isempty(l))
 {
  cout<<"\n\nLinked List is :\n";
  for(node *t=l;t;t=t->next)
   cout<<t->data<<" ";
  cout<<"\n\n";
 }
 else
  cout<<"\n\nLinked List is empty.\n\n";
}
void insert(node* &a)
{
 node *l;
 if(a==NULL)
 {
  a=new node;
  cout<<"\nEnter data : ";
  cin>>a->data;
  a->next=NULL;
  return;
 }
 for(l=a;l->next;l=l->next);
 l->next=new node;
 l=l->next;
 cout<<"\nEnter data : ";
 cin>>l->data;
 l->next=NULL;
}
void del(node* &a)
{
 node *t,*l;
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
 for(l=a;l->next->next;l=l->next);
 t=l->next;
 l->next=NULL;
 delete t;
}
void rev(node *h,node* &hh)
{
 if(h->next)
  rev(h->next,hh);
 else
 { 
  hh=h;
  return;
 }
 h->next->next=h;
 h->next=NULL;
}
void last_nth(node *h)
{
 node *t=h;
 int n;
 cout<<"\nEnter value of n : ";
 cin>>n;
 for(;h&&(--n);h=h->next);
 if(n)
 {
  cout<<"\nThere are less tha n nodes.\n";
  return;
 }
 for(;h->next;h=h->next,t=t->next);
 cout<<endl<<endl<<"Data is : "<<t->data<<endl<<endl;
}
void bubble_sort(node *h)
{
 node *a,*b,*c;
 for(a=h;a->next;a=a->next)
  for(b=h,c=a;c->next;c=c->next,b=b->next)
   if(b->next->data<b->data)
    swap(b->next->data,b->data);
}
int main()
{
 int ch,n;
 node *head=NULL;
 while(ch)
 {
  cout<<"Enter option :\n1 to insert an element in a Linked List.";
  cout<<"\n2 to delete at last in Linked List.\n3 to find nth last node in singly Linked List.";
  cout<<"\n4 to perform Bubble Sort in Linked List.\n5 to display.\n6 to reverse singly Linked List.\n";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : insert(head); break;
   case 2 : del(head); break;
   case 3 : last_nth(head); break;
   case 4 : bubble_sort(head);
   case 5 : display(head);
            break;
   case 6 : rev(head,head);
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

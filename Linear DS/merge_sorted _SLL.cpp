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
void merge(node *a,node *b,node* &c)
{
 c=new node;
 node *h=c;
 while(a&&b)
 {
  h->next=new node;
  h=h->next;
  if(a->data<b->data)
  { 
   h->data=a->data;
   a=a->next;
  }
  else
  {
   h->data=b->data;
   b=b->next;
  }
 }
 while(a)
 {
  h->next=new node;
  h=h->next;
  h->data=a->data;
  a=a->next;
 }
 while(b)
 {
  h->next=new node;
  h=h->next;
  h->data=b->data;
  b=b->next;
 }
 h->next=NULL;
 c=c->next;
}
int main()
{
 int ch,n;
 node *head1,*head2,*head;
 head1=head2=head=NULL;
 while(ch)
 {
  cout<<"Enter option :\n1 to insert an element in a Linked List 1.";
  cout<<"\n2 to delete at last in Linked List 1.\n3 to insert an element in a Linked List 2.";
  cout<<"\n4 to delete at last in Linked List 2.\n5 to merge both singly Linked List.";
  cout<<"\n6 to display Linked List 1.\n7 to display Linked List 2.\n0 to terminate the program.\n";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : insert(head1); break;
   case 2 : del(head1); break;
   case 3 : insert(head2); break;
   case 4 : del(head2); break;
   case 5 : merge(head1,head2,head);
            display(head);
            break;
   case 6 : display(head1); break;
   case 7 : display(head2); break;
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

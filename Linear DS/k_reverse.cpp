#include<iostream>
using namespace std;
struct node
{
 union datatype
 {
  int a;
  float b;
  char c;
 };
 datatype data;
 int type;
 node *next;
}*head;
void insert()
{
 node *temp,*tmp=new node;
 cout<<"Enter Type (1 for int, 2 for float & 3 for char): ";
 cin>>tmp->type;
 cout<<"\nEnter Data : ";
 switch(tmp->type)
 {
  case 1: cin>>tmp->data.a; break;
  case 2: cin>>tmp->data.b; break;
  case 3: cin>>tmp->data.c; break;
 }
 tmp->next=NULL;
 if(!head)
  head=tmp;
 else
 { 
  for(temp=head;temp->next;temp=temp->next);
  temp->next=tmp;
 }
}
void disp(node *t)
{
 if(!t) return;
 switch(t->type)
 {
  case 1: cout<<t->data.a; break;
  case 2: cout<<t->data.b; break;
  case 3: cout<<t->data.c; break;
 }
 cout<<" ";
 disp(t->next);
}
void reverse(node *h,node* &new_head)
{
  if(h->next==NULL)
  {
   new_head=h;
   return;
  }
   reverse(h->next,new_head);
   h->next->next=h;
   h->next=NULL;
}
void K_REVERSE(node* &head,int K)
{
 node *tmp,*x,*y,*z; int i; bool fl=1;
 x=head;
 while(1)
 {
  for(tmp=x,i=1;i<K&&tmp;i++,tmp=tmp->next);
  if(tmp==NULL)
  {
   y->next=x;
   break;
  }
  z=tmp->next;
  tmp->next=NULL;
  reverse(x,x);
  if(fl){ head=x; fl=0; }
  else y->next=x;
  for(y=x;y->next!=NULL;y=y->next);
  x=z;
 }
}
int main()
{
 int K,n; head=NULL;
 cout<<"\nEnter no. of nodes : ";
 cin>>n;
 for(int i=0;i<n;i++)
  insert();
 cout<<"\nLinked List is : ";
 disp(head);
 for(int i=0;i<3;i++)
 {
  cout<<"\nEnter value of K : ";
  cin>>K;
  K_REVERSE(head,K);
  cout<<"\nNow Linked List is : ";
  disp(head);
 }
}
//10 1 1 1 2 2 3.8 1 4 1 5 1 6 3 A 2 8.9 3 B 1 10
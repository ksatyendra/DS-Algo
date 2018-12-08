#include<iostream>
#include<conio.h>
using namespace std;
struct cl
{
 int data;
 cl *next;
};
void show(cl *hh)
{
 cl *h;
 for(h=hh;h->next!=hh;h=h->next)
  cout<<h->data<<" ";
 cout<<h->data<<endl;
}
cl *deleteM(cl *head,int M)
{
 cl *tmp,*t=head; int i;
 if(M==1)
 {
  while(t->next!=head)
   t=t->next;
  return t;
 }
 while(1)
 {
  for(i=1;(i<M-1) && (t->next!=t);i++,t=t->next);
  tmp=t->next;
  t->next=t->next->next;
  delete tmp;
  show(t);
  if(t->next==t)
   return t;
  t=t->next;
 }
}
int main()
{
  cl *t,*head=NULL; int i,N,M;
  cout<<"\nEnter N & M : ";
  cin>>N>>M;
  for(i=0;i<N;i++)
  {
   if(head==NULL)
   {
    head=new cl();
    head->data=i+1;
    t=head;
   }
   else
   {
    t->next=new cl;
    t=t->next;
    t->data=i+1;
   }
  }
  t->next=head;
  head=deleteM(head,M);
  cout<<"\nAnswer : "<<head->data<<endl;
}
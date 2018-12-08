#include<iostream>
using namespace std;
class Stack
{
 private:
 struct stk
 {
  int data;
  stk *next;
 }*head;
 public:
 Stack(){ head=NULL; }
 bool isEmpty(){ return head==NULL; }
 void push(int d)
 {
  stk *t=new stk;
  t->data=d;
  t->next=head;
  head=t; 
 }
 int topElement()
 {
  if(head) return head->data;
  return INT_MAX;
 }
 int pop()
 {
  int k=topElement();
  stk *t=head;
  head=head->next;
  delete t;
  return k;
 }
 void display()
 {
  for(stk *t=head;t;t=t->next)
   cout<<t->data<<" ";
  cout<<endl;
 }
}s1,s2;
class Queue
{
 private:
 struct qu
 {
  int data;
  qu *next;
 }*head;
 public:
 Queue(){ head=NULL; }
 bool isEmpty(){ return head==NULL; }
 void enqueue(int d)
 {
  qu *t;
  if(isEmpty())
  {
   head=new qu;
   head->data=d;
   head->next=NULL;
  }
  else
  {
   for(t=head;t->next;t=t->next);
   t->next=new qu;
   t=t->next;
   t->data=d;
   t->next=NULL;
  }
 }
 int lastElement()
 {
  if(head) return head->data;
  return INT_MAX;
 }
 int dequeue()
 {
  int k=lastElement();
  qu *t=head;
  head=head->next;
  delete t;
  return k;
 }
 void display()
 {
  for(qu *t=head;t;t=t->next)
   cout<<t->data<<" ";
  cout<<endl;
 }
}q;
void qsort(Queue q,Stack s1,Stack s2)
{
int k=q.dequeue();
  while(!q.isEmpty())
  {
  if(s1.isEmpty()||k>=s1.topElement())
   s1.push(k);
  else
  {
   while(s1.topElement()>k)
    s2.push(s1.pop());
   s1.push(k);
   while(!s2.isEmpty())
    s1.push(s2.pop());
  }

 k=q.dequeue();
}
 while(!s1.isEmpty())
  q.enqueue(s1.pop());
 cout<<"\nSorted Queue : ";
 q.display();
}
int main()
{
  int n,k,i;
  cout<<"\nEnter no. of elements in queue : ";
  cin>>n;
  cout<<"\nEnter elements of queue : ";
  for(i=0;i<n;i++)
  {
   cin>>k;
   q.enqueue(k);
  }
  cout<<"\nQueue is : ";
  q.display();
  cout<<"\nPerforming sorting of Queue ...\n";
  qsort(q,s1,s2);
}
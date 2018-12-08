#include<iostream>
using namespace std;
struct lst
{
    int d;
    int key;
    lst *lk;
};
void show(lst *l)
{
 if(l)
 {
  for(lst *p=l;p;p=p->lk)
   cout<<"\nKey : "<<p->key<<"\t\tValue : "<<p->d<<endl;
 }
 else
  cout<<"\nQueue is empty.!!!\n";
}
void enqueue(lst* &l)
{
    lst *t,*k;
    t=new lst;
    cout<<"\nEnter the key : ";
    cin>>t->key;
    cout<<"\nEnter the data : ";
    cin>>t->d;
    t->lk=NULL;
    if(l)
    {
     if(l->lk)
     {
      for(k=l; k->lk && t->key > k->lk->key;k=k->lk);
      t->lk=k->lk;
      k->lk=t;
     }
     else if(t->key>l->key)
        l->lk=t;
     else
     { 
      t->lk=l;
      l=t;
     }
    } 
    else
    {
      l=t;
      l->lk=NULL;
    }      
}
void dequeue(lst* &l)
{
   if(l)
   {
    cout<<"\nDequeued Data : "<<l->d<<endl;
    l=l->lk;
   }
   else
    cout<<"\nQueue is empty.!!!\n";
}
int main()
{
  int k=1;
  lst *l=NULL;
  while(k)
  {
   cout<<"\nEnter 1 to enqueue, 2 to dequeue Queue & 3 to show & 0 to terminate : ";
   cin>>k;
   if(k==3)
    show(l);
   else if(k==1)
    enqueue(l);
   else if(k==2)
    dequeue(l);
  }
}
#include<iostream>
using namespace std;
struct lst
{
    int d;
    lst *lk;
};
void init(lst* &l)
{
   int i;
   lst *p;
   l=NULL;
   cout<<"\nEnter no. of elements : ";
   cin>>i;
   while(i--)
   {
    if(l==NULL){l=new lst;l->lk=NULL;cin>>l->d;p=l;}
    else
    {
     p->lk=new lst;
     p=p->lk;
     cin>>p->d;
     p->lk=NULL;
    }
   }
}
void show(lst *l)
{
  for(lst *p=l;p;p=p->lk)
   cout<<p->d<<" ";
}
void enqueue(lst* &l)
{
    cout<<"\nEnter the data : ";
    lst *t=new lst;
    cin>>t->d;
    t->lk=l;
    l=t;
}
int dequeue(lst* &l)
{
   if(!l)
    return INT_MIN;
   else if(!l->lk)
   {
    int x=l->d;
    l=NULL;
    return x;
   }
   lst *t;
   for(t=l;t->lk->lk;t=t->lk);
   int x=t->lk->d;
   t->lk=NULL;
   return x;
}
int main()
{
  int k=1;lst *l=NULL;
  while(k)
  {
   cout<<"\nEnter 1 to enqueue, 2 to dequeue, 3 to show,4 to initialize Queue & 0 to terminate : ";
   cin>>k;
   if(k==1)
    enqueue(l);
   else if(k==2)
    cout<<"\nDequeued data : "<<dequeue(l)<<endl;
   else if(k==3)
    show(l);
   else if(k==4)
    init(l);
  }
}
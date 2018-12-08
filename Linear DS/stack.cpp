#include<iostream>
using namespace std;
struct lst
{
    int d;
    lst *lk;
};
void show(lst *l)
{
  for(lst *p=l;p;p=p->lk)
   cout<<p->d<<" ";
}
void push(lst **l)
{
    cout<<"\nEnter the data : ";
    lst *t=new lst;
    cin>>t->d;
    t->lk=*l;
    *l=t;
}
int pop(lst **l)
{
   if(!*l)
    return INT_MIN;
   int x=(*l)->d;
   *l=(*l)->lk;
   return x;
}
int main()
{
   int i=-1,k=1;lst *l=NULL,*p;
   for(;++i<5;)
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
  while(k)
  {
   cout<<"\nEnter 1 to push, 2 to pop, 3 to show  stack & 0 to terminate : ";
   cin>>k;
   if(k==1)
    push(&l);
   else if(k==2)
    cout<<"\nPopped data : "<<pop(&l)<<endl;
   else if(k==3)
    show(l);
  }
}

#include<iostream>
using namespace std;
struct lst
{
    int d;
    lst *lk;
}*hd;
void disp(lst *t)
{
  if(t) disp(t->lk),cout<<t->d<<" ";
}
void bblsrt(lst *t)
{
 lst *t1,*t2,*aa;
 for(t1=t;t1;t1=t1->lk)
  for(t2=t,aa=t1;aa->lk;t2=t2->lk,aa=aa->lk)
   if(t2->d>t2->lk->d)
    swap(t2->d,t2->lk->d);
}
void selsrt(lst *t)
{
 lst *t1,*t2;
 for(t1=t;t1;t1=t1->lk)
  for(t2=t1->lk;t2;t2=t2->lk)
   if(t1->d>t2->d)
    swap(t1->d,t2->d);
}
/*void inssrt(lst *t)
{
 int i,j,k;
 for(i=1;i<15;i++)
 {
  for(j=0;j<i;j++)
   if(a[j]>a[i])
    {
     int x=a[j];
     a[j]=a[i];
     for(k=j+1;k<=i;k++)
     swap(a[k],x);
    }
 }
}*/
void rev(lst* l)
{
  if(!l) return;
  if(l->lk)
  { 
   rev(l->lk);
   l->lk->lk=l;
  }
  else
   hd=l;
}
void inssrt(lst *t)
{
 lst *t1,*t2,*t3;
 for(t1=t->lk;t1;t1=t1->lk)
 {
  int x=t1->d;
  for(t3=t;t3!=t1&&t3->d<x;t3=t3->lk);
  for(;t3!=t1;t3=t3->lk)
  swap(t3->d,x);
  t3->d=x;
 }
}
void revv(lst* &l)
{
 lst *t,*prv=NULL,*nxt;
 if(!t->lk)
  return;
 for(t=l;t;)
 { 
  nxt=t->lk;
  t->lk=prv;
  prv=t;
  t=nxt;
 }
 l=prv;
}
int main()
{
   int i=-1;lst *l=NULL,*p;
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
   disp(l);
   rev(l);
   l->lk=NULL;
   disp(hd);
  /*inssrt(l);
  for(p=l;p;p=p->lk)
   cout<<p->d<<" ";*/
  cin>>i;
}
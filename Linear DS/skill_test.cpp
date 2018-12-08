#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct lst
{
    int d;
    lst *lk;
};
bool searchL(lst **k,int n,lst *t)
{
  for(int i=0;i<n;i++)
   if(k[i]==t)
    return 1;
  return 0;
}
string isloop(lst *l)
{
 lst **k=new lst*[10];
 int i=0;
 for(lst *t=l;t->lk!=NULL;t=t->lk)
 {
  if(searchL(k,i,t))
   return "YES\n";
  else
    k[i++]=t;
 }
 return "No\n";
}
void show_nth_last(lst *l,int k)
{
  lst *p,*q;
  int n=k;
  for(p=l;--n&&p->lk;p=p->lk);
  if(n)
  {
   cout<<"Not Possible\n";
   return;
  }
  for(q=l;p->lk;p=p->lk,q=q->lk);
  cout<<k<<"th last Data is : "<<q->d<<endl;
}
void bubble_del_duplicate(lst *t)
{
 lst *t1,*t2,*aa,*bb;
 for(t1=t;t1;t1=t1->lk)
 {
  for(t2=t,aa=t1;aa->lk;t2=t2->lk,aa=aa->lk)
   if(t2->d>t2->lk->d)
    swap(t2->d,t2->lk->d);
  if(t2->lk)
   t2->lk->d==t2->d?t2->lk=t2->lk->lk:t2=t2->lk;
 }
}
int main()
{
   int i=-1;lst *l=NULL,*p;
   for(;++i<5;)
   {
   if(l==NULL)
   {
    l=new lst;
    l->lk=NULL;
    cin>>l->d;
    p=l;
   }
   else
   {
    p->lk=new lst;
    p=p->lk;
    cin>>p->d;
    p->lk=NULL;
   }
  }
  //p->lk=l; p->lk=l->lk->lk;
  bubble_del_duplicate(l);
  show_nth_last(l,1);
  show_nth_last(l,2);
  show_nth_last(l,3);
  show_nth_last(l,4);
  show_nth_last(l,5);
  cout<<isloop(l);
  cin>>i;
}
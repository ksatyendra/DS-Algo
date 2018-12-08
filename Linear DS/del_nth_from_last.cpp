#include<iostream>
using namespace std;
struct lst
{
    int d;
    lst *lk;
}*hd;
void ins(lst* &l)
{
 if(l==NULL)
 {
  l=new lst;
  l->lk=NULL;
  cin>>l->d;
 }
 else
 {
  lst *p;
  for(p=l;p->lk;p=p->lk);
  p->lk=new lst;
  p=p->lk;
  cin>>p->d;
  p->lk=NULL;
 }
}
void disp(lst *l)
{
  for(lst *p=l;p;p=p->lk)
   cout<<p->d<<" ";
  cout<<endl;
}
void deln(lst* &l,int n)
{
  lst *p,*q;
  if(n)
   for(p=l;--n&&p->lk;p=p->lk);
  else
   p=l;
  if(n)
   cout<<"not possible";
  if(p->lk)
  {
   for(q=l;p->lk->lk;p=p->lk,q=q->lk);
   lst *t=q->lk;
   q->lk=q->lk->lk;
   delete t;
  }
  else
  {
   lst *t=l;
   l=l->lk;
  }
}
int main()
{
 lst *l=NULL;
 int ch,n;
 while(1)
 {
  cin>>ch;
  if(!ch) break;
  switch(ch)
  { 
   case 1:ins(l); break;
   case 2:cout<<"link list is :\n";
          disp(l); break;
   case 3:cin>>n;
          deln(l,n);
          cout<<"res is :\n";
          disp(l); break;
  }
 }
}
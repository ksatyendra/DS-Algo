#include<iostream>
using namespace std;
struct mtr
{
    int d;
    mtr *lk;
    mtr *nx;
}*hd;
void create(mtr* &t)
{
 int ch=2;
 t=new mtr;
 mtr *k,*l=t;
 cout<<"enter root data : ";
 cin>>t->d;
 t->lk=NULL;
 t->nx=NULL;
 while(ch)
 {
  if(!ch)
   break;
  cout<<"enter choice : ";
  cin>>ch;
  for(k=l;ch-1;)
  {
   k->lk=new mtr;
   k=k->lk;
   create(k->lk);
   cout<<"enter choice : ";
   cin>>ch;
  }
  for(k=l;ch;)
  {
   k->nx=new mtr;
   k=k->nx;
   cout<<"enter sib data : ";
   cin>>k->d;
   cout<<"enter choice : ";
   cin>>ch;
   k->lk=NULL;
   k->nx=NULL;
  }
 }
}
void show(mtr *h)
{
 cout<<h->d<<" ";
 if(h->nx)
  show(h->nx);
 if(h->lk)
  show(h->lk);
}
void rev(mtr* l)
{
  if(l->lk->lk)
  { 
   rev(l->lk);
   l->lk->lk=l;
   l->lk=NULL;
  }
  else
  {
   hd=l->lk;
   l->lk->lk=l;
  }
}
int main()
{
 mtr *h=NULL;
 create(h);
 show(h);
}
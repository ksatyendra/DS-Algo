#include<iostream>
using namespace std;
struct lt
{
 int d; lt *n; lt *r;
};
void insert(lt *&h)
{
 lt *a,*t=new lt; t->r=t->n=NULL;
 cout<<"\nEnter Data : "; cin>>t->d;
 if(!h) h=t;
 else
 {
  for(a=h;a->n;a=a->n);
  a->n=t;
 }
}
void random(lt *h)
{
 int x; lt *t,*j;
 for(t=h;t;t=t->n)
 {
  cout<<"\nEnter random for "<<t->d<<" : "; cin>>x;
  for(j=h;j;j=j->n)
   if(j->d==x)
   {
    t->r=j;
    break;
   }
 }
}
void clone(lt *h,lt *&g)
{
 lt *t,*u;
 for(t=h;t;t=t->n)
 {
  u=new lt;
  u->d=t->d;
  u->r=t->r;
  t->r=u;
 }
 g=h->r;
 for(t=h,u=g;t->n;t=t->n,u=u->n)
 {
  u->r=u->r->r;
  u->n=t->n->r;
 }
 u->n=NULL;
}
void dispn(lt *t)
{
  if(!t) return;
  cout<<t->d<<" ";
  dispn(t->n);
}
void dispr(lt *t)
{
  if(!t) return;
  if(t->r) cout<<t->r->d<<" ";
  else cout<<"* ";
  dispr(t->n);
}
int main()
{
   lt *g,*h; h=g=NULL; int ch=1;
   while(ch)
   {
    cout<<"\nEnter choice : ";
    cin>>ch;
    if(!ch) break;
    if(ch==1) insert(h);
    if(ch==2) random(h);
    if(ch==3)
    {
     dispn(h);
     cout<<endl;
     dispr(h);
    }
    if(ch==4)
    {
     dispn(g);
     cout<<endl;
     dispr(g);
    }
    if(ch==5)
     clone(h,g);
   }
}//1 1 1 2 1 3 1 4 1 5 2 3 3 3 5 2 3 5 4
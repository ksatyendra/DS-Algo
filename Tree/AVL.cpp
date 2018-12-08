#include<iostream>
using namespace std;
bool fl;
class avl
{
 public: int d,ht; avl *l,*r;
 avl(int k){ d=k; ht=0; l=NULL; r=NULL; }
 avl(int k,int hh){ d=k; ht=hh; l=NULL; r=NULL; }
 avl(int k,int hh,avl *a,avl *b){ d=k; ht=hh; l=a; r=b; }
};
void pre_order_traversal(avl *h){ if(!h) return; cout<<h->d<<" "; pre_order_traversal(h->l); pre_order_traversal(h->r); }
void in_order_traversal(avl *h){ if(!h) return; in_order_traversal(h->l); cout<<h->d<<" "; in_order_traversal(h->r); }
void post_order_traversal(avl *h){ if(!h) return; post_order_traversal(h->l); post_order_traversal(h->r); cout<<h->d<<" "; }
int height(avl *h)
{
 if(!h) return -1;
 int a=height(h->l),b=height(h->r);
 if(a>b) return a+1;
 else return b+1;
}
void rec_level(avl *h,int i){ if(!i){ if(h) cout<<h->d<<"("<<h->ht<<") "; return; } rec_level(h->l,i-1); rec_level(h->r,i-1); }
void level_order_traversal(avl *h){ for(int i=0,ht=height(h); i<=ht; cout<<endl,i++) rec_level(h,i); }
int max(avl *a,avl *b,int &x)
{
 x=0;
 if(a && b)
 {
  x=a->ht-b->ht;
  if(a->ht>b->ht)
   return a->ht;
  else
   return b->ht;
 }
 else if(a)
 {
  x=a->ht+1;
  return a->ht;
 }
 else if(b)
 {
  x=-1-b->ht;
  return b->ht;
 }
 else
  return -1;
}
void left_rotate(avl* &h)
{
 avl *t=h->r; int x;
 h->r=t->l;
 t->l=h;
 h->ht=max(h->l,h->r,x)+1;
 h=t;
 t->ht=max(t->l,t->r,x)+1;
 if(h->r)
  t=h->r,t->ht=max(t->l,t->r,x)+1;
}
void right_rotate(avl* &h)
{
 avl *t=h->l; int x;
 h->l=t->r;
 t->r=h;
 h->ht=max(h->l,h->r,x)+1;
 h=t;
 t->ht=max(t->l,t->r,x)+1;
 if(h->l)
  t=h->l,t->ht=max(t->l,t->r,x)+1;
}
void left_right_rotate(avl* &h)
{
 left_rotate(h->l);
 right_rotate(h);
}
void right_left_rotate(avl* &h)
{
 right_rotate(h->r);
 left_rotate(h);
}
void insert(avl* &h,int k)
{
 int bal_fac;
 if(!h)
  h=new avl(k);
 else if(k<=h->d)
 {
  insert(h->l,k);
  h->ht=max(h->l,h->r,bal_fac)+1;
  if(bal_fac>1)
  {
   if(h->r||h->l->l)
    right_rotate(h);
   else
    left_right_rotate(h);
  }
 }
 else
 {
  insert(h->r,k);
  h->ht=max(h->l,h->r,bal_fac)+1;
  if(bal_fac<-1)
  {
   if(h->l||h->r->r)
    left_rotate(h);
   else
    right_left_rotate(h);
  }
 }
}
bool search(avl *h,int k)
{
 if(!h)
  return 0;
 if(k==h->d)
  return 1;
 else if(k<h->d)
  return search(h->l,k);
 else
  return search(h->r,k);
}
bool deleteT(avl* &h,int k)
{
 bool q; int bal_fac; avl *t;
 if(!h)
  return 0;
 if(h->d==k)
 {
  if(h->l && h->r)
  {
   t=h->l;
   while(t->r) t=t->r;
   h->d=t->d;
   deleteT(h->l,t->d);
  }
  else if(h->l)
   h=h->l;
  else if(h->r)
   h=h->r;
  else
   h=NULL;
  q=1;
 }
 else if(k<=h->d)
 {
  q=deleteT(h->l,k);
  h->ht=max(h->l,h->r,bal_fac)+1;
  if(bal_fac>1)
  {
   if(h->r||h->l->l)
    right_rotate(h);
   else
    left_right_rotate(h);
  }
 }
 else
 {
  q=deleteT(h->r,k);
  h->ht=max(h->l,h->r,bal_fac)+1;
  if(bal_fac<-1)
  {
   if(h->l||h->r->r)
    left_rotate(h);
   else
    right_left_rotate(h);
  }
 }
 return q;
}
int main()
{
 int ch=1,k; avl *h=NULL; fl=0;
 while(ch)
 {
  cout<<"\nEnter Choice : "; cin>>ch;
  if(!ch) break;
  if(ch==1)
  {
   cout<<"\nEnter Data to insert : ";
   cin>>k;
   insert(h,k);
  }
  if(ch==2)
  {
   cout<<"\nEnter data to search : ";
   cin>>k;
   if(search(h,k))
    cout<<"\nIt is there\n";
   else
    cout<<"\nIt is not there.\n";
  }
  if(ch==3)
  {
   cout<<"\nEnter data to delete : ";
   cin>>k;
   if(deleteT(h,k))
    cout<<"\nDeleted\n";
   else
    cout<<"\nIs not there.\n";
  }
  if(ch==4){ cout<<"\nPreorder : "; pre_order_traversal(h); }
  if(ch==5){ cout<<"\nInorder : "; in_order_traversal(h); }
  if(ch==6){ cout<<"\nPostorder : "; post_order_traversal(h); }
  if(ch==7){ cout<<"\nLevelorder : "; level_order_traversal(h); }
 }
}
//1 1 1 2 1 3 1 4 1 5 1 6 1 7 1 8 1 9 1 10 1 11 1 12 1 13
//1 38 1 40 1 42 1 44 1 46 1 48 1 47 7
//1 45 1 23 1 55 1 21 1 33 1 49 1 62 1 5 1 22 1 32 1 34 1 48 1 50 1 61 1 63 0
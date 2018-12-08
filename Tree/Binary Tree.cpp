#include<iostream>
using namespace std;
class bt
{
 public: int d; bt *l,*r;
 bt(int dt,bt *ll,bt *rr){ d=dt; l=ll; r=rr; }
 bt(int dt){ d=dt; l=NULL; r=NULL; }
};
void insert(int k,bt* &h)
{
 if(!h){ h=new bt(k); return; }
 char ch; cout<<"\nEnter 'l' or 'r' : "; cin>>ch;
 if(ch=='l') insert(k,h->l);
 else insert(k,h->r);
}
bool deleteT(bt* &h,int k)
{
 bt *t;
 if(!h) return 0;
 if(h->d==k)
 {
  if(!(h->l||h->r))
   h=NULL;
  else if(!h->l)
   h=h->r;
  else if(!h->r)
   h=h->l;
  else
  {
   bt *tmp,*t=h;
   while(t->l->l)
    t=t->l;
   swap(h->d,t->l->d);
   tmp=t->l;
   t->l=NULL;
   delete tmp;
  }
  return 1;
 }
 return deleteT(h->l,k)||deleteT(h->r,k);
}
void pre_order(bt *h){ if(!h) return; cout<<h->d<<" "; pre_order(h->l); pre_order(h->r); }
void in_order(bt *h){ if(!h) return; in_order(h->l); cout<<h->d<<" "; in_order(h->r); }
void post_order(bt *h){ if(!h) return; post_order(h->l); post_order(h->r); cout<<h->d<<" "; }
void min(bt *h,int &m)
{
 if(!h) return;
 if(h->d<m) m=h->d;
 min(h->l,m);
 min(h->r,m);
}
void max(bt *h,int &m)
{
 if(!h) return;
 if(h->d>m) m=h->d;
 max(h->l,m);
 max(h->r,m);
}
int main()
{
 int ch=1,k;bt *root=NULL;
 while(ch)
 {
  cout<<"\nEnter choice : ";
  cin>>ch;
  if(!ch) break;
  if(ch==1){ cout<<"\nEnter Data : "; cin>>k; insert(k,root); }
  if(ch==2)
  {
   cout<<"\nEnter no. to delete : "; cin>>k;
   if(deleteT(root,k)) cout<<"\nDeleted";
   else cout<<"\nNot there.";
  }
  if(ch==3)
  {
   cout<<"\nPre Order : "; pre_order(root);
   cout<<"\nIn Order : "; in_order(root);
   cout<<"\nPost Order : "; post_order(root);
  }
  if(ch==4 && root){ k=INT_MAX; min(root,k); cout<<"\nMINIMUM : "<<k<<endl; }
  if(ch==5 && root){ k=INT_MIN; max(root,k); cout<<"\nMAXIMUM : "<<k<<endl; }
 }
}// 1 37 1 34 l 1 35 r 1 33 l r 1 57 l r l 1 59 r l 1 666 r r 1 567 r r r 1 22 r r r l
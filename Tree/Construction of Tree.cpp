#include<iostream>
using namespace std;
class bst
{
 public: int d; bst *l; bst *r;
 bst(int k,bst *a,bst *b){ d=k; l=a; r=b; }
 bst(int k,bst *b,bst *a,int x){ d=k; l=a; r=b; }
};
class ll { public: int d; ll *lk; ll(){ lk=NULL; } };
class stk
{
 private: bst *d; stk *lk;
 public: stk(){ d=NULL; lk=NULL; }
 stk(bst *k,stk *t){ d=k; lk=t; }
 bool isEmpty(stk *l){ return l==NULL; }
 void push(bst *k,stk* &l){ stk *g=new stk(k,l); l=g; }
 bst *pop(stk* &l){ if(!l) return NULL; bst *x=l->d; l=l->lk; return x; }
};
class Q
{
 private: bst *d; Q *lk;
 public: Q(){ d=NULL; lk=NULL; }
 Q(bst *k,Q *t){ d=k; lk=t; }
 bool isEmpty(Q *l){ return l==NULL; }
 void EQ(bst *k,Q* &l){ Q *g=new Q(k,l); l=g; }
 bst *DQ(Q* &l)
 {
  Q *t;
  if(!l) return NULL;
  if(!(l->lk)){ bst *x=l->d; l=NULL; return x; }
  for(t=l;t->lk->lk;t=t->lk);
  bst *x=t->lk->d; t->lk=NULL; return x;
 }
};
void pre_order_traversal(bst *h)
{
 if(!h) return;
 cout<<h->d<<" "; pre_order_traversal(h->l); pre_order_traversal(h->r);
}
void in_order_traversal(bst *h)
{
 if(!h) return;
 in_order_traversal(h->l); cout<<h->d<<" "; in_order_traversal(h->r);
}
void post_order_traversal(bst *h)
{
 if(!h) return;
 post_order_traversal(h->l); post_order_traversal(h->r); cout<<h->d<<" ";
}
void rev(ll* l,ll* &h)
{
  if(l->lk->lk)
  { 
   rev(l->lk,h);
   l->lk->lk=l;
   l->lk=NULL;
  }
  else
  {
   h=l->lk;
   h->lk=l;
  }
}
bst *prein(int *a,int *b,int st,int end)
{
 static int stt=0; int x;
 if(st>end)
  return NULL;
 for(x=st-1;b[++x]!=a[stt];);
 bst *h=new bst(a[stt++],prein(a,b,st,x-1),prein(a,b,x+1,end));
 return h;
}
bst *pre_in(ll *&a,ll *b)
{
 if(!b) return NULL; int x=a->d; a=a->lk; ll *p,*t=b;
 if(b->d!=x){ while(t->lk->d!=x) t=t->lk; p=t->lk->lk; t->lk=NULL;}
 else { p=b->lk; b=NULL;}
 bst *h=new bst(x,pre_in(a,b),pre_in(a,p)); return h;
}
bst *inpost(int *a,int *b,int st,int end)
{
 static int stt=end; int x;
 if(st>end) return NULL; for(x=st-1;b[++x]!=a[stt];);
 bst *h=new bst(a[stt--],inpost(a,b,x+1,end),inpost(a,b,st,x-1),0); return h;
}
bst *ip(ll *&a,ll *b)
{
 if(!b) return NULL; int x=a->d; a=a->lk; ll *p,*t=b;
 if(b->d!=x){ while(t->lk->d!=x) t=t->lk; p=t->lk->lk; t->lk=NULL;}
 else { p=b->lk; b=NULL; }
 bst *h=new bst(x,ip(a,p),ip(a,b),0); return h;
}
bst *in_post(ll* &a,ll *b)
{
 rev(a,a);
 return ip(a,b);
}
bst *levelin(int *a,int *b,int is,int ie,int ls,int lt)
{
 if(is>ie||ls>lt) return NULL; int j;
 for(;ls<=lt;ls++){ for(j=is;(j<=ie) && (a[ls]!=b[j]);j++); if(a[ls]==b[j]) break; }
 bst *h=new bst(a[ls],levelin(a,b,is,j-1,ls+1,lt),levelin(a,b,j+1,ie,ls+1,lt)); return h;
}
int main()
{
 int ch=1; bst *h,*root=NULL;
 while(ch)
 {
  cout<<"\nchoice : "; cin>>ch;
  if(!ch) break;
  if(ch==1)
  {
   int pre[10]={1,2,4,5,6,7,3,8,9,10},in[10]={4,2,5,7,6,1,8,10,9,3};
   root=prein(pre,in,0,9);
   ch=13;
  }
  if(ch==2)
  {
   int in[11]={4,2,5,7,6,1,8,10,9,3,11},post[11]={4,7,6,5,2,10,9,8,11,3,1};
   root=inpost(post,in,0,10);
   ch=13;
  }
  if(ch==3)
  {
    int in[11]={4,2,5,7,6,1,8,10,9,3,11},level[11]={1,2,3,4,5,8,11,6,9,7,10};
    root=levelin(level,in,0,10,0,10);
    ch=13;
  }
  if(ch==4)
  {
   int n,i; ll *a=new ll(); ll *b=new ll(); ll *t;
   cout<<"\nEnter no. of nodes : "; cin>>n;
   cout<<"\nEnter pre : "; cin>>a->d;
   for(t=a,i=1;i<n;i++) { t->lk=new ll(); t=t->lk; cin>>t->d; } t->lk=NULL;
   cout<<"\nEnter in : "; cin>>b->d;
   for(t=b,i=1;i<n;i++) { t->lk=new ll(); t=t->lk; cin>>t->d; }t->lk=NULL;
   root=pre_in(a,b); // 1 2 4 5 6 7 3 8 9 10 & 4 2 5 7 6 1 8 10 9 3
   ch=13;
  }
  if(ch==5)
  {
   int n,i; ll *a=new ll(); ll *b=new ll(); ll *t;
   cout<<"\nEnter no. of nodes : "; cin>>n;
   cout<<"\nEnter post : "; cin>>a->d;
   for(t=a,i=1;i<n;i++) { t->lk=new ll(); t=t->lk; cin>>t->d; } t->lk=NULL;
   cout<<"\nEnter in : "; cin>>b->d;
   for(t=b,i=1;i<n;i++) { t->lk=new ll(); t=t->lk; cin>>t->d; }t->lk=NULL;
   root=in_post(a,b); // 4 7 6 5 2 10 9 8 11 3 1 & 4 2 5 7 6 1 8 10 9 3 11
   ch=13;
  }
  if(ch==6)
  {
   int n,i; ll *a=new ll(); ll *b=new ll(); ll *t;
   cout<<"\nEnter no. of nodes : "; cin>>n;
   cout<<"\nEnter pre : "; cin>>a->d;
   for(t=a,i=1;i<n;i++) { t->lk=new ll(); t=t->lk; cin>>t->d; } t->lk=NULL;
   cout<<"\nEnter in : "; cin>>b->d;
   for(t=b,i=1;i<n;i++) { t->lk=new ll(); t=t->lk; cin>>t->d; }t->lk=NULL;
   root=pre_in(a,b); // 1 2 4 5 6 7 3 8 9 10 & 4 2 5 7 6 1 8 10 9 3
  }
  if(ch==13 && (h=root)) // display 
  {
   cout<<"\nLevel order : ";
   Q ob,*s=NULL; int i=0,k=0; ob.EQ(h,s);
   while(!ob.isEmpty(s))
   {
    h=ob.DQ(s); cout<<h->d<<" ";
    if(h->l) ob.EQ(h->l,s);
    if(h->r) ob.EQ(h->r,s);
   }
   cout<<"\nPre order : "; pre_order_traversal(root);
   cout<<"\nIn order : "; in_order_traversal(root);
   cout<<"\nPost order : "; post_order_traversal(root); cout<<endl;
  }
 } } //45 1 23 1 55 1 21 1 33 1 49 1 62 1 5 1 22 1 32 1 34 1 48 1 50 1 61 1 63 0
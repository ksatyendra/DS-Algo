#include<iostream>
using namespace std;
class bst
{
    public: int d; bst *l; bst *r;
    bst(int k){ d=k; l=NULL; r=NULL; }
    bst(int k,bst *a,bst *b){ d=k; l=a; r=b; }
    bst(int k,bst *b,bst *a,int x){ d=k; l=a; r=b; }
};
class Stack
{
 private:
 struct stk
 {
  bst *data;
  stk *next;
 }*head;
 public:
 Stack(){ head=NULL; }
 bool isEmpty(){ return head==NULL; }
 void push(bst *d)
 {
  stk *t=new stk;
  t->data=d;
  t->next=head;
  head=t; 
 }
 bst *topElement()
 {
  if(head) return head->data;
  return NULL;
 }
 bst *pop()
 {
  bst *k=topElement();
  stk *t=head;
  head=head->next;
  delete t;
  return k;
 }
 void disp(stk *t)
 {
  if(t->next)
   disp(t->next);
  cout<<t->data<<" ";
 }
 void display()
 {
  stk *t=head;
  disp(t);
 }
};
class Queue
{
 private:
 struct qu
 {
  bst *data;
  qu *next;
 }*head;
 public:
 Queue(){ head=NULL; }
 bool isEmpty(){ return head==NULL; }
 void enqueue(bst *d)
 {
  qu *t;
  if(isEmpty())
  {
   head=new qu;
   head->data=d;
   head->next=NULL;
  }
  else
  {
   for(t=head;t->next;t=t->next);
   t->next=new qu;
   t=t->next;
   t->data=d;
   t->next=NULL;
  }
 }
 bst *lastElement()
 {
  if(head) return head->data;
  return NULL;
 }
 bst *dequeue()
 {
  bst *k=lastElement();
  qu *t=head;
  head=head->next;
  delete t;
  return k;
 }
 void display()
 {
  for(qu *t=head;t;t=t->next)
   cout<<t->data<<" ";
 }
};
int height(bst *h)
{
 if(!h) return -1;
 int a=height(h->l),b=height(h->r);
 if(a>b) return a+1;
 else return b+1;
}
void insert(bst *&h,int k)
{
 if(!h) h=new bst(k);
 else if(k<=h->d) insert(h->l,k);
 else insert(h->r,k);
}
void pre_order(bst *h)
{
 if(!h){ cout<<"\nEmpty Tree\n"; return; }
 Stack s; s.push(h);
 while(!s.isEmpty())
 {
  h=s.pop(); cout<<h->d<<" ";
  if(h->r) s.push(h->r);
  if(h->l) s.push(h->l);
 }
}
void in_order(bst *h)
{
 if(!h){ cout<<"\nEmpty Tree\n"; return; }
 Stack s; while(1)
 {
  if(h){ s.push(h); h=h->l; }
  else if(!s.isEmpty()){ h=s.pop(); cout<<h->d<<" "; h=h->r; }
  else break;
 }
}
void post_order(bst *h)
{
 Stack s; bst *k=NULL;
 if(!h) { cout<<"\nEmpty Tree\n"; return; }
 s.push(h);
 while(!s.isEmpty())
 {
    h=s.topElement();
    if(!k || k->l==h || k->r==h)
    {
     if(h->l) s.push(h->l);
     else if(h->r) s.push(h->r);
    }
    else if(h->l==k){ if(h->r) s.push(h->r); }
    else cout<<s.pop()->d<<" ";
    k=h;
  }
}
void post_order_2_stack(bst *h)
{
 if(h==NULL){ cout<<"\nEmpty Tree\n"; return; }
 Stack s,k; s.push(h);
 while(!s.isEmpty())
 {
   h=s.pop(); k.push(h);
   if(h->l) s.push(h->l);
   if(h->r) s.push(h->r);
 }
 while(!k.isEmpty()) cout<<k.pop()->d<<" ";
}
void level_order(bst *h)
{
 if(h==NULL){ cout<<"\nEmpty Tree\n"; return; }
 Queue s; int i=0,k=0; s.enqueue(h);
 while(!s.isEmpty())
 {
  h=s.dequeue(); cout<<h->d<<" ";
  if(h->l) s.enqueue(h->l);
  if(h->r) s.enqueue(h->r);
 }
}
bst *findAddress(bst *h,int k)
{
 if(!h || h->d==k) return h;
 bst *a=findAddress(h->l,k),*b=findAddress(h->r,k);
 if(a||b) return a?a:b; return NULL;
}
void Zigzag(bst *h)
{
 if(h==NULL){ cout<<"\nEmpty Tree\n"; return; }
 Stack s,k; bool j=1; s.push(h);
 while(!s.isEmpty())
 {
  h=s.pop(); cout<<h->d<<" ";
  if(j){ if(h->l) k.push(h->l); if(h->r) k.push(h->r); }
  else{ if(h->r) k.push(h->r); if(h->l) k.push(h->l); }
  if(s.isEmpty()){ swap(s,k); j=1-j; }
 }
}
void ipath(bst *h)
{
 string a=""; Queue q; q.enqueue(h);
 while(!q.isEmpty())
 {
  h=q.dequeue(); a+=h->d;
  if(!(h->l||h->r)) { cout<<a<<endl; }
  if(h->l) q.enqueue(h->l);
  if(h->r) q.enqueue(h->r);
 }
}
bool issum(bst *h,int k)
{
 NULL;
}
void allAncestor(bst *h)
{
 NULL;
}
void leastAncestor(bst *h,bst *a,bst *b)
{
 NULL;
}
bst *prep(bst *h)
{
 NULL;
}
bst *inp(bst *h)
{
 NULL;
}
bst *postp(bst *h)
{
 NULL;
}
bst *pres(bst *h)
{
 NULL;
}
bst *ins(bst *h)
{
 NULL;
}
bst *posts(bst *h)
{
 NULL;
}
int main()
{
 int ch=1,k; bst *h=NULL;
 while(ch)
 {
  cout<<"\nEnter Choice : "; cin>>ch;
  if(!ch) break;
  if(ch==1){ cout<<"\ndata : "; cin>>k; insert(h,k); }
  if(ch==2)
  {
   cout<<"\nlevel_order_traversal : "; level_order(h);
   cout<<"\npre_order_traversal : "; pre_order(h);
   cout<<"\nin_order_traversal : "; in_order(h);
   cout<<"\npost_order_traversal : "; post_order(h);
   cout<<"\npost_with_2_stacks : "; post_order_2_stack(h);
  } // ITERATIVE TRAVERSAL
  if(ch==3){ cout<<"\nZigzag :\n"; Zigzag(h); }
  if(ch==6){ cout<<"\nPath :\n"; ipath(h); }
  if(ch==8){ cout<<"\nEnter sum : "; cin>>k; cout<<issum(h,k)<<endl; }
  if(ch==9){ cout<<"\nAll Ancestors : "; allAncestor(h); }
  if(ch==10)
  {
   cout<<"\nLeast Ancestor : ";
   bst *a,*b;
   cout<<"\nEnter First Data : "; cin>>k;
   a=findAddress(h,k);
   cout<<"\nEnter First Data : "; cin>>k;
   b=findAddress(h,k);
   leastAncestor(h,a,b);
  }
  if(ch==11){ cout<<"\nPre Order Precedessor : "<<prep(h)<<endl; }
  if(ch==12){ cout<<"\nIn Order Precedessor : "<<inp(h)<<endl; }
  if(ch==13){ cout<<"\nPost Order Precedessor : "<<postp(h)<<endl; }
  if(ch==14){ cout<<"\nPre Order Successor : "<<pres(h)<<endl; }
  if(ch==15){ cout<<"\nIn Order Successor : "<<ins(h)<<endl; }
  if(ch==16){ cout<<"\nPost Order Successor : "<<posts(h)<<endl; }
 }
} // 1 45 1 23 1 55 1 21 1 33 1 49 1 62 1 5 1 22 1 32 1 34 1 48 1 50 1 61 1 63
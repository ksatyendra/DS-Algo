#include<iostream>
#include<queue>
using namespace std;
class bst
{
 public: int d; bst *l,*r;
 bst(int k){ d=k; l=NULL; r=NULL; }
 bst(int k,bst *a,bst *b){ d=k; l=a; r=b; }
};
class Stack
{
 private:
 struct stk
 {
  int data;
  stk *next;
 }*head;
 public:
 Stack(){ head=NULL; }
 bool isEmpty(){ return head==NULL; }
 void push(int d)
 {
  stk *t=new stk;
  t->data=d;
  t->next=head;
  head=t; 
 }
 int topElement()
 {
  if(head) return head->data;
  return INT_MAX;
 }
 int pop()
 {
  int k=topElement();
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
}q;
int height(bst *h)
{
 if(!h) return -1;
 int a=height(h->l),b=height(h->r);
 if(a>b) return a+1;
 else return b+1;
}
int min_height(bst *h)
{
 if(!h) return -1;
 int a=height(h->l),b=height(h->r);
 if(a<b) return a+1;
 else return b+1;
}
void insert(bst *&h,int k)
{
 if(!h) h=new bst(k);
 else if(k<=h->d) insert(h->l,k);
 else insert(h->r,k);
}
bool checkcomplete(bst* root)
{
 if(root==NULL)
  return 1;
 int c=0,x=1; bst *tmp;
 queue<bst*> q;
 q.push(root);
 q.push(NULL);
 while(!q.empty())
 {
  tmp=q.front(); q.pop();
  c++;
  if(tmp==NULL)
  {
   if(c!=x && !q.empty())
    return 0;
   if(c!=x && q.empty())
    return 1;
   if(c==x)
    q.push(NULL);
   c=0;
  }
  x*=2;
  if(tmp->l)
   q.push(tmp->l);
  if(tmp->r)
   q.push(tmp->r);
 }
}
bool deleteT(bst* &h,int k)
{
 bst *tmp;
 if(!h)
  return 0;
 if(h->d==k)
 {
  if(!(h->l||h->r))
   h=NULL;
  else if(!h->l)
   h=h->r;
  else if(!h->r)
   h=h->l;
  else if(h->l->r)
  {
   bst *t;
   for(t=h->l;t->r->r;t=t->r);//make work for all
    swap(h->d,t->r->d);
    tmp=t->r;
    if(t->r->l)
     t->r=t->r->l;
    else
     t->r=NULL;
  }
  else
  {
    swap(h->d,h->l->d);
    tmp=h->l;
    h->l=h->l->l;
  }
  delete tmp;
  return 1;
 }
 else if(k<h->d) return deleteT(h->l,k);
 else return deleteT(h->r,k);
}
void pre_order_traversal(bst *h){ if(!h) return; cout<<h->d<<" "; pre_order_traversal(h->l); pre_order_traversal(h->r); }
void in_order_traversal(bst *h){ if(!h) return; in_order_traversal(h->l); cout<<h->d<<" "; in_order_traversal(h->r); }
void post_order_traversal(bst *h){ if(!h) return; post_order_traversal(h->l); post_order_traversal(h->r); cout<<h->d<<" "; }
void rec_level(bst *h,int i){ if(!i){ if(h) cout<<h->d<<" "; return; } rec_level(h->l,i-1); rec_level(h->r,i-1); }
void level_order_traversal(bst *h){ for(int i=0,ht=height(h); i<=ht; cout<<endl,i++) rec_level(h,i); }
void leaf(bst *h)
{
 if(!h) return;
 if(!(h->l||h->r)){ cout<<h->d<<" "; return; }
 leaf(h->l); leaf(h->r);
}
void nonleaf(bst *h)
{
 if(!(h && (h->l||h->r))) return;
 cout<<h->d<<" "; nonleaf(h->l); nonleaf(h->r);
}
int size(bst *h)
{
 if(!h) return 0;
 return 1+size(h->l)+size(h->r);
}
int no_nonleaf(bst *h)
{
 if(!(h && (h->l||h->r))) return 0;
 return 1+no_nonleaf(h->l)+no_nonleaf(h->r);
}
int no_leaf(bst *h)
{
 if(!(h && (h->l||h->r))) return h && !(h->l||h->r);
 return no_leaf(h->l)+no_leaf(h->r);
}
void mirror(bst *h){ if(!h) return; swap(h->l,h->r); mirror(h->l); mirror(h->r); }
void path(bst *h)
{
  if(!h) return;
  else if(!(h->l||h->r)){ q.display(); cout<<h->d<<endl; return; }
  q.push(h->d);
  path(h->l);
  path(h->r);
  q.pop();
}
void spath(bst *h,string a)
{
  if(!h) return;
  a+=char(h->d+'0');
  if(!(h->l||h->r)){ cout<<a<<endl; return; }
  spath(h->l,a);
  spath(h->r,a);
}
bool issum(bst *h,int sum)
{
 if(h) sum-=h->d;
 if(!(h&&(h->l||h->r))) return sum==0;
 if(h->l && h->r) return issum(h->l,sum)||issum(h->r,sum);
 else if(h->l) return issum(h->l,sum);
 else return issum(h->r,sum);
}
void rec(bst *h,int i,bool j)
{ 
 if(!i){ if(h) cout<<h->d<<" "; return; }
 if(j) rec(h->l,i-1,j),rec(h->r,i-1,j);
 else rec(h->r,i-1,j),rec(h->l,i-1,j);
}
void Zigzag(bst *h){ bool j=1; for(int i=0,ht=height(h);i<=ht;j=1-j,cout<<endl,i++) rec(h,i,j); }
bst *findAddress(bst *h,int k)
{
 if(!h || h->d==k) return h;
 bst *a=findAddress(h->l,k),*b=findAddress(h->r,k);
 if(a||b) return a?a:b; return NULL;
}
bst *leastAncestor(bst *h,bst *a,bst *b)
{
 if(!h || h==a || h==b) return h;
 bst *x=leastAncestor(h->l,a,b),*y=leastAncestor(h->r,a,b);
 if(x && y) return h;
 else return x?x:y;
}
bool allAncestor(bst *h,int k)
{if(h && (h->d==k || allAncestor(h->l,k) || allAncestor(h->r,k))){cout<<h->d<<" "; return 1;} return 0;}
int min(bst *h){ while(h->l) h=h->l; return h->d; }
int max(bst *h){ while(h->r) h=h->r; return h->d; }
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
  if(ch==1){ cout<<"\nEnter Data : "; cin>>k; insert(h,k); } // INSERTION
  if(ch==2){ cout<<"\nMinimum Height of Tree : "<<min_height(h)<<endl; } //MINIMUM HEIGHT OF TREE
  if(ch==3){ cout<<"\nHeight of Tree : "<<height(h)<<endl; } //HEIGHT OF TREE
  if(ch==4){ cout<<"\nMINIMUM DATA in Tree : "<<min(h)<<endl; } //MINIMUM OF TREE
  if(ch==5){ cout<<"\nMAXIMUM DATA in Tree : "<<max(h)<<endl; } //MAXIMUM OF TREE
  if(ch==6){ cout<<"\nMirror Image Done.\n"; mirror(h); } //Mirror Image
  if(ch==7)
  {
   cout<<"\nEnter data to delete : "; cin>>k;
   if(deleteT(h,k)) cout<<"\nData deleted.\n";
   else cout<<"\nData is not there in tree.\n";
  }
  if(ch==8)
  {
   cout<<"\nIn Order Traversal : "; pre_order_traversal(h);
   cout<<"\nIn Order Traversal : "; in_order_traversal(h);
   cout<<"\nIn Order Traversal : "; post_order_traversal(h);
   //cout<<"\nIn Order Traversal : "; level_order_traversal(h);
  } // RECURSIVE TRAVERSAL
  if(ch==9){ cout<<"\nNo. of Non-Leaf Nodes : "<<no_nonleaf(h)<<endl; } //NUMBER OF NON LEAF NODES IN TREE
  if(ch==10){ cout<<"\nNo. of Leaf Nodes : "<<no_leaf(h)<<endl; } //NUMBER OF LEAF NODES IN TREE
  if(ch==11){ cout<<"\nLEAF NODES : "; leaf(h); } //PRINT LEAF NODES
  if(ch==12){ cout<<"\nNON LEAF NODES : "; nonleaf(h); } //PRINT NON-LEAF NODES
  if(ch==13){ cout<<"\nPath :\n"; path(h); cout<<"\nAND spath :\n"; spath(h,""); } // PATH ROOT TO EACH NODE
  if(ch==14){ cout<<"\nSize Of Tree : "<<size(h)<<endl; } //SIZE OF TREE
  if(ch==15){ cout<<"\nEnter Sum : "; cin>>k; cout<<issum(h,k)<<endl; } //SUM IS THERE OR NOT
  if(ch==16){ cout<<"\nZigzag : "; Zigzag(h); } //ZIGZAG PRINTING OF NODES
  if(ch==17){ cout<<"\nEnter Data Whose All Ancestors : "; cin>>k; allAncestor(h,k); } //ALL ANCESTORS OF A NODE
  if(ch==18)
  {
   cout<<"\nLeast Ancestor : "; bst *a,*b,*c;
   cout<<"\nEnter First Data : "; cin>>k; a=findAddress(h,k);
   cout<<"\nEnter First Data : "; cin>>k; b=findAddress(h,k);
   c=leastAncestor(h,a,b);
   if(c) cout<<"\nAncestor : "<<c->d<<endl;
   else cout<<"\nThere is no Ancestor.\n";
  } //ROOT HAVING BOTH GIVEN NODES
  if(ch==19){ cout<<"\nPre Order Precedessor : "<<prep(h)<<endl; }
  if(ch==20){ cout<<"\nIn Order Precedessor : "<<inp(h)<<endl; }
  if(ch==21){ cout<<"\nPost Order Precedessor : "<<postp(h)<<endl; }
  if(ch==22){ cout<<"\nPre Order Successor : "<<pres(h)<<endl; }
  if(ch==23){ cout<<"\nIn Order Successor : "<<ins(h)<<endl; }
  if(ch==24){ cout<<"\nPost Order Successor : "<<posts(h)<<endl; }
  if(ch==25){ cout<<checkcomplete(h)<<endl; }
 }
}
//1 45 1 23 1 55 1 21 1 33 1 49 1 62 1 5 1 22 1 32 1 34 1 48 1 50 1 61 1 63 0
//1 45 1 25 1 55 1 15 1 35 1 36 1 5 18 35 36
/*class Queue
{
 private:
 struct qu
 {
  int data;
  qu *next;
 }*head;
 public:
 Queue(){ head=NULL; }
 bool isEmpty(){ return head==NULL; }
 void enqueue(int d)
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
 int lastElement()
 {
  if(head) return head->data;
  return INT_MAX;
 }
 int dequeue()
 {
  int k=lastElement();
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
};*/
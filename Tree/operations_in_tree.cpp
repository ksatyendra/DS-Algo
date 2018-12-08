#include<iostream>
#include<conio.h>
using namespace std;
int f=0,r=-1,top=-1;
class Tree
{
 public:
  int data;
  Tree *Lchild;
  Tree *Rchild;
  Tree(int k,Tree *l,Tree *r)
  {
   data=k;
   Lchild=l;
   Rchild=r;
  }
}**Q,**stk;
bool isEmptys()
{
 return top==-1;
}
void push(Tree *d)
{
 stk[++top]=d;
}
Tree *pop()
{
 return stk[top--];
}
Tree *top_element()
{
 return stk[top];
}
bool isEmptyq()
{
 return r<f;
}
void enq(Tree *h)
{
 Q[++r]=h;
}
Tree *deq()
{
 return Q[f++];
}
int height(Tree *h)
{
 if(!h) return -1;
 int a=height(h->Lchild),b=height(h->Rchild);
 if(a>b)
  return a+1;
 else
  return b+1;
}
int size(Tree *h)
{
 if(!h) return 0;
 return 1+size(h->Lchild)+size(h->Rchild);
}
int no_leaf(Tree *h)
{
 if(!h) return 0;
 if(h->Lchild||h->Rchild)
  return no_leaf(h->Lchild)+no_leaf(h->Rchild);
 return 1;
}
int no_non_leaf(Tree *h)
{
 if(!h) return 0;
 if(h->Lchild||h->Rchild)
  return 1+no_non_leaf(h->Lchild)+no_non_leaf(h->Rchild);
 return 0;
}
void leaf(Tree *h)
{
 if(!h) return;
 if(h->Lchild||h->Rchild)
 {
  leaf(h->Lchild);
  leaf(h->Rchild);
 }
 else cout<<h->data<<" ";
}
void path(Tree *h,int i,int *a)
{
 if(!h) return;
 if(h->Lchild||h->Rchild)
 {
  a[i]=h->data;
  path(h->Lchild,i+1,a);
  path(h->Rchild,i+1,a);
 }
 else
 {
  for(int j=0;j<i;)
   cout<<a[j++]<<" ";
  cout<<h->data<<endl;
 }
}
void non_leaf(Tree *h)
{
 if(!h) return;
 if(h->Lchild||h->Rchild)
 { 
  cout<<h->data<<" ";
  non_leaf(h->Lchild);
  non_leaf(h->Rchild);
 }
}
void pre_order_traversal(Tree *h)
{
 push(h);
 while(!isEmptys())
 {
  h=pop();
  cout<<h->data<<" ";
  if(h->Rchild)
   push(h->Rchild);
  if(h->Lchild)
   push(h->Lchild);
 }
}
void in_order_traversal(Tree *h)
{
 while(1)
 {
  if(h)
  {
   push(h);
   h=h->Lchild;
  }
  else if(!isEmptys())
  {
   h=pop();
   cout<<h->data<<" ";
   h=h->Rchild;
  }
  else break;
 }
}
void post_order_traversal(Tree *h)
{
 Tree *k=NULL;
 push(h);
 while(!isEmptys())
 {
  h=top_element();
  if(!k || k->Lchild==h || k->Rchild==h)
  {
   if(h->Lchild)
    push(h->Lchild);
   else if(h->Rchild)
    push(h->Rchild);
  }
  else if(h->Lchild==k)
  {
   if(h->Rchild)
    push(h->Rchild);
  }
  else
   cout<<pop()->data<<" ";
  k=h;
 }
}
void level_order_traversal(Tree *h)
{
 enq(h);
 while(!isEmptyq())
 {
  h=deq();
  cout<<h->data<<" ";
  if(h->Lchild)
   enq(h->Lchild);
  if(h->Rchild)
   enq(h->Rchild);
 }
}
void insert(Tree *h)
{
 int k;
 cout<<"\nEnter data : ";
 cin>>k;
 Tree *z=new Tree(k,NULL,NULL);
 enq(h);
 for(;;h=deq())
 {
  if(h->Lchild)
   enq(h->Lchild);
  else
  {
   h->Lchild=z;
   break;
  }
  if(h->Rchild)
   enq(h->Rchild);
  else
  {
   h->Rchild=z;
   break;
  }
 }
 f=0,r=-1;
}
int main()
{
 Q=new Tree*[50];
 stk=new Tree*[50];
 int *a=new int[25];
 int ch=1,k;
 cout<<"\nEnter Root Data : ";
 cin>>k;
 Tree *root=new Tree(k,NULL,NULL);
 while(ch)
 {
  cout<<"\nEnter choice 1 to insert, 2 to find height, 3 to find size of tree, 4 to find no. of leaf nodes, 5 to find no. of non-leaf nodes, 6 to path from root to each leaf nodes, 7 to print leaf nodes, 8 to print non-leaf nodes & 10 to level order traversal :\n";
  cin>>ch;
  if(!ch) break;
  if(ch==1) insert(root);
  if(ch==2) cout<<"\nHeight is  : "<<height(root)<<endl;
  if(ch==3) cout<<"\nSize is  : "<<size(root)<<endl;
  if(ch==4) cout<<"\nNo. of Leaf nodes is  : "<<no_leaf(root)<<endl;
  if(ch==5) cout<<"\nNo. of Non-Leaf nodes is  : "<<no_non_leaf(root)<<endl;
  if(ch==6) { cout<<"\nPath from root to leaf  :\n"; path(root,0,a); }
  if(ch==7) { cout<<"\nLeaf Nodes : "; leaf(root); }
  if(ch==8) { cout<<"\nNon-Leaf nodes : "; non_leaf(root); }
  if(ch==10) level_order_traversal(root);
 }
 return 0;
}

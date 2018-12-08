#include<iostream>
#include<conio.h>
using namespace std;
int f=0,r=-1;
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
}**Q;
bool isEmpty()
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
void pre_order_traversal(Tree *h)
{
 if(!h) return;
 cout<<h->data<<" ";
 pre_order_traversal(h->Lchild);
 pre_order_traversal(h->Rchild);
}
void in_order_traversal(Tree *h)
{
 if(!h) return;
 in_order_traversal(h->Lchild);
 cout<<h->data<<" ";
 in_order_traversal(h->Rchild);
}
void post_order_traversal(Tree *h)
{
 if(!h) return;
 post_order_traversal(h->Lchild);
 post_order_traversal(h->Rchild);
 cout<<h->data<<" ";
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
void show_level_nodes(Tree *h,int i)
{
 if(!h) return;
 if(!i)
 {
  cout<<h->data<<" ";
  return;
 }
 show_level_nodes(h->Lchild,i-1);
 show_level_nodes(h->Rchild,i-1);
}
void level_order_traversal(Tree *h)
{
 int ht=height(h),i;
 for(i=0;i<=ht;i++)
 { 
  show_level_nodes(h,i);
  cout<<endl;
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
 int ch=1,k;
 cout<<"\nEnter Root Data : ";
 cin>>k;
 Tree *root=new Tree(k,NULL,NULL);
 while(ch)
 {
  cout<<"\nEnter choice 1 to insert, 2 to pre, 3 to in, 4 to post & 5 to level :\n";
  cin>>ch;
  if(!ch) break;
  if(ch==1) insert(root);
  if(ch==2) pre_order_traversal(root);
  if(ch==3) in_order_traversal(root);
  if(ch==4) post_order_traversal(root);
  if(ch==5) level_order_traversal(root);
 }
 return 0;
}

#include<iostream>
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
}
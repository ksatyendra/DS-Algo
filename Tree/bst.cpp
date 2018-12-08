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
void ins(Tree *h,Tree *d)
{
 if(d->data<h->data)
 {
  if(h->Lchild)
   ins(h->Lchild,d);
  else
   h->Lchild=d;
 }
 else
 {
  if(h->Rchild)
   ins(h->Rchild,d);
  else
   h->Rchild=d;
 }
}
void insert(Tree *h)
{
 int k;
 cout<<"\nEnter data : ";
 cin>>k;
 Tree *z=new Tree(k,NULL,NULL);
 ins(h,z);
}
void create(Tree *h)
{
 int n,i;
 cout<<"\nEnter no. of nodes : ";
 cin>>n;
 for(i=0;i<n;i++)
  insert(h);
}
bool srh(Tree *h,int n)
{
 if(!h) return 0;
 if(n==h->data)
  return 1;
 if(h->data>n)
  return srh(h->Lchild,n);
 else
  return srh(h->Rchild,n);
}
void search(Tree *h)
{
 int n;
 cout<<"\nEnter no. to search : ";
 cin>>n;
 if(srh(h,n)) cout<<"\nYES,It is there.\n";
 else cout<<"\nNO,It is not there.\n";
}
void remove(Tree* &h)
{
 if(!h->Lchild)
  h=h->Rchild;
 else if(!h->Rchild)
  h=h->Lchild;
 else
 {
  Tree *j,*k=h->Lchild;
  if(!(k->Lchild||k->Rchild))
   h->Lchild=NULL;
  else if(k->Lchild)
   h->Lchild=k->Lchild;
  else
  {
   for(j=k,k=k->Rchild;k->Rchild;j=j->Rchild,k->Rchild);
   j->Rchild=NULL;
  }
  h->data=k->data;
  delete k;
 }  
}
bool del(Tree *h,int n)
{
 if(n<h->data)
 {
  if(h->Lchild->data==n)
   remove(h->Lchild);
  else
   del(h->Lchild,n);
 }
 else
 {
  if(h->Rchild->data==n)
   remove(h->Rchild);
  else
   del(h->Rchild,n);
 }
}
void delt(Tree *h)
{
 int n;
 cout<<"\nEnter data to delete : "; cin>>n;
 if(h->data==n){ remove(h); cout<<"\ndeleted."; }
 else if(del(h,n)) cout<<"\ndeleted.";
 else cout<<"\nis not there.";
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
  cout<<"\nEnter choice :\n1 to create\n2 to find insert\n3 to search\n4 to delete\n10 to level order traversal :\n";
  cin>>ch;
  if(!ch) break;
  if(ch==1) create(root);
  if(ch==2) insert(root);
  if(ch==3) search(root);
  if(ch==4) delt(root); 
  if(ch==10) level_order_traversal(root);
 }
 return 0;
}

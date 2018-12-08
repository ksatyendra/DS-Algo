#include<iostream>
#include<conio.h>
using namespace std;
int f=0,r=-1;
class BT
{
 public:
  int data;
  BT *Lchild;
  BT *Rchild;
  BT(int k,BT *l,BT *r)
  {
   data=k;
   Lchild=l;
   Rchild=r;
  }
};
class LL
{
 public:
  int data;
  LL *next;
  LL(int k,LL *n)
  {
   data=k;
   next=n;
  }
  LL() { };
};
void pre_order_traversal(BT *h)
{
 if(!h) return;
 cout<<h->data<<" ";
 pre_order_traversal(h->Lchild);
 pre_order_traversal(h->Rchild);
}
void in_order_traversal(BT *h)
{
 if(!h) return;
 in_order_traversal(h->Lchild);
 cout<<h->data<<" ";
 in_order_traversal(h->Rchild);
}
void post_order_traversal(BT *h)
{
 if(!h) return;
 post_order_traversal(h->Lchild);
 post_order_traversal(h->Rchild);
 cout<<h->data<<" ";
}
BT *pre_in(LL* &pre,LL *in)
{
 if(!(pre && in)) return NULL;
 LL *c,*k=in; int x=pre->data; pre=pre->next;
 while(k->next->data!=x) k=k->next;
 c=k->next->next; k->next=NULL;
 BT *t=new BT(x,pre_in(pre,in),pre_in(pre,c));
 return t;
}
int main()
{
 int n,i;
 LL *pre,*in,*t;
 cout<<"\nEnter no. of nods : ";
 cin>>n;
 cout<<"\nEnter PRE-ORDER : ";
 pre=new LL();
 cin>>pre->data;
 for(i=0,t=pre;i<n-1;i++)
 {
  t->next=new LL();
  t=t->next;
  cin>>t->data;
 }
 cout<<"\nEnter IN-ORDER : ";
 in=new LL();
 cin>>in->data;
 for(i=0,t=in;i<n-1;i++)
 {
  t->next=new LL();
  t=t->next;
  cin>>t->data;
 }getch();
 BT *root=pre_in(pre,in);
 cout<<"pre_order_traversal : ";
 pre_order_traversal(root);
 cout<<"in_order_traversal : ";
 in_order_traversal(root);
 cout<<"post_order_traversal : ";
 post_order_traversal(root);
 getch();
 return 0;
}

#include<iostream>
using namespace std;
class BT
{
 public:
 int data;
 BT *LC,*RC;
 BT()
 {
 }
 BT(int d,BT *l,BT *r)
 {
  data=d;
  LC=l;
  RC=r;
 }
};
void insert(BT *h,int k)
{
 if(k<h->data)
 {
  if(h->LC)
   insert(h->LC,k);
  else
   h->LC=new BT(k,NULL,NULL);
 }
 else
 {
  if(h->RC)
   insert(h->RC,k);
  else
   h->RC=new BT(k,NULL,NULL);
 }
}
void create(BT* &h)
{
 bool ch=1;
 int k;
 cout<<"\nEnter root data : ";
 cin>>k;
 h=new BT(k,NULL,NULL); 
 while(ch)
 {
  cout<<"\nEnter 1 to continue & 0 to stop : ";
  cin>>ch;
  if(!ch)
   break;
  cout<<"\nEnter data : ";
  cin>>k;
  insert(h,k);
 }
}
void rec_pre_order(BT *h)
{
 if(!h)
  return;
 cout<<h->data;
 rec_pre_order(h->LC);
 rec_pre_order(h->RC);
}
int main()
{
 BT *rt=NULL;
 int k,ch=1;
 while(ch)
 {
  cout<<"\nEnter choice :\n1 to create\n2 to insert\n3 for Pre Order Traversal\n4 for in Order Traversal\n5 for Post Order Traversal\n0 to terminate : ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : create(rt); break;
   case 2 : cout<<"\nEnter Data : ";
            cin>>k; insert(rt,k); break;
   case 3 : rec_pre_order(rt); break;
   case 4 : rec_pre_order(rt); break;
   case 5 : rec_pre_order(rt); break;
   default : cout<<"\nWrong Choce.\n";
  }
 }
}

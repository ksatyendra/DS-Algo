#include<iostream>
using namespace std;
class ET
{
 public:
  ET *l; char d; ET *r;
  ET(char x){ d=x; l=NULL; r=NULL; }
  ET(char x,ET *rr,ET *ll){ d=x; l=ll; r=rr; }
};
class Stack
{
 private:
 struct stk
 {
  ET *data;
  stk *next;
 }*head;
 public:
 Stack(){ head=NULL; }
 bool isEmpty(){ return head==NULL; }
 void push(ET *d)
 {
  stk *t=new stk;
  t->data=d;
  t->next=head;
  head=t;
 }
 ET* topElement()
 {
  if(head) return head->data;
  else NULL;
 }
 ET* pop()
 {
  ET *k=topElement();
  stk *t=head;
  head=head->next;
  delete t;
  return k;
 }
 void display()
 {
  for(stk *t=head;t;t=t->next)
   cout<<t->data<<" ";
  cout<<endl;
 }
};
void pre_order_traversal(ET *h)
{
 if(!h)
  return;
 cout<<h->d<<" ";
 pre_order_traversal(h->l);
 pre_order_traversal(h->r);
}
void in_order_traversal(ET *h)
{
 if(!h)
  return;
 in_order_traversal(h->l);
 cout<<h->d<<" ";
 in_order_traversal(h->r);
}
void post_order_traversal(ET *h)
{
 if(!h)
  return;
 post_order_traversal(h->l);
 post_order_traversal(h->r);
 cout<<h->d<<" ";
}
int main()
{
 Stack a;
 char s[50];
 int i;
 ET *t;
 cout<<"\nEnter postfix Expresssion : ";
 cin>>s;
 for(i=0;s[i]!='\0';i++)
 {
  if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'||s[i]=='%')
   t=new ET(s[i],a.pop(),a.pop());
  else
   t=new ET(s[i]);
  a.push(t);
 }
 t=a.pop();
 cout<<"\nPre order : ";
 pre_order_traversal(t);
 cout<<"\nIn order : ";
 in_order_traversal(t);
 cout<<"\nPost order : ";
 post_order_traversal(t);
}
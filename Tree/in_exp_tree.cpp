#include<iostream>
using namespace std;
struct BT
{
 public:
  BT *left,*right;
  char data;
};
class Stack
{
 private:
 struct stk
 {
  BT* d;
  stk *next;
 }*head;
 public:
 Stack(){ head=NULL; }
 bool isempty(){ return head==NULL; }
 void push(BT* dd)
 {
  stk *t=new stk;
  t->d=dd;
  t->next=head;
  head=t; 
 }
 char topElem()
 {
  if(head) return head->d->data;
  else return '\0';
 }
 BT* pop()
 {
  stk *t=head;
  head=head->next;
  return t->d;
 }
};
BT* create_new_node(BT* rr,BT* ll,char d)
{
 BT* tmp=new BT;
 tmp->data=d;
 tmp->right=rr;
 tmp->left=ll;
 return tmp;
}
void in_to_expn_tree(char a[],BT* &root)
{
  Stack rator_stack,rand_stack;
  for (int i = 0; a[i]!='\0'; i++)
  {
    if(a[i]>='a' && a[i]<='z')
      rand_stack.push(create_new_node(NULL,NULL,a[i]));
    else
    {
      switch(a[i])
      {
        case '(': rator_stack.push(create_new_node(NULL,NULL,a[i])); break;
        case '/': 
         while(rator_stack.topElem()=='/')
         {
           BT *tmp=rator_stack.pop();
           tmp->right=rand_stack.pop();
           tmp->left=rand_stack.pop();
           rand_stack.push(tmp);
         }
         break;
        case '*': 
         while(rator_stack.topElem()=='/' || rator_stack.topElem()=='*')
         {
           BT *tmp=rator_stack.pop();
           tmp->right=rand_stack.pop();
           tmp->left=rand_stack.pop();
           rand_stack.push(tmp);
         }
         break;
        case '+':
        case '-':
         while(rator_stack.topElem()=='/' || rator_stack.topElem()=='*' || rator_stack.topElem()=='+' || rator_stack.topElem()=='-')
         {
           BT *tmp=rator_stack.pop();
           tmp->right=rand_stack.pop();
           tmp->left=rand_stack.pop();
           rand_stack.push(tmp);
         }
         break;
        case ')':
         while(rator_stack.topElem()!=')')
         {
          BT *tmp=rator_stack.pop();cout<<"*";
          tmp->right=rand_stack.pop();
          tmp->left=rand_stack.pop();
          rand_stack.push(tmp);
         }
         rator_stack.pop();
         break;
      }
      rator_stack.push(create_new_node(NULL,NULL,a[i]));
    }
  }
  while(!rator_stack.isempty())
  {
   BT *tmp=rator_stack.pop();
   tmp->right=rand_stack.pop();
   tmp->left=rand_stack.pop();
   rand_stack.push(tmp);
  }
  root=rand_stack.pop();
}
void pre_order_traversal(BT *h)
{
 if(!h)
  return;
 cout<<h->data<<" ";
 pre_order_traversal(h->left);
 pre_order_traversal(h->right);
}
void in_order_traversal(BT *h)
{
 if(!h)
  return;
 in_order_traversal(h->left);
 cout<<h->data<<" ";
 in_order_traversal(h->right);
}
void post_order_traversal(BT *h)
{
 if(!h)
  return;
 post_order_traversal(h->left);
 post_order_traversal(h->right);
 cout<<h->data<<" ";
}
int height(BT *h)
{
 if(!h) return -1;
 int a=height(h->left),b=height(h->right);
 if(a>b)
  return a+1;
 else
  return b+1;
}
void show_level_nodes(BT *h,int i)
{
 if(!h) return;
 if(!i)
 {
  cout<<h->data<<" ";
  return;
 }
 show_level_nodes(h->left,i-1);
 show_level_nodes(h->right,i-1);
}
void level_order_traversal(BT *h)
{
 int ht=height(h),i;
 for(i=0;i<=ht;i++)
 { 
  show_level_nodes(h,i);
  cout<<endl;
 }
}
int main()
{
 char s[50]="a*c+b";
 BT *root=new BT;
 in_to_expn_tree(s,root);
 cout<<"\nPre order : ";
 pre_order_traversal(root);
 cout<<"\nIn order : ";
 in_order_traversal(root);
 cout<<"\nPost order : ";
 post_order_traversal(root);
 cout<<"\nLevel Order : \n";
 level_order_traversal(root);
}
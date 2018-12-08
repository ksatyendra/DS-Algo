#include<iostream>
#include<conio.h>
using namespace std;
struct lst
{
 int coef;
 int exp;
 lst *next;
};
bool isempty(lst *l)
{
 return l==NULL;
}
void show(lst *l)
{
  lst *t=l;
  if((t->coef!=1) && t->coef)
    cout<<t->coef<<"x^"<<t->exp;
   else if(t->coef)
    cout<<"x^"<<t->exp;
  while(t->next)
  {
   t=t->next;
   if(t->exp==0)
    cout<<" + "<<t->coef;
   else if(t->exp==1)
    cout<<" + "<<t->coef<<"x";
   else if((t->coef!=1) && t->coef)
    cout<<" + "<<t->coef<<"x^"<<t->exp;
   else if(t->coef)
    cout<<" + "<<"x^"<<t->exp;
  }
  cout<<endl;
}
void insert(lst* &l)
{
 lst *t,*a=new lst;
 cin>>a->coef;
 cin>>a->exp;
 a->next=NULL;
 if(l==NULL)
 {
  l=a;
  return;
 }
 for(t=l;t->next;t=t->next);
 t->next=a;
}
void add(lst *i,lst *j,lst* &a)
{
 lst *k;
 a=new lst;
 for(k=a;i&&j;k->next=new lst,k=k->next)
  if(i->exp==j->exp)
  {
   k->exp=i->exp;
   k->coef=i->coef+j->coef;
   i=i->next;
   j=j->next;
  }
  else if(i->exp>j->exp)
  {
   k->exp=i->exp;
   k->coef=i->coef;
   i=i->next;
  }
  else
  {
   k->exp=j->exp;
   k->coef=j->coef;
   j=j->next;
  }
 for(;i;k->next=new lst,k=k->next)
 {
  k->exp=i->exp;
  k->coef=i->coef;
  i=i->next;
 }
 for(;j;k->next=new lst,k=k->next)
 {
  k->exp=j->exp;
  k->coef=j->coef;
  j=j->next;
 }
 k->coef=0;
 k->exp=0;
 k->next=NULL;
}
void sort_del_duplicate(lst* &h)
{
 lst *a,*b,*c;
 for(a=h;a->next;a=a->next)
  for(b=h,c=a;c->next;c=c->next,b=b->next)
   if(b->next->exp>b->exp)
   { 
    swap(b->next->coef,b->coef);
    swap(b->next->exp,b->exp);
   }
   else if(b->next->exp==b->exp)
   {
    b->coef+=b->next->coef;
    b->next=b->next->next;
   }
}
void mul(lst *c,lst *b,lst* &a)
{
 a=new lst;
 lst *i,*j,*t=a;
 for(i=c;i;i=i->next)
  for(j=b;j;j=j->next)
  {
   t->next=new lst;
   t=t->next;
   t->coef=i->coef*j->coef;
   t->exp=i->exp+j->exp;
  }
  t->next=NULL;
  a=a->next;
  sort_del_duplicate(a);
}
int main()
{
 int ch,n;
 lst *head1,*head2,*head;
 head1=head2=head=NULL;
 while(ch)
 {
  cout<<"Enter option :\n1 to edit Ist polynomial.\n2 to edit IInd polynomial.\n3 to do addition of polynomial.";
  cout<<"\n4 to do multiplication of polynomial.\n5 to reset Ist polynomial.\n6 to reset IInd polynomial.   :   ";
  cin>>ch;
  if(!ch)
   break;
  switch(ch)
  {
   case 1 : cout<<"\nEnter coefficient and power of Ist polynomials in decreasing order :\n=>";
            insert(head1); 
            cout<<"\nNow Ist Polynomial : ";
            show(head1); break;
   case 2 : cout<<"\nEnter coefficient and power of Ist polynomials in decreasing order :\n=>";
            insert(head2);
            cout<<"\nNow Ist Polynomial : ";
            show(head2); break;
   case 3 : add(head1,head2,head);
            cout<<"\nNow Ist Polynomial : ";
            show(head1);
            cout<<"\nNow IInd Polynomial : ";
            show(head2);
            cout<<"\n\nAnswer is : ";
            show(head); break;
   case 4:  mul(head1,head2,head);
            cout<<"\nNow Ist Polynomial : ";
            show(head1);
            cout<<"\nNow IInd Polynomial : ";
            show(head2);
            cout<<"\nAnswer is : ";
            show(head);
            cout<<endl; break;
   case 5 : head1=NULL; break;
   case 6 : head2=NULL; break;
   default : cout<<"\n\nWRONG CHOICE.\n\n";
  }
 }
 return 0;
}

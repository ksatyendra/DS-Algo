#include<iostream>
using namespace std;
struct lst
{
    int d;
    lst *lk;
}*hd;
void ins(lst* &l)
{
 if(l==NULL)
 {
  l=new lst;
  l->lk=NULL;
  cin>>l->d;
 }
 else
 {
  lst *p;
  for(p=l;p->lk;p=p->lk);
  p->lk=new lst;
  p=p->lk;
  cin>>p->d;
  p->lk=NULL;
 }
}
void disp(lst *l)
{
  for(lst *p=l;p;p=p->lk)
   cout<<p->d<<" ";
  cout<<endl;
}
lst* merge(lst* &l1,lst* &l2)
{
 if(!l1)
  return l2;
 if(!l2)
  return l1;
 lst *t,*l3;
 l3=l1;
 t=l3;
 l1=l1->lk;
 while(l1&&l2)
 {
  t->lk=l2;
  l2=l2->lk;
  t=t->lk;
  t->lk=l1;
  l1=l1->lk;
  t=t->lk;
 }
 t->lk=NULL;
 if(l1)
  t->lk=l1;
 if(l2)
  t->lk=l2;
 l1=l2=NULL;
 return l3;
}
int main()
{
 lst *l1,*l2,*l3;
 int ch;
 l1=l2=l3=NULL;
 while(1)
 {
  cin>>ch;
  if(!ch) break;
  switch(ch)
  { 
   case 1:ins(l1); break;
   case 2:ins(l2); break;
   case 3:cout<<"lk 1 is :\n";
          disp(l1); break;
   case 4:cout<<"lk 2 is :\n";
          disp(l2); break;
   case 5:l3=merge(l1,l2); 
          cout<<"res is :\n";
          disp(l3);
  }
 }
}
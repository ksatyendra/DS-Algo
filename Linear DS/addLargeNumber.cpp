#include<iostream>
using namespace std;
class lst
{
 public: char d; lst *lk;
 lst(char a,lst *b) { d=a; lk=b; }
};
void ins(lst* &l,char k)
{
 if(l)
 {
  lst *t=new lst(k,l);
  l=t;
 }
 else
  l=new lst(k,NULL);
}
lst *sum(lst *l,lst *o)
{
 int k;
 lst *t,*z=new lst('0',NULL);
 for(t=z;l&&o;t=t->lk,l=l->lk,o=o->lk)
 {
  k=l->d+o->d-96;
  t->d+=(k%10);
  t->lk=new lst(k/10+48,NULL);
 }
 for(;l;l=l->lk,t=t->lk)
 {
  t->d+=(l->d-48);
  t->lk=new lst('0',NULL);
 }
 for(;o;o=o->lk,t=t->lk)
 {
  t->d+=(o->d-48);
  t->lk=new lst('0',NULL);
 }
 return z;
}
void take(lst *p,char *c,int &i)
{
 for(i=0;p;p=p->lk)
  c[i++]=p->d;
}
int main()
{
 char c[100]; int n;
 lst* l[3]={NULL},*p;
 for(int j=0;j<2;j++)
 {
  cout<<"enter no. : ";
  cin>>c;
  for(int i=0;c[i]!='\0';i++)
   ins(l[j],c[i]);
 }
 l[2]=sum(l[0],l[1]);
 take(l[2],c,n);
 cout<<"answer is : ";
 for(n--;n;cout<<c[--n]);
}
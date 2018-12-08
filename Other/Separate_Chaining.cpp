#include<iostream>
using namespace std;
#define table_size 17
struct LinkedList
{
 int data;
 LinkedList *next;
};
void hash(LinkedList **a,int k)
{
 int i=k%table_size;
 LinkedList *tmp=new LinkedList;
 tmp->data=k;
 tmp->next=a[i];
 a[i]=tmp;
}
bool del_hash(LinkedList **a,int k)
{
 int i=k%table_size;
 if(!a[i]) return 0;
 if(a[i]->data==k)
 {
  a[i]=a[i]->next;
  return 1;
 }
 LinkedList *tmp=a[i];
 while(tmp->next && tmp->next->data!=k) tmp=tmp->next;
 if(tmp->next)
 { 
  tmp->next=tmp->next->next;
  return 1;
 }
 return 0;
}
bool search(LinkedList **a,int k)
{
 int i=k%table_size;
 LinkedList *tmp=a[i];
 while(tmp && tmp->data!=k) tmp=tmp->next;
 return tmp!=NULL;
}
void display(LinkedList **a)
{
 LinkedList *tmp;
 int i;
 for(i=0;i<table_size;i++)
 {
  cout<<"Key = "<<i<<" : ";
  for(tmp=a[i];tmp;tmp=tmp->next)
   cout<<" -> "<<tmp->data;
  cout<<endl;
 }
}
int main()
{
 int ch=1,k;
 LinkedList *h[table_size]={NULL};
 while(ch)
 {
  cout<<"\nEnter choice [1 to hash, 2 to search, 3 to delete hash & 4 to diaplay] : ";
  cin>>ch;
  if(!ch) break;
  if(ch==1)
  {
   cout<<"\nEnter data to hash : ";
   cin>>k;
   hash(h,k);
   cout<<"\nDone.\n";
  }
  if(ch==2)
  {
   cout<<"\nEnter data to search : ";
   cin>>k;
   if(search(h,k))
    cout<<"\nData is there.\n";
   else
    cout<<"\nNot possible in this table size.\n";
  }
  if(ch==3)
  {
   cout<<"\nEnter data to delete : ";
   cin>>k;
   if(del_hash(h,k))
    cout<<"\nDone.\n";
   else\
    cout<<"\nIs not there in this table.\n";
  }
  if(ch==4)
   display(h);
 }
}
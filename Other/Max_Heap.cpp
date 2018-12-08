#include<iostream>
using namespace std;
#define hsize 20
int *a,it;
void heapify()
{
 int i,k;
 for(i=it/2;i>=0;i--)
 {
  k=2*i+1;
  if(k<=it && a[k]>a[i])
   swap(a[i],a[k]);
  k++;
  if(k<=it && a[k]>a[i])
   swap(a[i],a[k]); 
 }
}
void insert(int k)
{
 a[++it]=k;
 heapify();
}
int hdelete()
{
 if(it<0)
  return INT_MIN;
 int x=a[0];
 swap(a[0],a[it--]);
 heapify();
 return x;
}
void hsort()
{
 for(int i=it;i>=0;i--)
  cout<<hdelete()<<"\t";
 cout<<endl;
}
void display()
{
 for(int i=0;i<=it;i++)
  cout<<a[i]<<"\t";
 cout<<endl;
}
int main()
{
 int ch=1,k;
 a=new int[hsize];
 it=-1;
 while(ch)
 {
  cout<<"\nEnter choice [1 to insert, 2 to delete, 3 to perform heap sort & 4 to display] : ";
  cin>>ch;
  if(!ch) break;
  if(ch==1)
  {
   cout<<"\nEnter data to insert : ";
   cin>>k;
   insert(k);
  }
  if(ch==2)
  {
   k=hdelete();
   if(k!=INT_MIN)
    cout<<"\nDeleted data is : "<<k<<endl;
   else
    cout<<"\nEmpty!!!\n";
  }
  if(ch==3)
   hsort();
  if(ch==4)
   display();
 }
}
#include<iostream>
using namespace std;
#define table_size 17
bool hash(int a[],int k)
{
 int i,j,index;
 i=index=k%table_size;
 if(a[i]==-1)
 {
  a[i]=k;
  return 1;
 }
 i++;
 for(j=2;a[i]!=-1 && i%table_size!=index;j++) i=index+j*j;
 if(i%table_size==index) return 0;
 a[i%table_size]=k;
 return 1;
}
int search(int a[],int k)
{
 int i,j,index;
 i=index=k%table_size;
 if(a[i]==k)
  return i;
 i++;
 for(j=2;a[i]!=k && i%table_size!=index;j++) i=index+j*j;
 if(i%table_size==index) return -1;
 return i%table_size;
}
bool del_hash(int a[],int k)
{
 int i=search(a,k);
 if(i!=-1)
  a[i]=-1;
 return i!=-1;
}
void display(int a[])
{
 cout<<"\nKey\t:\tData:\n";
 for(int i=0;i<table_size;i++)
  cout<<i<<"\t:\t"<<a[i]<<endl;
}
int main()
{
 int ch,k,*h;
 h=new int[table_size];
 for(ch=0;ch<table_size;ch++)
  h[ch]=-1;
 while(ch)
 {
  cout<<"\nEnter choice [1 to hash, 2 to search, 3 to delete hash & 4 to diaplay] : ";
  cin>>ch;
  if(!ch) break;
  if(ch==1)
  {
   cout<<"\nEnter data to hash : ";
   cin>>k;
   if(hash(h,k))
    cout<<"\nDone.\n";
   else\
    cout<<"\nNot possible in this table size.\n";
  }
  if(ch==2)
  {
   cout<<"\nEnter data to search : ";
   cin>>k;
   k=search(h,k);
   if(k!=-1)
    cout<<"\nData is at key : "<<k<<endl;
   else
    cout<<"\nIs not there in this table.\n";
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

#include<iostream>
using namespace std;
#define table_size 17
bool hash(int a[],int k)
{
 int i,index;
 i=index=k%table_size;
 while(a[i]!=-1 && i<index+table_size) i++;
 if(i==table_size+index) return 0;
 a[i%table_size]=k;
 return 1;
}
bool del_hash(int a[],int k)
{
 int i,index;
 i=index=k%table_size;
 while(a[i]!=k && i<index+table_size) i++;
 if(i==index+table_size) return 0;
 a[i%table_size]=0;
 return 1;
}
int search(int a[],int k)
{
 int i,index;
 i=index=k%table_size;
 while(a[i]!=k && i<index+table_size) i++;
 if(i==index+table_size) return -1;
 return i%table_size;
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
#include<iostream>
using namespace std;
int *a,n=10,f,r;
bool isempty()
{
 return r<=f;
}
bool isfull()
{
 return r==f+n-1;
}
void show()
{
  for(int i=f;i<=r;i++)
   cout<<a[i%n]<<" ";
  cout<<endl;
}
void ins(int k)
{
    a[(++r)%n]=k;
}
int del()
{
    return a[(f++)%n];
}
int main()
{
  int i,k=1,x;
  r=-1;f=0;
  a=new int[n];
  while(k)
  {
   cin>>k;
   switch(k)
   {
     case 1 :
         if(!isfull())
         { cin>>x; ins(x); }
         else
           cout<<"\nStack is full.";
         break;
     case 2 :
         if(!isempty())
          cout<<"********"<<del();
         else
          cout<<"\nStack is empty.";
         break;
     case 3 :
         if(!isempty())
          show();
         else
          cout<<"\nStack is empty.";
         break;
   }
  }
}

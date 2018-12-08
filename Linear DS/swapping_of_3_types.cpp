#include<iostream>
#include<conio.h>
using namespace std;
void swap1(int &a,int &b)
{
 int t=a;
 a=b;
 b=t;
}
void swap2(int *a,int *b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}
int main()
{
 int A,B,tmp,choice=0;
 cout<<"\nEnter value of A : ";
 cin>>A;
 cout<<"\nEnter value of B : ";
 cin>>B;
 while(choice!=4)
 {
  cout<<"\nEnter choice :\n=>1 for swap by call by value\n=>2 for swap by call by reference\n=>3 for swap by pointer\n=>4 to terminate\n";
   cin>>choice;
  if(choice==1)
  {
   tmp=A;
   A=B;
   B=tmp;
  }
  else if(choice==2)
   swap1(A,B);
  else if(choice==3)
   swap2(&A,&B);
  else
   break;
  cout<<"\nNow value of A : "<<A<<endl;
  cout<<"\nNow value of B : "<<B<<endl;
 }
 return 0;
}

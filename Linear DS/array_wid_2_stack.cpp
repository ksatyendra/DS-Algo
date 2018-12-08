#include<iostream>
using namespace std;
int a[10],n=10,top1,top2;
bool isempty1()
{
 return top1==-1;
}
bool isempty2()
{
 return top2==n;
}
bool isfull()
{
 return top1==top2-1;
}
bool underflow()
{
 return top1==-1||top2==n;
}
bool overflow()
{
 return top1>=top2;
}
void show1()
{
  for(int i=0;i<=top1;i++)
   cout<<a[i]<<" ";
  cout<<endl;
}
void show2()
{
  for(int i=n-1;i>=top2;i--)
   cout<<a[i]<<" ";
  cout<<endl;
}
void push1(int k)
{
 a[++top1]=k;
}
int pop1()
{
 return a[top1--];
}
void push2(int k)
{
 a[--top2]=k;
}
int pop2()
{
 return a[top2++];
}
int main()
{
  int i,k=1;
  top1=-1,top2=n;
  while(k)
  {
   cout<<"Enter choice :\n1 to push in stack 1\n2 to pop stack 1\n3 to show stack 1";
   cout<<"\n4 to push in stack 2\n5 to pop stack 2\n6 to show stack 2\n7 to check underflow";
   cout<<"\n8 to check overflow\n9 to check full\n9 to check stack 1 empty\n10 to check ";
   cout<<"stack 2 empty\n0 to terminate : ";
   cin>>k;
   switch(k)
   {
     case 1 : if(!isfull())
                {   cout<<"\nenter no. : ";   cin>>i;   push1(i);   }
              else  cout<<"\nfull!!!";break;
     case 2 : if(!isempty1())
                {   cout<<"\npopped data : ";  cout<<pop1();   }
              else  cout<<"\nempty!!!";break;
     case 3 : cout<<"\nStack 1 :\n"; show1(); break;
     case 4 : if(!isfull())
                {   cout<<"\nenter no. : ";   cin>>i;   push2(i);   }
              else  cout<<"\nfull!!!";break;
     case 5 : if(!isempty2())
                {   cout<<"\npopped data : ";  cout<<pop2();   }
              else  cout<<"\nempty!!!";break;
     case 6 : cout<<"\nStack 2 :\n"; show2(); break;
     case 7 : if(underflow())
                 cout<<"\nUnderflow is there.\n";
              else
                 cout<<"\nUnderflow is not there.\n";
               break;
     case 8 : if(overflow())
                 cout<<"\nOverflow is there.\n";
              else
                 cout<<"\nOverflow is not there.\n";
   }

  }
}

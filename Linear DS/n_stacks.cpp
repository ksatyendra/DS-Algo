#include<iostream>
using namespace std;
int max_size=10;
struct kStacks
{
 int *data;
 int *top;
}s;
bool isEmpty(int sn)
{
 return s.top[sn]==sn*max_size-1;
}
bool isFull(int sn)
{
 return s.top[sn]==(sn+1)*max_size-1;
}
void display(int sn)
{
 for(int i=sn*max_size;i<=s.top[sn];i++)
  cout<<s.data[i]<<" ";
 cout<<endl;
}
void push(int k,int sn)
{
 s.data[++s.top[sn]]=k;
}
int pop(int sn)
{
 return s.data[s.top[sn]--];
}
int main()
{
 int k,ch,sn,i,j;
 cout<<"\nEnter no. of stacks : ";
 cin>>k;
 s.data=new int[k*max_size];
 s.top=new int[k];
 for(i=-1,j=0;i<k*max_size;i+=max_size,j++)
  s.top[j]=i;
 while(ch)
 {
  cout<<"Enter choice :\n1 to push\n2 to pop\n3 to display : ";
  cin>>ch;
  cout<<"\nEnter stack number : ";
  cin>>sn; sn--;
  switch(ch)
  {
   case 1 : if(!isFull(sn))
            {
             cout<<"\nEnter Data : ";
             cin>>i;
             push(i,sn);
            }
            else
             cout<<"\n"<<sn+1<<"th stack is Full!!!\n";
            break;
   case 2 : if(!isEmpty(sn))
             cout<<"\nPopped data from "<<sn+1<<"th stack is : "<<pop(sn)<<endl;
            else
             cout<<"\n"<<sn+1<<"th stack ibs Empty!!!\n";
            break;
   case 3 : cout<<"\nStack "<<sn+1<<" is :\n";
            display(sn);
            break;
   }

  }
}

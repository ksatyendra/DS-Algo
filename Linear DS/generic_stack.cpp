#include<iostream>
#include<string.h>
using namespace std;
int n=10;
template<class sk>
class Stack
{
 private:
    int top;
    sk *a=new sk[n];
 public:
    Stack()
    {
     top=-1;
    }
    bool isempty()
    {
        return top==-1;
    }
    bool isfull()
    {
        return top==n-1;
    }
    void push()
    {
        if(!isfull())
        {
            cout<<"\nEnter data : ";
            cin>>a[++top];
        }
        else cout<<"\nOOOPS... Stack is full.";
    }
    sk pop()
    {
        return a[top--];
    }
    sk show()
    {
        cout<<"\nStack is : ";
        for(int i=0;i<=top;i++)
         cout<<a[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    int type,k;
    Stack<int>A;
    Stack<char>B;
    Stack<float>C;
    cout<<"\nEnter the type of Stack which you want to make\n1->int\n2->char\n3->float : ";
    cin>>type;
    if(type>3||type<1)
    {
        cout<<"\nWRONG CHOICE\n";
        return 0;
    }
    while(k)
    {
     cout<<"\nEnter 1 to push, 2 to pop, 3 to show  stack & 0 to terminate : ";
     cin>>k;
     if(!k)
      break;
     else if(k==1)
     {
      if(type==1)A.push();
      else if(type==2)B.push();
      else C.push();
     }
     else if(k==2)
     {
      cout<<"\nPopped data : ";
      if(type==1&&!B.isempty())
       cout<<A.pop();
      else if(type==2&&!B.isempty())
       cout<<B.pop();
      else if(type==3&&!C.isempty())
       cout<<C.pop();
      else
       cout<<"\nOOOPS... Stack is Empty.";
      cout<<endl;
     }
     else if(k==3)
     {
      if(type==1)A.show();
      else if(type==2)B.show();
      else C.show();
     }
  }
}
